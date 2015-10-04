#if defined (__cplusplus)
extern "C" {
#endif

#include "ddsxSacDcps.h"
#include "ddsxSplDcps.h"

#include <dds_dcps.h>
#include <dds_dcps_private.h>

DDS_sequence_ddsx_CortoDeclare *DDS_sequence_ddsx_CortoDeclare__alloc (void)
{
    return (DDS_sequence_ddsx_CortoDeclare *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_ddsx_CortoDeclare));
}

ddsx_CortoDeclare *DDS_sequence_ddsx_CortoDeclare_allocbuf (DDS_unsigned_long len)
{
    DDS_boolean DDS_sequence_ddsx_CortoDeclare_freebuf (void *buffer);

    return (ddsx_CortoDeclare *)DDS_sequence_allocbuf (DDS_sequence_ddsx_CortoDeclare_freebuf, sizeof (ddsx_CortoDeclare), len);
}

DDS_boolean DDS_sequence_ddsx_CortoDeclare_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    ddsx_CortoDeclare *b = (ddsx_CortoDeclare *)buffer;
    DDS_unsigned_long i;
    void ddsx_CortoDeclare__free (void *object);

    for (i = 0; i < *count; i++) {
        ddsx_CortoDeclare__free (&b[i]);
    }
    return TRUE;
}

extern c_bool __ddsx_CortoDeclare__copyIn(c_base base, void *from, void *to);
extern void __ddsx_CortoDeclare__copyOut(void *from, void *to);


ddsx_CortoDeclareTypeSupport
ddsx_CortoDeclareTypeSupport__alloc (
    void
    )
{
    c_ulong i;
    os_size_t strlength =0;
    char * metaDescriptor;
    ddsx_CortoDeclareTypeSupport result;
    for (i = 0; i < ddsx_CortoDeclare_metaDescriptorArrLength; i++) {
        strlength +=strlen(ddsx_CortoDeclare_metaDescriptor[i]);
    }

    metaDescriptor = (char*)malloc(strlength+1);
    metaDescriptor[0] = '\0';
    for (i = 0; i < ddsx_CortoDeclare_metaDescriptorArrLength; i++) {
        strcat(metaDescriptor,ddsx_CortoDeclare_metaDescriptor[i]);
    }
	result = DDS__FooTypeSupport__alloc (
	    __ddsx_CortoDeclare__name(),
            __ddsx_CortoDeclare__keys(),
            metaDescriptor,
            NULL,
            (DDS_copyIn)__ddsx_CortoDeclare__copyIn,
            (DDS_copyOut)__ddsx_CortoDeclare__copyOut,
            (DDS_unsigned_long)(sizeof(ddsx_CortoDeclare)),
            (DDS_typeSupportAllocBuffer)DDS_sequence_ddsx_CortoDeclare_allocbuf
        );
    free(metaDescriptor);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareTypeSupport_register_type (
    ddsx_CortoDeclareTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooTypeSupport_register_type (
	    (DDS_TypeSupport)_this,
	    domain,
	    name
	);
    return result;
}

DDS_string
ddsx_CortoDeclareTypeSupport_get_type_name (
    ddsx_CortoDeclareTypeSupport _this
    )
{
    DDS_string result = (DDS_string)
        DDS__FooTypeSupport_get_type_name (
	    (DDS_TypeSupport)_this
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoDeclareDataWriter_register_instance (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoDeclareDataWriter_register_instance_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_unregister_instance (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance (
	    (const DDS_DataWriter)_this,
	    (DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_unregister_instance_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_write (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_write_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_dispose (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_dispose_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_writedispose (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_writedispose_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_get_key_value (
    ddsx_CortoDeclareDataWriter _this,
    ddsx_CortoDeclare *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_get_key_value (
	    (DDS_DataWriter)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoDeclareDataWriter_lookup_instance (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_lookup_instance (
        (DDS_DataWriter)_this,
        (DDS_sample)key_holder
    );
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_next_sample (
    ddsx_CortoDeclareDataReader _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_next_sample (
    ddsx_CortoDeclareDataReader _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_instance (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_instance (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_next_instance (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_next_instance (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_next_instance_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_next_instance_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_return_loan (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_return_loan (
            (DDS_DataReader)_this,
            (DDS_sequence)received_data,
            info_seq
    );
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_get_key_value (
    ddsx_CortoDeclareDataReader _this,
    ddsx_CortoDeclare *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_get_key_value (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoDeclareDataReader_lookup_instance (
    ddsx_CortoDeclareDataReader _this,
    const ddsx_CortoDeclare *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReader_lookup_instance (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_next_sample (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_next_sample (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_instance (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_instance (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_next_instance (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_next_instance (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_return_loan (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_return_loan (
            (DDS_DataReaderView)_this,
            (DDS_sequence)received_data,
            info_seq
    );

    if ( result == DDS_RETCODE_OK ) {
        DDS__free(received_data->_buffer);
        received_data->_length  = 0;
        received_data->_maximum = 0;
        received_data->_buffer  = NULL;

        DDS__free(info_seq->_buffer);
        info_seq->_length  = 0;
        info_seq->_maximum = 0;
        info_seq->_buffer  = NULL;
    }

    return result;
}


DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_next_instance_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_next_instance_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_get_key_value (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_get_key_value (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}


DDS_InstanceHandle_t
ddsx_CortoDeclareDataReaderView_lookup_instance (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReaderView_lookup_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

DDS_sequence_ddsx_CortoUpdate *DDS_sequence_ddsx_CortoUpdate__alloc (void)
{
    return (DDS_sequence_ddsx_CortoUpdate *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_ddsx_CortoUpdate));
}

ddsx_CortoUpdate *DDS_sequence_ddsx_CortoUpdate_allocbuf (DDS_unsigned_long len)
{
    DDS_boolean DDS_sequence_ddsx_CortoUpdate_freebuf (void *buffer);

    return (ddsx_CortoUpdate *)DDS_sequence_allocbuf (DDS_sequence_ddsx_CortoUpdate_freebuf, sizeof (ddsx_CortoUpdate), len);
}

DDS_boolean DDS_sequence_ddsx_CortoUpdate_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    ddsx_CortoUpdate *b = (ddsx_CortoUpdate *)buffer;
    DDS_unsigned_long i;
    void ddsx_CortoUpdate__free (void *object);

    for (i = 0; i < *count; i++) {
        ddsx_CortoUpdate__free (&b[i]);
    }
    return TRUE;
}

extern c_bool __ddsx_CortoUpdate__copyIn(c_base base, void *from, void *to);
extern void __ddsx_CortoUpdate__copyOut(void *from, void *to);


ddsx_CortoUpdateTypeSupport
ddsx_CortoUpdateTypeSupport__alloc (
    void
    )
{
    c_ulong i;
    os_size_t strlength =0;
    char * metaDescriptor;
    ddsx_CortoUpdateTypeSupport result;
    for (i = 0; i < ddsx_CortoUpdate_metaDescriptorArrLength; i++) {
        strlength +=strlen(ddsx_CortoUpdate_metaDescriptor[i]);
    }

    metaDescriptor = (char*)malloc(strlength+1);
    metaDescriptor[0] = '\0';
    for (i = 0; i < ddsx_CortoUpdate_metaDescriptorArrLength; i++) {
        strcat(metaDescriptor,ddsx_CortoUpdate_metaDescriptor[i]);
    }
	result = DDS__FooTypeSupport__alloc (
	    __ddsx_CortoUpdate__name(),
            __ddsx_CortoUpdate__keys(),
            metaDescriptor,
            NULL,
            (DDS_copyIn)__ddsx_CortoUpdate__copyIn,
            (DDS_copyOut)__ddsx_CortoUpdate__copyOut,
            (DDS_unsigned_long)(sizeof(ddsx_CortoUpdate)),
            (DDS_typeSupportAllocBuffer)DDS_sequence_ddsx_CortoUpdate_allocbuf
        );
    free(metaDescriptor);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateTypeSupport_register_type (
    ddsx_CortoUpdateTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooTypeSupport_register_type (
	    (DDS_TypeSupport)_this,
	    domain,
	    name
	);
    return result;
}

DDS_string
ddsx_CortoUpdateTypeSupport_get_type_name (
    ddsx_CortoUpdateTypeSupport _this
    )
{
    DDS_string result = (DDS_string)
        DDS__FooTypeSupport_get_type_name (
	    (DDS_TypeSupport)_this
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoUpdateDataWriter_register_instance (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoUpdateDataWriter_register_instance_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_unregister_instance (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance (
	    (const DDS_DataWriter)_this,
	    (DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_unregister_instance_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_write (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_write_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_dispose (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_dispose_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_writedispose (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_writedispose_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_get_key_value (
    ddsx_CortoUpdateDataWriter _this,
    ddsx_CortoUpdate *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_get_key_value (
	    (DDS_DataWriter)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoUpdateDataWriter_lookup_instance (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_lookup_instance (
        (DDS_DataWriter)_this,
        (DDS_sample)key_holder
    );
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_next_sample (
    ddsx_CortoUpdateDataReader _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_next_sample (
    ddsx_CortoUpdateDataReader _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_instance (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_instance (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_next_instance (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_next_instance (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_next_instance_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_next_instance_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_return_loan (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_return_loan (
            (DDS_DataReader)_this,
            (DDS_sequence)received_data,
            info_seq
    );
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_get_key_value (
    ddsx_CortoUpdateDataReader _this,
    ddsx_CortoUpdate *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_get_key_value (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoUpdateDataReader_lookup_instance (
    ddsx_CortoUpdateDataReader _this,
    const ddsx_CortoUpdate *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReader_lookup_instance (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_next_sample (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_next_sample (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_instance (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_instance (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_next_instance (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_next_instance (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_return_loan (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_return_loan (
            (DDS_DataReaderView)_this,
            (DDS_sequence)received_data,
            info_seq
    );

    if ( result == DDS_RETCODE_OK ) {
        DDS__free(received_data->_buffer);
        received_data->_length  = 0;
        received_data->_maximum = 0;
        received_data->_buffer  = NULL;

        DDS__free(info_seq->_buffer);
        info_seq->_length  = 0;
        info_seq->_maximum = 0;
        info_seq->_buffer  = NULL;
    }

    return result;
}


DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_next_instance_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_next_instance_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_get_key_value (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_get_key_value (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}


DDS_InstanceHandle_t
ddsx_CortoUpdateDataReaderView_lookup_instance (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReaderView_lookup_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

DDS_sequence_ddsx_CortoInvoke *DDS_sequence_ddsx_CortoInvoke__alloc (void)
{
    return (DDS_sequence_ddsx_CortoInvoke *)DDS__malloc (DDS_sequence_free, 0, sizeof(DDS_sequence_ddsx_CortoInvoke));
}

ddsx_CortoInvoke *DDS_sequence_ddsx_CortoInvoke_allocbuf (DDS_unsigned_long len)
{
    DDS_boolean DDS_sequence_ddsx_CortoInvoke_freebuf (void *buffer);

    return (ddsx_CortoInvoke *)DDS_sequence_allocbuf (DDS_sequence_ddsx_CortoInvoke_freebuf, sizeof (ddsx_CortoInvoke), len);
}

DDS_boolean DDS_sequence_ddsx_CortoInvoke_freebuf (void *buffer)
{
    DDS_unsigned_long *count = (DDS_unsigned_long *)DDS__header (buffer);
    ddsx_CortoInvoke *b = (ddsx_CortoInvoke *)buffer;
    DDS_unsigned_long i;
    void ddsx_CortoInvoke__free (void *object);

    for (i = 0; i < *count; i++) {
        ddsx_CortoInvoke__free (&b[i]);
    }
    return TRUE;
}

extern c_bool __ddsx_CortoInvoke__copyIn(c_base base, void *from, void *to);
extern void __ddsx_CortoInvoke__copyOut(void *from, void *to);


ddsx_CortoInvokeTypeSupport
ddsx_CortoInvokeTypeSupport__alloc (
    void
    )
{
    c_ulong i;
    os_size_t strlength =0;
    char * metaDescriptor;
    ddsx_CortoInvokeTypeSupport result;
    for (i = 0; i < ddsx_CortoInvoke_metaDescriptorArrLength; i++) {
        strlength +=strlen(ddsx_CortoInvoke_metaDescriptor[i]);
    }

    metaDescriptor = (char*)malloc(strlength+1);
    metaDescriptor[0] = '\0';
    for (i = 0; i < ddsx_CortoInvoke_metaDescriptorArrLength; i++) {
        strcat(metaDescriptor,ddsx_CortoInvoke_metaDescriptor[i]);
    }
	result = DDS__FooTypeSupport__alloc (
	    __ddsx_CortoInvoke__name(),
            __ddsx_CortoInvoke__keys(),
            metaDescriptor,
            NULL,
            (DDS_copyIn)__ddsx_CortoInvoke__copyIn,
            (DDS_copyOut)__ddsx_CortoInvoke__copyOut,
            (DDS_unsigned_long)(sizeof(ddsx_CortoInvoke)),
            (DDS_typeSupportAllocBuffer)DDS_sequence_ddsx_CortoInvoke_allocbuf
        );
    free(metaDescriptor);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeTypeSupport_register_type (
    ddsx_CortoInvokeTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooTypeSupport_register_type (
	    (DDS_TypeSupport)_this,
	    domain,
	    name
	);
    return result;
}

DDS_string
ddsx_CortoInvokeTypeSupport_get_type_name (
    ddsx_CortoInvokeTypeSupport _this
    )
{
    DDS_string result = (DDS_string)
        DDS__FooTypeSupport_get_type_name (
	    (DDS_TypeSupport)_this
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoInvokeDataWriter_register_instance (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoInvokeDataWriter_register_instance_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_register_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_unregister_instance (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance (
	    (const DDS_DataWriter)_this,
	    (DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_unregister_instance_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_unregister_instance_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_write (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_write_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_write_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_dispose (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_dispose_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_dispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_writedispose (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_writedispose_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_writedispose_w_timestamp (
	    (DDS_DataWriter)_this,
	    (const DDS_sample)instance_data,
	    instance_handle,
	    source_timestamp
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_get_key_value (
    ddsx_CortoInvokeDataWriter _this,
    ddsx_CortoInvoke *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataWriter_get_key_value (
	    (DDS_DataWriter)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoInvokeDataWriter_lookup_instance (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataWriter_lookup_instance (
        (DDS_DataWriter)_this,
        (DDS_sample)key_holder
    );
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_next_sample (
    ddsx_CortoInvokeDataReader _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_next_sample (
    ddsx_CortoInvokeDataReader _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_sample (
	    (DDS_DataReader)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_instance (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_instance (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_next_instance (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_next_instance (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_next_instance_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_read_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_next_instance_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_take_next_instance_w_condition (
	    (DDS_DataReader)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    a_condition
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_return_loan (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_return_loan (
            (DDS_DataReader)_this,
            (DDS_sequence)received_data,
            info_seq
    );
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_get_key_value (
    ddsx_CortoInvokeDataReader _this,
    ddsx_CortoInvoke *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReader_get_key_value (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}

DDS_InstanceHandle_t
ddsx_CortoInvokeDataReader_lookup_instance (
    ddsx_CortoInvokeDataReader _this,
    const ddsx_CortoInvoke *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReader_lookup_instance (
	    (DDS_DataReader)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_next_sample (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_next_sample (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_sample (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)received_data,
	    sample_info
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_instance (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_instance (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_next_instance (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_next_instance (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
	    sample_states,
	    view_states,
	    instance_states
	);
    return result;
}

DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_return_loan (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_return_loan (
            (DDS_DataReaderView)_this,
            (DDS_sequence)received_data,
            info_seq
    );

    if ( result == DDS_RETCODE_OK ) {
        DDS__free(received_data->_buffer);
        received_data->_length  = 0;
        received_data->_maximum = 0;
        received_data->_buffer  = NULL;

        DDS__free(info_seq->_buffer);
        info_seq->_length  = 0;
        info_seq->_maximum = 0;
        info_seq->_buffer  = NULL;
    }

    return result;
}


DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_next_instance_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_read_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_next_instance_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
   )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_take_next_instance_w_condition (
	    (DDS_DataReaderView)_this,
	    (DDS_sequence)received_data,
	    info_seq,
	    max_samples,
	    a_handle,
            a_condition
	);
    return result;
}


DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_get_key_value (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *key_holder,
    const DDS_InstanceHandle_t handle
    )
{
    DDS_ReturnCode_t result = (DDS_ReturnCode_t)
        DDS__FooDataReaderView_get_key_value (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder,
	    handle
	);
    return result;
}


DDS_InstanceHandle_t
ddsx_CortoInvokeDataReaderView_lookup_instance (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *key_holder
    )
{
    DDS_InstanceHandle_t result = (DDS_InstanceHandle_t)
        DDS__FooDataReaderView_lookup_instance (
	    (DDS_DataReaderView)_this,
	    (DDS_sample)key_holder
	);
    return result;
}

#if defined (__cplusplus)
}
#endif
