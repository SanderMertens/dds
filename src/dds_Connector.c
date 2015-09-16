/* dds_Connector.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define dds_LIB
#include "dds.h"

/* $header() */
#include "dds_dcps.h"
#include "CheckStatus.h"
#include "ddsx.h"

typedef enum CrudKind {
    Create,
    Update,
    Delete
} CrudKind;

CrudKind DdsToCrudKind(DDS_ViewStateKind vs, DDS_InstanceStateKind is) {
    CrudKind result;

    if(is == DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE || 
       is == DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE) {
        result = Delete;
    }else if(vs == DDS_NEW_VIEW_STATE) {
        result = Create;
    }else if(is == DDS_ALIVE_INSTANCE_STATE) {
        result = Update;
    }

    return result;
}

/* Regular DDS objects don't need a forward declaration, but in order to properly sync
 * two corto stores, declare semantics are required. */
void corto_onDeclareListener(dds_Connector this, DDS_DataReader reader) {
    DDS_sequence_ddsx_CortoDeclare sampleSeq = { 0, 0, DDS_OBJECT_NIL, FALSE };
    DDS_SampleInfoSeq infoSeq = { 0, 0, DDS_OBJECT_NIL, FALSE };
    DDS_ReturnCode_t status;
    unsigned int i;

    cx_setSource(this);

    /* Take all messages. */
    status = ddsx_CortoDeclareDataReader_take(
        reader,
        &sampleSeq,
        &infoSeq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);
    checkStatus(status, "ddsx_CortoDeclareDataReader_take");

    for (i = 0; i < sampleSeq._length; i++) {
        cx_object p = NULL;
        cx_object o = NULL;
        cx_type t = NULL;

        p = cx_resolve(this->scope, sampleSeq._buffer[i].parent);
        if (!p) {
            cx_error("parent '%s' not found");
            continue;
        }
        o = cx_resolve(p, sampleSeq._buffer[i].name);

        if (sampleSeq._buffer[i].type) {
            t = cx_resolve(NULL, sampleSeq._buffer[i].type);
            if (!t) {
                cx_error("unresolved type '%s'", sampleSeq._buffer[i].type);
                continue;
            }
        } else if (o) {
            t = cx_typeof(o);

            /* Increase refcount to match resolve (cx_typeof doesn't increase count) */
            cx_claim(t);
        }

        /* If y is not found, declare it */
        if (!o) {
            o = cx_declareChild(
                p,
                sampleSeq._buffer[i].name,
                t);
        } else {
            /* If CACHE_NAME is found, validate it is of the correct type */
            if (!cx_instanceof(t, o)) {
                cx_id id;
                cx_error("object '%s' already exists in the database with type '%s'",
                    cx_nameof(o),
                    cx_fullname(cx_typeof(o), id));

                /* Release refcount obtained by cx_resolve */
                cx_release(o);
                continue;
            }

            /* Release refcount obtained by cx_resolve */
            cx_release(o);
        }

        /* Release refcount obtained by cx_resolve */
        cx_release(t);

        /* Synchronize device data with cortex */
        switch (DdsToCrudKind(infoSeq._buffer[i].view_state, infoSeq._buffer[i].instance_state)) {
        case Delete:
            cx_delete(o);
            break;
        default:
            break;
        }
    }

    status = ddsx_CortoDeclareDataReader_return_loan(reader, &sampleSeq, &infoSeq);
    checkStatus(status, "ddsx_CortoDeclareDataReader_return_loan");
}

/* Serialize an update to an existing object */
void corto_onUpdateListener(dds_Connector this, DDS_DataReader reader) {
    DDS_sequence_ddsx_CortoUpdate sampleSeq = { 0, 0, DDS_OBJECT_NIL, FALSE };
    DDS_SampleInfoSeq infoSeq = { 0, 0, DDS_OBJECT_NIL, FALSE };
    DDS_ReturnCode_t status;
    unsigned int i;

    cx_setSource(this);

    /* Take all messages. */
    status = ddsx_CortoUpdateDataReader_take(
        reader,
        &sampleSeq,
        &infoSeq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);
    checkStatus(status, "ddsx_CortoUpdateDataReader_take");

    for (i = 0; i < sampleSeq._length; i++) {
        cx_object o;

        /* Find CACHE_NAME in cortex cache */
        o = cx_resolve(this->scope, sampleSeq._buffer[i].id);

        /* If y is not found, declare it */
        if (!o) {
            cx_error("object %s hasn't been declared yet", sampleSeq._buffer[i].id);
            continue;
        }

        /* Synchronize device data with cortex */
        switch (DdsToCrudKind(infoSeq._buffer[i].view_state, infoSeq._buffer[i].instance_state)) {
        case Create:
        case Update:
            cx_fromStr(&o, sampleSeq._buffer[i].value);
            if (!cx_checkState(o, CX_DEFINED)) {
                cx_define(o);
            } else {
                cx_update(o);
            }
            break;
        case Delete:
            cx_delete(o);
            break;
        }
    }

    status = ddsx_CortoUpdateDataReader_return_loan(reader, &sampleSeq, &infoSeq);
    checkStatus(status, "ddsx_CortoUpdateDataReader_return_loan");
}
/* $end */

/* ::dds::Connector::construct() */
cx_int16 _dds_Connector_construct(dds_Connector this) {
/* $begin(::dds::Connector::construct) */

    /* -- Create DDS entities */
    DDS_DomainParticipant dp;
    DDS_Subscriber sub;
    DDS_Publisher pub;
    DDS_Topic cortoUpdateTopic;
    DDS_Topic cortoDeclareTopic;
    ddsx_CortoDeclareTypeSupport cortoDeclareTs;
    ddsx_CortoUpdateTypeSupport cortoUpdateTs;
    ddsx_CortoUpdateDataReader cortoUpdateReader;
    ddsx_CortoUpdateDataWriter cortoUpdateWriter;
    ddsx_CortoDeclareDataReader cortoDeclareReader;
    ddsx_CortoDeclareDataWriter cortoDeclareWriter;
    struct DDS_DataReaderListener cortoUpdateListener;
    struct DDS_DataReaderListener cortoDeclareListener;
    char *cortoUpdateTypeName;
    char *cortoDeclareTypeName;
    DDS_TopicQos topicQos;
    DDS_SubscriberQos subQos;
    DDS_PublisherQos pubQos;
    DDS_ReturnCode_t status;

    memset(&topicQos, 0, sizeof(topicQos));
    memset(&pubQos, 0, sizeof(subQos));
    memset(&subQos, 0, sizeof(subQos));

    dp = DDS_DomainParticipantFactory_create_participant (
        DDS_TheParticipantFactory,
        this->domainId,
        DDS_PARTICIPANT_QOS_DEFAULT,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(dp, "DDS_DomainParticipantFactory_create_participant");

    cortoDeclareTs = ddsx_CortoDeclareTypeSupport__alloc();
    checkHandle(cortoDeclareTs, "ddsx_CortoDeclareTypeSupport__alloc");
    cortoDeclareTypeName = ddsx_CortoDeclareTypeSupport_get_type_name(cortoDeclareTs);
    status = ddsx_CortoUpdateTypeSupport_register_type(
        cortoDeclareTs,
        dp,
        cortoDeclareTypeName);
    checkStatus(status, "ddsx_CortoUpdateTypeSupport_register_type");

    cortoUpdateTs = ddsx_CortoUpdateTypeSupport__alloc();
    checkHandle(cortoUpdateTs, "ddsx_CortoUpdateTypeSupport__alloc");
    cortoUpdateTypeName = ddsx_CortoUpdateTypeSupport_get_type_name(cortoUpdateTs);
    status = ddsx_CortoUpdateTypeSupport_register_type(
        cortoUpdateTs,
        dp,
        cortoUpdateTypeName);
    checkStatus(status, "ddsx_CortoUpdateTypeSupport_register_type");

    status = DDS_DomainParticipant_get_default_topic_qos(dp, &topicQos);
    checkStatus(status, "DDS_DomainParticipant_get_default_topic_qos");
    topicQos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    topicQos.durability.kind = DDS_TRANSIENT_LOCAL_DURABILITY_QOS;
    topicQos.history.depth = 1;
    topicQos.history.kind = DDS_KEEP_LAST_HISTORY_QOS;

    cortoDeclareTopic = DDS_DomainParticipant_create_topic(
        dp,
        "CortoDeclare",
        cortoDeclareTypeName,
        &topicQos,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoDeclareTopic, "DDS_DomainParticipant_create_topic (CortoDeclare)");

    cortoUpdateTopic = DDS_DomainParticipant_create_topic(
        dp,
        "CortoUpdate",
        cortoUpdateTypeName,
        &topicQos,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoUpdateTopic, "DDS_DomainParticipant_create_topic (CortoUpdate)");

    status = DDS_DomainParticipant_get_default_subscriber_qos (dp, &subQos);
    checkStatus(status, "DDS_DomainParticipant_get_default_subscriber_qos");
    if (this->partition) {
        subQos.partition.name._length = 1;
        subQos.partition.name._maximum = 1;
        subQos.partition.name._buffer = DDS_StringSeq_allocbuf (1);
        checkHandle(subQos.partition.name._buffer, "DDS_StringSeq_allocbuf");
        subQos.partition.name._buffer[0] = DDS_string_dup (this->partition);
        checkHandle(subQos.partition.name._buffer[0], "DDS_string_dup");
    }

    sub = DDS_DomainParticipant_create_subscriber(dp, &subQos, NULL, DDS_STATUS_MASK_NONE);
    checkHandle(sub, "DDS_DomainParticipant_create_subscriber");

    cortoDeclareReader = DDS_Subscriber_create_datareader(
        sub,
        cortoDeclareTopic,
        DDS_DATAREADER_QOS_USE_TOPIC_QOS,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoDeclareReader, "DDS_Subscriber_create_datareader (CortoDeclare)");

    cortoUpdateReader = DDS_Subscriber_create_datareader(
        sub,
        cortoUpdateTopic,
        DDS_DATAREADER_QOS_USE_TOPIC_QOS,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoUpdateReader, "DDS_Subscriber_create_datareader (CortoUpdate)");

    status = DDS_DomainParticipant_get_default_publisher_qos (dp, &pubQos);
    checkStatus(status, "DDS_DomainParticipant_get_default_publisher_qos");
    if (this->partition) {
        pubQos.partition.name._length = 1;
        pubQos.partition.name._maximum = 1;
        pubQos.partition.name._buffer = DDS_StringSeq_allocbuf (1);
        checkHandle(pubQos.partition.name._buffer, "DDS_StringSeq_allocbuf");
        pubQos.partition.name._buffer[0] = DDS_string_dup (this->partition);
        checkHandle(pubQos.partition.name._buffer[0], "DDS_string_dup");
    }

    pub = DDS_DomainParticipant_create_publisher(dp, &pubQos, NULL, DDS_STATUS_MASK_NONE);
    checkHandle(pub, "DDS_DomainParticipant_create_publisher");

    cortoDeclareWriter = DDS_Publisher_create_datawriter(
        pub,
        cortoDeclareTopic,
        DDS_DATAWRITER_QOS_USE_TOPIC_QOS,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoDeclareReader, "DDS_Publisher_create_datawriter (CortoDeclare)");

    cortoUpdateWriter = DDS_Publisher_create_datawriter(
        pub,
        cortoUpdateTopic,
        DDS_DATAWRITER_QOS_USE_TOPIC_QOS,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoUpdateReader, "DDS_Publisher_create_datawriter (CortoUpdate)");

    /* -- Setup DDS listeners */
    memset(&cortoDeclareListener, 0, sizeof(cortoDeclareListener));
    cortoDeclareListener.on_data_available = (void (*)(void *, DDS_DataReader)) corto_onDeclareListener;
    cortoDeclareListener.listener_data = this;

    memset(&cortoUpdateListener, 0, sizeof(cortoUpdateListener));
    cortoUpdateListener.on_data_available = (void (*)(void *, DDS_DataReader)) corto_onUpdateListener;
    cortoUpdateListener.listener_data = this;

    status = DDS_DataReader_set_listener(cortoDeclareReader, &cortoDeclareListener, DDS_DATA_AVAILABLE_STATUS);
    checkStatus(status, "DDS_DataReader_set_listener (CortoDeclare)");

    status = DDS_DataReader_set_listener(cortoUpdateReader, &cortoUpdateListener, DDS_DATA_AVAILABLE_STATUS);
    checkStatus(status, "DDS_DataReader_set_listener (CortoUpdate)");

    /* -- Assign entities to DdsConnector object */
    this->dp = (cx_word)dp;
    this->sub = (cx_word)sub;
    this->pub = (cx_word)pub;
    this->topic_cortoDeclare = (cx_word)cortoDeclareTopic;
    this->topic_cortoUpdate = (cx_word)cortoUpdateTopic;
    this->dr_cortoDeclare = (cx_word)cortoDeclareReader;
    this->dw_cortoDeclare = (cx_word)cortoDeclareWriter;
    this->dr_cortoUpdate = (cx_word)cortoUpdateReader;
    this->dw_cortoUpdate = (cx_word)cortoUpdateWriter;

    if (!this->scope) {
        cx_setref(&this->scope, root_o);
    }

    dds_Connector_onUpdate_o->mask = CX_ON_DEFINE | CX_ON_UPDATE | CX_ON_TREE;
    cx_listen(this->scope, dds_Connector_onUpdate_o, this);

    dds_Connector_onDeclare_o->mask = CX_ON_DECLARE | CX_ON_TREE;
    cx_listen(this->scope, dds_Connector_onDeclare_o, this);

    return 0;
/* $end */
}

/* ::dds::Connector::destruct() */
cx_void _dds_Connector_destruct(dds_Connector this) {
/* $begin(::dds::Connector::destruct) */

    DDS_ReturnCode_t status;
    status = DDS_DomainParticipant_delete_contained_entities((DDS_DomainParticipant)this->dp);
    checkStatus(status, "DDS_DomainParticipant_delete_contained_entities");

/* $end */
}

/* ::dds::Connector::onDeclare() */
cx_void _dds_Connector_onDeclare(dds_Connector this, cx_object observable, cx_object source) {
/* $begin(::dds::Connector::onDeclare) */
    ddsx_CortoDeclare sample;

    if (this != observable) {
        cx_id parentId; cx_relname(this->scope, cx_parentof(observable), parentId);
        cx_id typeId; cx_fullname(cx_typeof(observable), typeId);
        sample.parent = parentId;
        sample.name = cx_nameof(observable);
        sample.type = typeId;

        ddsx_CortoDeclareDataWriter_write(
            (ddsx_CortoDeclareDataWriter)this->dw_cortoDeclare, &sample, DDS_HANDLE_NIL);
    }

/* $end */
}

/* ::dds::Connector::onUpdate() */
cx_void _dds_Connector_onUpdate(dds_Connector this, cx_object observable, cx_object source) {
/* $begin(::dds::Connector::onUpdate) */
	ddsx_CortoUpdate sample;

	if (this != observable) {
		cx_id id; cx_relname(this->scope, observable, id);
		sample.id = id;
		sample.value = cx_str(observable, 0);

		ddsx_CortoUpdateDataWriter_write(
            (ddsx_CortoUpdateDataWriter)this->dw_cortoUpdate, &sample, DDS_HANDLE_NIL);

        cx_dealloc(sample.value);
	}

/* $end */
}
