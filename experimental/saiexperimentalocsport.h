/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiexperimentalocsport.h
 *
 * @brief   This module defines the OCS port
 */

#if !defined (__SAIEXPERIMENTALOCSPORT_H_)
#define __SAIEXPERIMENTALOCSPORT_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALOCSPORT SAI - OCS port specific API definitions
 *
 * @{
 */

/** @brief OCS port configuration status */
typedef enum _sai_ocs_port_config_status_t
{
    SAI_OCS_PORT_CONFIG_STATUS_POWERED_OFF,
    SAI_OCS_PORT_CONFIG_STATUS_NORMAL,
    SAI_OCS_PORT_CONFIG_STATUS_FORCE_BLOCKED,
} sai_ocs_port_config_status_t;

/** @brief OCS port operation status */
typedef enum _sai_ocs_port_oper_status_t
{
    SAI_OCS_PORT_OPER_STATUS_POWERED_OFF,
    SAI_OCS_PORT_OPER_STATUS_BLOCKED,
    SAI_OCS_PORT_OPER_STATUS_TUNING,
    SAI_OCS_PORT_OPER_STATUS_CONNECTED,
    SAI_OCS_PORT_OPER_STATUS_FAILED,
} sai_ocs_port_oper_status_t;

/**
 * @brief OCS attribute IDs
 */
typedef enum _sai_ocs_port_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OCS_PORT_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OCS_PORT_ATTR_ID = SAI_OCS_PORT_ATTR_START,

    /**
     * @brief Simplex port id
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    SAI_OCS_PORT_ATTR_SIMPLEX_PORT_ID,

    /**
     * @brief Label
     *
     * @type char
     * @flags CREATE_AND_SET
     */
    SAI_OCS_PORT_ATTR_LABEL,

    /**
     * @brief Port configuration status
     *
     * @type sai_ocs_port_config_status_t
     * @flags CREATE_AND_SET
     */
    SAI_OCS_PORT_ATTR_CONFIG_STATUS,

    /**
     * @brief Connector type
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OCS_PORT_ATTR_CONNECTOR_TYPE,

    /**
     * @brief Connector pin
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OCS_PORT_ATTR_CONNECTOR_PIN,

    /**
     * @brief Target simplex port id
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OCS_PORT_ATTR_TARGET_SIMPLEX_PORT_ID,

    /**
     * @brief Port operation status
     *
     * @type sai_ocs_port_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OCS_PORT_ATTR_OPER_STATUS,

    /**
     * @brief End of attributes
     */
    SAI_OCS_PORT_ATTR_END,

    /** Custom range base value */
    SAI_OCS_PORT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OCS_PORT_ATTR_CUSTOM_RANGE_END

} sai_ocs_port_attr_t;

/**
 * @brief OCS port stat IDs
 */
typedef enum _sai_ocs_port_stat_t
{
    /**
     * @brief Start of statistics
     */
    SAI_OCS_PORT_STAT_START,

    /**
     * @brief A place holder
     */
    SAI_OCS_PORT_STAT_NO_USE = SAI_OCS_PORT_STAT_START,

    /**
     * @brief End of statistics
     */
    SAI_OCS_PORT_STAT_END

} sai_ocs_port_stat_t;

/**
 * @brief Create OCS port.
 *
 * Allocates and initializes a OCS port.
 *
 * @param[out] ocs_port_id OCS port id
 * @param[in] switch_id Switch id on which the OCS exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_ocs_port_fn)(
        _Out_ sai_object_id_t *ocs_port_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OCS port
 *
 * @param[in] ocs_port_id OCS port id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_ocs_port_fn)(
        _In_ sai_object_id_t ocs_port_id);

/**
 * @brief Set OCS attribute
 *
 * @param[in] ocs_port_id OCS port id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_ocs_port_attribute_fn)(
        _In_ sai_object_id_t ocs_port_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OCS port attribute
 *
 * @param[in] ocs_port_id OCS port id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ocs_port_attribute_fn)(
        _In_ sai_object_id_t ocs_port_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get OCS port statistics.
 *
 * @param[in] ocs_port_id OCS port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ocs_port_stats_fn)(
        _In_ sai_object_id_t ocs_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get OCS statistics extended.
 *
 * @param[in] ocs_port_id OCS port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ocs_port_stats_ext_fn)(
        _In_ sai_object_id_t ocs_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear OCS port statistics counters.
 *
 * @param[in] ocs_port_id OCS port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_ocs_port_stats_fn)(
        _In_ sai_object_id_t ocs_port_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_ocs_port_api_t
{
    sai_create_ocs_port_fn                create_ocs_port;
    sai_remove_ocs_port_fn                remove_ocs_port;
    sai_set_ocs_port_attribute_fn         set_ocs_port_attribute;
    sai_get_ocs_port_attribute_fn         get_ocs_port_attribute;
    sai_get_ocs_port_stats_fn             get_ocs_port_stats;
    sai_get_ocs_port_stats_ext_fn         get_ocs_port_stats_ext;
    sai_clear_ocs_port_stats_fn           clear_ocs_port_stats;
} sai_ocs_port_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOCSPORT_H_ */
