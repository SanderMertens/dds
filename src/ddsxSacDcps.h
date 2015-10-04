#ifndef DDSXSACDCPS_H
#define DDSXSACDCPS_H

#include "ddsxDcps.h"

#ifndef DDS_API
#define DDS_API
#endif


#define ddsx_CortoDeclareTypeSupport DDS_TypeSupport

 ddsx_CortoDeclareTypeSupport
ddsx_CortoDeclareTypeSupport__alloc (
    void
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareTypeSupport_register_type (
    ddsx_CortoDeclareTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

 DDS_string
ddsx_CortoDeclareTypeSupport_get_type_name (
    ddsx_CortoDeclareTypeSupport _this
    );

#ifndef _DDS_sequence_ddsx_CortoDeclare_defined
#define _DDS_sequence_ddsx_CortoDeclare_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    ddsx_CortoDeclare *_buffer;
    DDS_boolean _release;
} DDS_sequence_ddsx_CortoDeclare;

 DDS_sequence_ddsx_CortoDeclare *DDS_sequence_ddsx_CortoDeclare__alloc (void);
 ddsx_CortoDeclare *DDS_sequence_ddsx_CortoDeclare_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_ddsx_CortoDeclare_defined */

#define ddsx_CortoDeclareDataWriter DDS_DataWriter

#define ddsx_CortoDeclareDataWriter_enable DDS_Entity_enable

#define ddsx_CortoDeclareDataWriter_get_status_changes DDS_Entity_get_status_changes

#define ddsx_CortoDeclareDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define ddsx_CortoDeclareDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoDeclareDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define ddsx_CortoDeclareDataWriter_get_listener DDS_DataWriter_get_listener

#define ddsx_CortoDeclareDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define ddsx_CortoDeclareDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define ddsx_CortoDeclareDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define ddsx_CortoDeclareDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define ddsx_CortoDeclareDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define ddsx_CortoDeclareDataWriter_get_publication_matched_status DDS_DataWriter_get_publication_matched_status

#define ddsx_CortoDeclareDataWriter_get_publisher DDS_DataWriter_get_publisher

#define ddsx_CortoDeclareDataWriter_get_qos DDS_DataWriter_get_qos

#define ddsx_CortoDeclareDataWriter_get_topic DDS_DataWriter_get_topic

#define ddsx_CortoDeclareDataWriter_set_listener DDS_DataWriter_set_listener

#define ddsx_CortoDeclareDataWriter_set_qos DDS_DataWriter_set_qos

 DDS_InstanceHandle_t
ddsx_CortoDeclareDataWriter_register_instance (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data
    );

 DDS_InstanceHandle_t
ddsx_CortoDeclareDataWriter_register_instance_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_unregister_instance (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_unregister_instance_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_write (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_write_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_dispose (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_dispose_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_writedispose (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_writedispose_w_timestamp (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataWriter_get_key_value (
    ddsx_CortoDeclareDataWriter _this,
    ddsx_CortoDeclare *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoDeclareDataWriter_lookup_instance (
    ddsx_CortoDeclareDataWriter _this,
    const ddsx_CortoDeclare *key_holder
    );

#define ddsx_CortoDeclareDataReader DDS_DataReader

#define ddsx_CortoDeclareDataReader_enable DDS_Entity_enable

#define ddsx_CortoDeclareDataReader_get_status_changes DDS_Entity_get_status_changes

#define ddsx_CortoDeclareDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define ddsx_CortoDeclareDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoDeclareDataReader_create_querycondition DDS_DataReader_create_querycondition

#define ddsx_CortoDeclareDataReader_create_readcondition DDS_DataReader_create_readcondition

#define ddsx_CortoDeclareDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define ddsx_CortoDeclareDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define ddsx_CortoDeclareDataReader_get_listener DDS_DataReader_get_listener

#define ddsx_CortoDeclareDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define ddsx_CortoDeclareDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define ddsx_CortoDeclareDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define ddsx_CortoDeclareDataReader_get_qos DDS_DataReader_get_qos

#define ddsx_CortoDeclareDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define ddsx_CortoDeclareDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define ddsx_CortoDeclareDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define ddsx_CortoDeclareDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define ddsx_CortoDeclareDataReader_get_subscriber DDS_DataReader_get_subscriber

#define ddsx_CortoDeclareDataReader_get_subscription_matched_status DDS_DataReader_get_subscription_matched_status

#define ddsx_CortoDeclareDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define ddsx_CortoDeclareDataReader_set_listener DDS_DataReader_set_listener

#define ddsx_CortoDeclareDataReader_set_qos DDS_DataReader_set_qos

#define ddsx_CortoDeclareDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_next_sample (
    ddsx_CortoDeclareDataReader _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_next_sample (
    ddsx_CortoDeclareDataReader _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    );

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
    );

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
    );

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
    );

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
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_read_next_instance_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_take_next_instance_w_condition (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_return_loan (
    ddsx_CortoDeclareDataReader _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReader_get_key_value (
    ddsx_CortoDeclareDataReader _this,
    ddsx_CortoDeclare *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoDeclareDataReader_lookup_instance (
    ddsx_CortoDeclareDataReader _this,
    const ddsx_CortoDeclare *key_holder
    );

#define ddsx_CortoDeclareDataReaderView DDS_DataReaderView

#define ddsx_CortoDeclareDataReaderView_enable DDS_Entity_enable

#define ddsx_CortoDeclareDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoDeclareDataReaderView_get_qos DDS_DataReaderView_get_qos

#define ddsx_CortoDeclareDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define ddsx_CortoDeclareDataReaderView_set_qos DDS_DataReaderView_set_qos

#define ddsx_CortoDeclareDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define ddsx_CortoDeclareDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define ddsx_CortoDeclareDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define ddsx_CortoDeclareDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_next_sample (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_next_sample (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *received_data,
    DDS_SampleInfo *sample_info
    );

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
    );

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
    );

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
    );

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
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_return_loan (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_read_next_instance_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_take_next_instance_w_condition (
    ddsx_CortoDeclareDataReaderView _this,
    DDS_sequence_ddsx_CortoDeclare *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoDeclareDataReaderView_get_key_value (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoDeclareDataReaderView_lookup_instance (
    ddsx_CortoDeclareDataReaderView _this,
    ddsx_CortoDeclare *key_holder
    );


#define ddsx_CortoUpdateTypeSupport DDS_TypeSupport

 ddsx_CortoUpdateTypeSupport
ddsx_CortoUpdateTypeSupport__alloc (
    void
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateTypeSupport_register_type (
    ddsx_CortoUpdateTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

 DDS_string
ddsx_CortoUpdateTypeSupport_get_type_name (
    ddsx_CortoUpdateTypeSupport _this
    );

#ifndef _DDS_sequence_ddsx_CortoUpdate_defined
#define _DDS_sequence_ddsx_CortoUpdate_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    ddsx_CortoUpdate *_buffer;
    DDS_boolean _release;
} DDS_sequence_ddsx_CortoUpdate;

 DDS_sequence_ddsx_CortoUpdate *DDS_sequence_ddsx_CortoUpdate__alloc (void);
 ddsx_CortoUpdate *DDS_sequence_ddsx_CortoUpdate_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_ddsx_CortoUpdate_defined */

#define ddsx_CortoUpdateDataWriter DDS_DataWriter

#define ddsx_CortoUpdateDataWriter_enable DDS_Entity_enable

#define ddsx_CortoUpdateDataWriter_get_status_changes DDS_Entity_get_status_changes

#define ddsx_CortoUpdateDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define ddsx_CortoUpdateDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoUpdateDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define ddsx_CortoUpdateDataWriter_get_listener DDS_DataWriter_get_listener

#define ddsx_CortoUpdateDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define ddsx_CortoUpdateDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define ddsx_CortoUpdateDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define ddsx_CortoUpdateDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define ddsx_CortoUpdateDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define ddsx_CortoUpdateDataWriter_get_publication_matched_status DDS_DataWriter_get_publication_matched_status

#define ddsx_CortoUpdateDataWriter_get_publisher DDS_DataWriter_get_publisher

#define ddsx_CortoUpdateDataWriter_get_qos DDS_DataWriter_get_qos

#define ddsx_CortoUpdateDataWriter_get_topic DDS_DataWriter_get_topic

#define ddsx_CortoUpdateDataWriter_set_listener DDS_DataWriter_set_listener

#define ddsx_CortoUpdateDataWriter_set_qos DDS_DataWriter_set_qos

 DDS_InstanceHandle_t
ddsx_CortoUpdateDataWriter_register_instance (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data
    );

 DDS_InstanceHandle_t
ddsx_CortoUpdateDataWriter_register_instance_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_unregister_instance (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_unregister_instance_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_write (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_write_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_dispose (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_dispose_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_writedispose (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_writedispose_w_timestamp (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataWriter_get_key_value (
    ddsx_CortoUpdateDataWriter _this,
    ddsx_CortoUpdate *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoUpdateDataWriter_lookup_instance (
    ddsx_CortoUpdateDataWriter _this,
    const ddsx_CortoUpdate *key_holder
    );

#define ddsx_CortoUpdateDataReader DDS_DataReader

#define ddsx_CortoUpdateDataReader_enable DDS_Entity_enable

#define ddsx_CortoUpdateDataReader_get_status_changes DDS_Entity_get_status_changes

#define ddsx_CortoUpdateDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define ddsx_CortoUpdateDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoUpdateDataReader_create_querycondition DDS_DataReader_create_querycondition

#define ddsx_CortoUpdateDataReader_create_readcondition DDS_DataReader_create_readcondition

#define ddsx_CortoUpdateDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define ddsx_CortoUpdateDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define ddsx_CortoUpdateDataReader_get_listener DDS_DataReader_get_listener

#define ddsx_CortoUpdateDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define ddsx_CortoUpdateDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define ddsx_CortoUpdateDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define ddsx_CortoUpdateDataReader_get_qos DDS_DataReader_get_qos

#define ddsx_CortoUpdateDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define ddsx_CortoUpdateDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define ddsx_CortoUpdateDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define ddsx_CortoUpdateDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define ddsx_CortoUpdateDataReader_get_subscriber DDS_DataReader_get_subscriber

#define ddsx_CortoUpdateDataReader_get_subscription_matched_status DDS_DataReader_get_subscription_matched_status

#define ddsx_CortoUpdateDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define ddsx_CortoUpdateDataReader_set_listener DDS_DataReader_set_listener

#define ddsx_CortoUpdateDataReader_set_qos DDS_DataReader_set_qos

#define ddsx_CortoUpdateDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_next_sample (
    ddsx_CortoUpdateDataReader _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_next_sample (
    ddsx_CortoUpdateDataReader _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    );

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
    );

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
    );

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
    );

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
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_read_next_instance_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_take_next_instance_w_condition (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_return_loan (
    ddsx_CortoUpdateDataReader _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReader_get_key_value (
    ddsx_CortoUpdateDataReader _this,
    ddsx_CortoUpdate *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoUpdateDataReader_lookup_instance (
    ddsx_CortoUpdateDataReader _this,
    const ddsx_CortoUpdate *key_holder
    );

#define ddsx_CortoUpdateDataReaderView DDS_DataReaderView

#define ddsx_CortoUpdateDataReaderView_enable DDS_Entity_enable

#define ddsx_CortoUpdateDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoUpdateDataReaderView_get_qos DDS_DataReaderView_get_qos

#define ddsx_CortoUpdateDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define ddsx_CortoUpdateDataReaderView_set_qos DDS_DataReaderView_set_qos

#define ddsx_CortoUpdateDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define ddsx_CortoUpdateDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define ddsx_CortoUpdateDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define ddsx_CortoUpdateDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_next_sample (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_next_sample (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *received_data,
    DDS_SampleInfo *sample_info
    );

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
    );

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
    );

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
    );

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
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_return_loan (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_read_next_instance_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_take_next_instance_w_condition (
    ddsx_CortoUpdateDataReaderView _this,
    DDS_sequence_ddsx_CortoUpdate *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoUpdateDataReaderView_get_key_value (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoUpdateDataReaderView_lookup_instance (
    ddsx_CortoUpdateDataReaderView _this,
    ddsx_CortoUpdate *key_holder
    );


#define ddsx_CortoInvokeTypeSupport DDS_TypeSupport

 ddsx_CortoInvokeTypeSupport
ddsx_CortoInvokeTypeSupport__alloc (
    void
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeTypeSupport_register_type (
    ddsx_CortoInvokeTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

 DDS_string
ddsx_CortoInvokeTypeSupport_get_type_name (
    ddsx_CortoInvokeTypeSupport _this
    );

#ifndef _DDS_sequence_ddsx_CortoInvoke_defined
#define _DDS_sequence_ddsx_CortoInvoke_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    ddsx_CortoInvoke *_buffer;
    DDS_boolean _release;
} DDS_sequence_ddsx_CortoInvoke;

 DDS_sequence_ddsx_CortoInvoke *DDS_sequence_ddsx_CortoInvoke__alloc (void);
 ddsx_CortoInvoke *DDS_sequence_ddsx_CortoInvoke_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_ddsx_CortoInvoke_defined */

#define ddsx_CortoInvokeDataWriter DDS_DataWriter

#define ddsx_CortoInvokeDataWriter_enable DDS_Entity_enable

#define ddsx_CortoInvokeDataWriter_get_status_changes DDS_Entity_get_status_changes

#define ddsx_CortoInvokeDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define ddsx_CortoInvokeDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoInvokeDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define ddsx_CortoInvokeDataWriter_get_listener DDS_DataWriter_get_listener

#define ddsx_CortoInvokeDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define ddsx_CortoInvokeDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define ddsx_CortoInvokeDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define ddsx_CortoInvokeDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define ddsx_CortoInvokeDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define ddsx_CortoInvokeDataWriter_get_publication_matched_status DDS_DataWriter_get_publication_matched_status

#define ddsx_CortoInvokeDataWriter_get_publisher DDS_DataWriter_get_publisher

#define ddsx_CortoInvokeDataWriter_get_qos DDS_DataWriter_get_qos

#define ddsx_CortoInvokeDataWriter_get_topic DDS_DataWriter_get_topic

#define ddsx_CortoInvokeDataWriter_set_listener DDS_DataWriter_set_listener

#define ddsx_CortoInvokeDataWriter_set_qos DDS_DataWriter_set_qos

 DDS_InstanceHandle_t
ddsx_CortoInvokeDataWriter_register_instance (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data
    );

 DDS_InstanceHandle_t
ddsx_CortoInvokeDataWriter_register_instance_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_unregister_instance (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_unregister_instance_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_write (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_write_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_dispose (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_dispose_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_writedispose (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_writedispose_w_timestamp (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataWriter_get_key_value (
    ddsx_CortoInvokeDataWriter _this,
    ddsx_CortoInvoke *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoInvokeDataWriter_lookup_instance (
    ddsx_CortoInvokeDataWriter _this,
    const ddsx_CortoInvoke *key_holder
    );

#define ddsx_CortoInvokeDataReader DDS_DataReader

#define ddsx_CortoInvokeDataReader_enable DDS_Entity_enable

#define ddsx_CortoInvokeDataReader_get_status_changes DDS_Entity_get_status_changes

#define ddsx_CortoInvokeDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define ddsx_CortoInvokeDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoInvokeDataReader_create_querycondition DDS_DataReader_create_querycondition

#define ddsx_CortoInvokeDataReader_create_readcondition DDS_DataReader_create_readcondition

#define ddsx_CortoInvokeDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define ddsx_CortoInvokeDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define ddsx_CortoInvokeDataReader_get_listener DDS_DataReader_get_listener

#define ddsx_CortoInvokeDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define ddsx_CortoInvokeDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define ddsx_CortoInvokeDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define ddsx_CortoInvokeDataReader_get_qos DDS_DataReader_get_qos

#define ddsx_CortoInvokeDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define ddsx_CortoInvokeDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define ddsx_CortoInvokeDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define ddsx_CortoInvokeDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define ddsx_CortoInvokeDataReader_get_subscriber DDS_DataReader_get_subscriber

#define ddsx_CortoInvokeDataReader_get_subscription_matched_status DDS_DataReader_get_subscription_matched_status

#define ddsx_CortoInvokeDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define ddsx_CortoInvokeDataReader_set_listener DDS_DataReader_set_listener

#define ddsx_CortoInvokeDataReader_set_qos DDS_DataReader_set_qos

#define ddsx_CortoInvokeDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_next_sample (
    ddsx_CortoInvokeDataReader _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_next_sample (
    ddsx_CortoInvokeDataReader _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    );

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
    );

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
    );

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
    );

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
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_read_next_instance_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_take_next_instance_w_condition (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_return_loan (
    ddsx_CortoInvokeDataReader _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReader_get_key_value (
    ddsx_CortoInvokeDataReader _this,
    ddsx_CortoInvoke *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoInvokeDataReader_lookup_instance (
    ddsx_CortoInvokeDataReader _this,
    const ddsx_CortoInvoke *key_holder
    );

#define ddsx_CortoInvokeDataReaderView DDS_DataReaderView

#define ddsx_CortoInvokeDataReaderView_enable DDS_Entity_enable

#define ddsx_CortoInvokeDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define ddsx_CortoInvokeDataReaderView_get_qos DDS_DataReaderView_get_qos

#define ddsx_CortoInvokeDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define ddsx_CortoInvokeDataReaderView_set_qos DDS_DataReaderView_set_qos

#define ddsx_CortoInvokeDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define ddsx_CortoInvokeDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define ddsx_CortoInvokeDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define ddsx_CortoInvokeDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_next_sample (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_next_sample (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *received_data,
    DDS_SampleInfo *sample_info
    );

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
    );

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
    );

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
    );

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
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_return_loan (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_read_next_instance_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_take_next_instance_w_condition (
    ddsx_CortoInvokeDataReaderView _this,
    DDS_sequence_ddsx_CortoInvoke *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

 DDS_ReturnCode_t
ddsx_CortoInvokeDataReaderView_get_key_value (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *key_holder,
    const DDS_InstanceHandle_t handle
    );

 DDS_InstanceHandle_t
ddsx_CortoInvokeDataReaderView_lookup_instance (
    ddsx_CortoInvokeDataReaderView _this,
    ddsx_CortoInvoke *key_holder
    );

#endif
