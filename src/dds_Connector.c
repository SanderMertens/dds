/* dds_Connector.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

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

    if(is == DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE) {
        result = Delete;
    } else if(vs == DDS_NEW_VIEW_STATE) {
        result = Create;
    } else if(is == DDS_ALIVE_INSTANCE_STATE) {
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

    cx_setOwner(this);

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

        if (infoSeq._buffer[i].valid_data) {
            p = cx_resolve(this->scope, sampleSeq._buffer[i].parent);
            if (!p) {
                cx_error("parent '%s' not found");
                continue;
            }
            o = cx_resolve(p, sampleSeq._buffer[i].name);

            if (sampleSeq._buffer[i].type) {
                t = cx_resolve(NULL, sampleSeq._buffer[i].type);
                if (!t) {
                    cx_error("unresolved type '%s' (%s)", sampleSeq._buffer[i].type, cx_lasterr());
                    continue;
                }
            } else if (o) {
                t = cx_typeof(o);
                cx_claim(t);
            }

            if (!o) {
                o = cx_declareChild(
                    p,
                    sampleSeq._buffer[i].name,
                    t);
            } else {
                if (!cx_instanceof(t, o)) {
                    cx_id id;
                    cx_error("object '%s' already exists in the database with type '%s'",
                        cx_nameof(o),
                        cx_fullname(cx_typeof(o), id));

                    cx_release(o);
                    continue;
                }

                cx_release(o);
            }

            cx_release(t);

            switch (DdsToCrudKind(infoSeq._buffer[i].view_state, infoSeq._buffer[i].instance_state)) {
            case Delete:
                cx_delete(o);
                break;
            default:
                break;
            }
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

    cx_setOwner(this);

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

        if (infoSeq._buffer[i].valid_data) {
            o = cx_resolve(this->scope, sampleSeq._buffer[i].id);

            if (!o) {
                cx_error("object %s hasn't been declared yet", sampleSeq._buffer[i].id);
                continue;
            }

            switch (DdsToCrudKind(infoSeq._buffer[i].view_state, infoSeq._buffer[i].instance_state)) {
            case Create:
            case Update:
                if (cx_fromStr(&o, sampleSeq._buffer[i].value)) {
                    cx_error("deserialize failed ('%s')", cx_lasterr());
                }
                if (!cx_checkState(o, CX_DEFINED)) {
                    cx_define(o);
                } else if (cx_ownerof(o) == this) {
                    cx_update(o);
                }
                break;
            case Delete:
                cx_delete(o);
                break;
            }

            cx_release(o);
        }
    }

    status = ddsx_CortoUpdateDataReader_return_loan(reader, &sampleSeq, &infoSeq);
    checkStatus(status, "ddsx_CortoUpdateDataReader_return_loan");
}

/* Serialize an update to an existing object */
void corto_onInvokeListener(dds_Connector this, DDS_DataReader reader) {
    DDS_sequence_ddsx_CortoInvoke sampleSeq = { 0, 0, DDS_OBJECT_NIL, FALSE };
    DDS_SampleInfoSeq infoSeq = { 0, 0, DDS_OBJECT_NIL, FALSE };
    DDS_ReturnCode_t status;
    unsigned int i;

    cx_setOwner(this);

    /* Take all messages. */
    status = ddsx_CortoInvokeDataReader_take(
        reader,
        &sampleSeq,
        &infoSeq,
        DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE,
        DDS_ANY_VIEW_STATE,
        DDS_ANY_INSTANCE_STATE);
    checkStatus(status, "ddsx_CortoInvokeDataReader_take");

    for (i = 0; i < sampleSeq._length; i++) {
        cx_object instance, function;
        cx_octetseq args;

        if (infoSeq._buffer[i].valid_data) {
            instance = cx_resolve(this->scope, sampleSeq._buffer[i].instance);
            if (!instance) {
                cx_error("instance %s not found", sampleSeq._buffer[i].instance);
                continue;
            }

            if (cx_ownerof(instance) != this) {
                function = cx_resolve(this->scope, sampleSeq._buffer[i].method);
                if (!function) {
                    cx_error("method %s not found", sampleSeq._buffer[i].method);
                    continue;
                }

                args.buffer = sampleSeq._buffer[i].args._buffer;
                args.length = sampleSeq._buffer[i].args._length;
                *(cx_object*)(args.buffer) = instance;
                cx_replicator_invoke(this, instance, function, args);
                cx_release(function);
            }

            cx_release(instance);
        }
    }

    status = ddsx_CortoInvokeDataReader_return_loan(reader, &sampleSeq, &infoSeq);
    checkStatus(status, "ddsx_CortoInvokeDataReader_return_loan");
}

static cx_int16 dds_Connector_setup(dds_Connector this) {
    /* -- Create DDS entities */
    DDS_DomainParticipant dp;
    DDS_Subscriber sub;
    DDS_Publisher pub;
    DDS_Topic cortoUpdateTopic;
    DDS_Topic cortoDeclareTopic;
    DDS_Topic cortoInvokeTopic;
    ddsx_CortoDeclareTypeSupport cortoDeclareTs;
    ddsx_CortoUpdateTypeSupport cortoUpdateTs;
    ddsx_CortoInvokeTypeSupport cortoInvokeTs;
    ddsx_CortoUpdateDataReader cortoUpdateReader;
    ddsx_CortoUpdateDataWriter cortoUpdateWriter;
    ddsx_CortoDeclareDataReader cortoDeclareReader;
    ddsx_CortoDeclareDataWriter cortoDeclareWriter;
    ddsx_CortoInvokeDataReader cortoInvokeReader;
    ddsx_CortoInvokeDataWriter cortoInvokeWriter;
    struct DDS_DataReaderListener cortoUpdateListener;
    struct DDS_DataReaderListener cortoDeclareListener;
    struct DDS_DataReaderListener cortoInvokeListener;    
    char *cortoUpdateTypeName;
    char *cortoDeclareTypeName;
    char *cortoInvokeTypeName;
    DDS_TopicQos topicQos;
    DDS_TopicQos invokeTopicQos;
    DDS_SubscriberQos subQos;
    DDS_PublisherQos pubQos;
    DDS_DataWriterQos writerQos;
    DDS_ReturnCode_t status;

    memset(&topicQos, 0, sizeof(topicQos));
    memset(&pubQos, 0, sizeof(subQos));
    memset(&subQos, 0, sizeof(subQos));
    memset(&writerQos, 0, sizeof(writerQos));

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

    cortoInvokeTs = ddsx_CortoInvokeTypeSupport__alloc();
    checkHandle(cortoInvokeTs, "ddsx_CortoInvokeTypeSupport__alloc");
    cortoInvokeTypeName = ddsx_CortoInvokeTypeSupport_get_type_name(cortoInvokeTs);
    status = ddsx_CortoInvokeTypeSupport_register_type(
        cortoInvokeTs,
        dp,
        cortoInvokeTypeName);
    checkStatus(status, "ddsx_CortoInvokeTypeSupport_register_type");

    status = DDS_DomainParticipant_get_default_topic_qos(dp, &topicQos);
    checkStatus(status, "DDS_DomainParticipant_get_default_topic_qos");
    topicQos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    topicQos.durability.kind = DDS_TRANSIENT_LOCAL_DURABILITY_QOS;
    topicQos.history.depth = 1;
    topicQos.history.kind = DDS_KEEP_LAST_HISTORY_QOS;

    status = DDS_DomainParticipant_get_default_topic_qos(dp, &invokeTopicQos);
    checkStatus(status, "DDS_DomainParticipant_get_default_topic_qos");
    invokeTopicQos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    invokeTopicQos.durability.kind = DDS_VOLATILE_DURABILITY_QOS;
    invokeTopicQos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;

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

    cortoInvokeTopic = DDS_DomainParticipant_create_topic(
        dp,
        "CortoInvoke",
        cortoInvokeTypeName,
        &invokeTopicQos,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoInvokeTopic, "DDS_DomainParticipant_create_topic (CortoInvoke)");

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

    cortoInvokeReader = DDS_Subscriber_create_datareader(
        sub,
        cortoInvokeTopic,
        DDS_DATAREADER_QOS_USE_TOPIC_QOS,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoInvokeReader, "DDS_Subscriber_create_datareader (CortoInvoke)");

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

    status = DDS_Publisher_get_default_datawriter_qos (pub, &writerQos);
    checkStatus(status, "DDS_Publisher_get_default_datawriter_qos");
    status = DDS_Publisher_copy_from_topic_qos(pub, &writerQos, &topicQos);
    checkStatus(status, "DDS_Publisher_copy_from_topic_qos");
    writerQos.writer_data_lifecycle.autodispose_unregistered_instances = FALSE;

    cortoDeclareWriter = DDS_Publisher_create_datawriter(
        pub,
        cortoDeclareTopic,
        &writerQos,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoDeclareReader, "DDS_Publisher_create_datawriter (CortoDeclare)");

    cortoUpdateWriter = DDS_Publisher_create_datawriter(
        pub,
        cortoUpdateTopic,
        &writerQos,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoUpdateReader, "DDS_Publisher_create_datawriter (CortoUpdate)");

    cortoInvokeWriter = DDS_Publisher_create_datawriter(
        pub,
        cortoInvokeTopic,
        &writerQos,
        NULL,
        DDS_STATUS_MASK_NONE);
    checkHandle(cortoInvokeReader, "DDS_Publisher_create_datawriter (CortoInvoke)");

    /* -- Setup DDS listeners */
    memset(&cortoDeclareListener, 0, sizeof(cortoDeclareListener));
    cortoDeclareListener.on_data_available = (void (*)(void *, DDS_DataReader)) corto_onDeclareListener;
    cortoDeclareListener.listener_data = this;

    memset(&cortoUpdateListener, 0, sizeof(cortoUpdateListener));
    cortoUpdateListener.on_data_available = (void (*)(void *, DDS_DataReader)) corto_onUpdateListener;
    cortoUpdateListener.listener_data = this;

    memset(&cortoInvokeListener, 0, sizeof(cortoInvokeListener));
    cortoInvokeListener.on_data_available = (void (*)(void *, DDS_DataReader)) corto_onInvokeListener;
    cortoInvokeListener.listener_data = this;

    status = DDS_DataReader_set_listener(cortoDeclareReader, &cortoDeclareListener, DDS_DATA_AVAILABLE_STATUS);
    checkStatus(status, "DDS_DataReader_set_listener (CortoDeclare)");

    status = DDS_DataReader_set_listener(cortoUpdateReader, &cortoUpdateListener, DDS_DATA_AVAILABLE_STATUS);
    checkStatus(status, "DDS_DataReader_set_listener (CortoUpdate)");

    status = DDS_DataReader_set_listener(cortoInvokeReader, &cortoInvokeListener, DDS_DATA_AVAILABLE_STATUS);
    checkStatus(status, "DDS_DataReader_set_listener (CortoInvoke)");

    /* -- Assign entities to DdsConnector object */
    this->dp = (cx_word)dp;
    this->sub = (cx_word)sub;
    this->pub = (cx_word)pub;
    this->topic_cortoDeclare = (cx_word)cortoDeclareTopic;
    this->topic_cortoUpdate = (cx_word)cortoUpdateTopic;
    this->topic_cortoInvoke = (cx_word)cortoInvokeTopic;
    this->dr_cortoDeclare = (cx_word)cortoDeclareReader;
    this->dw_cortoDeclare = (cx_word)cortoDeclareWriter;
    this->dr_cortoUpdate = (cx_word)cortoUpdateReader;
    this->dw_cortoUpdate = (cx_word)cortoUpdateWriter;
    this->dr_cortoInvoke = (cx_word)cortoInvokeReader;
    this->dw_cortoInvoke = (cx_word)cortoInvokeWriter;

    if (!this->scope) {
        cx_setref(&this->scope, root_o);
    }

    return 0;
}

/* Teardown DDS connection */
void dds_Connector_teardown(dds_Connector this) {
	DDS_ReturnCode_t status;
    status = DDS_DomainParticipant_delete_contained_entities((DDS_DomainParticipant)this->dp);
    checkStatus(status, "DDS_DomainParticipant_delete_contained_entities");
}

/* $end */

/* ::dds::Connector::construct() */
cx_int16 _dds_Connector_construct(dds_Connector this) {
/* $begin(::dds::Connector::construct) */

	/* Setup connection to DDS */
	if (dds_Connector_setup(this)) {
		goto error;
	}

	/* Setup delegates for listening to corto updates */
    cx_notifyActionSet(&cx_replicator(this)->onDeclare, this, cx_function(dds_Connector_onDeclare_o));
    cx_notifyActionSet(&cx_replicator(this)->onUpdate, this, cx_function(dds_Connector_onUpdate_o));
    cx_notifyActionSet(&cx_replicator(this)->onDelete, this, cx_function(dds_Connector_onDelete_o));
    cx_invokeActionSet(&cx_replicator(this)->onInvoke, this, cx_function(dds_Connector_onInvoke_o));

    return cx_replicator_construct(this);
error:
	return -1;
/* $end */
}

/* ::dds::Connector::destruct() */
cx_void _dds_Connector_destruct(dds_Connector this) {
/* $begin(::dds::Connector::destruct) */

    dds_Connector_teardown(this);

/* $end */
}

/* ::dds::Connector::onDeclare(object observable) */
cx_void _dds_Connector_onDeclare(dds_Connector this, cx_object observable) {
/* $begin(::dds::Connector::onDeclare) */

    ddsx_CortoDeclare sample;

    cx_id parentId; cx_relname(this->scope, cx_parentof(observable), parentId);
    cx_id typeId; cx_fullname(cx_typeof(observable), typeId);

    sample.parent = parentId;
    sample.name = cx_nameof(observable);
    sample.type = typeId;

    ddsx_CortoDeclareDataWriter_write(
        (ddsx_CortoDeclareDataWriter)this->dw_cortoDeclare, &sample, DDS_HANDLE_NIL);

/* $end */
}

/* ::dds::Connector::onDelete(object observable) */
cx_void _dds_Connector_onDelete(dds_Connector this, cx_object observable) {
/* $begin(::dds::Connector::onDelete) */

    ddsx_CortoDeclare declare;
    ddsx_CortoUpdate update;

    /* Dispose update instance */
    cx_id id; cx_relname(this->scope, observable, id);
    update.id = id;

    ddsx_CortoUpdateDataWriter_dispose(
        (ddsx_CortoUpdateDataWriter)this->dw_cortoUpdate, &update, DDS_HANDLE_NIL);

    /* Dispose declare instance */
    cx_id parentId; cx_relname(this->scope, cx_parentof(observable), parentId);
    cx_id typeId; cx_fullname(cx_typeof(observable), typeId);
    declare.parent = parentId;
    declare.name = cx_nameof(observable);

    ddsx_CortoDeclareDataWriter_dispose(
        (ddsx_CortoDeclareDataWriter)this->dw_cortoDeclare, &declare, DDS_HANDLE_NIL);

/* $end */
}

/* ::dds::Connector::onInvoke(object instance,function f,octetseq args) */
cx_void _dds_Connector_onInvoke(dds_Connector this, cx_object instance, cx_function f, cx_octetseq args) {
/* $begin(::dds::Connector::onInvoke) */

    ddsx_CortoInvoke sample;
    cx_id id; cx_relname(this->scope, instance, id);
    cx_id methodId; cx_relname(this->scope, f, methodId);
    sample.instance = id;
    sample.method = methodId;
    sample.args._buffer = args.buffer;
    sample.args._length = args.length;
    sample.args._release = FALSE;
    sample.args._maximum = args.length;

    ddsx_CortoInvokeDataWriter_write(
        (ddsx_CortoInvokeDataWriter)this->dw_cortoInvoke, &sample, DDS_HANDLE_NIL);

/* $end */
}

/* ::dds::Connector::onUpdate(object observable) */
cx_void _dds_Connector_onUpdate(dds_Connector this, cx_object observable) {
/* $begin(::dds::Connector::onUpdate) */

    ddsx_CortoUpdate sample;

    cx_id id; cx_relname(this->scope, observable, id);
    sample.id = id;

    cx_string_ser_t serData;
    struct cx_serializer_s s;
    serData.buffer = NULL;
    serData.length = 0;
    serData.maxlength = 0;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;
    s = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
    cx_serialize(&s, observable, &serData);
    sample.value = serData.buffer;

    ddsx_CortoUpdateDataWriter_write(
        (ddsx_CortoUpdateDataWriter)this->dw_cortoUpdate, &sample, DDS_HANDLE_NIL);

    cx_dealloc(sample.value);

/* $end */
}
