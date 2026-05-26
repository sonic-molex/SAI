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
 * @file    saiexperimentalocscrossconnect.h
 *
 * @brief   This module defines the OCS cross connect
 */

#if !defined (__SAIEXPERIMENTALOCSCROSSCONNECT_H_)
#define __SAIEXPERIMENTALOCSCROSSCONNECT_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALOCSCONNECT SAI - OCS cross connect specific API definitions
 *
 * @{
 */

/** @brief OCS cross connection operation status */
typedef enum _sai_ocs_cross_connect_oper_status_t
{
    SAI_OCS_CROSS_CONNECT_OPER_STATUS_DISABLED,
    SAI_OCS_CROSS_CONNECT_OPER_STATUS_ENABLED,
    SAI_OCS_CROSS_CONNECT_OPER_STATUS_INVALID,
} sai_ocs_cross_connect_oper_status_t;

/**
 * @brief OCS cross connection attribute IDs
 */
typedef enum _sai_ocs_cross_connect_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OCS_CROSS_CONNECT_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OCS_CROSS_CONNECT_ATTR_ID = SAI_OCS_CROSS_CONNECT_ATTR_START,

    /**
     * @brief Cross connect id
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default ""
     */
    SAI_OCS_CROSS_CONNECT_ATTR_CROSS_CONNECT_ID,

    /**
     * @brief A side
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default ""
     */
    SAI_OCS_CROSS_CONNECT_ATTR_A_SIDE,

    /**
     * @brief B side
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default ""
     */
    SAI_OCS_CROSS_CONNECT_ATTR_B_SIDE,

    /**
     * @brief Physical path
     *
     * @type sai_u8_list_t
     * @flags READ_ONLY
     */
    SAI_OCS_CROSS_CONNECT_ATTR_PHYSICAL_PATH,

    /**
     * @brief Cross connect run time measured insertion loss in dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OCS_CROSS_CONNECT_ATTR_INSERTION_LOSS_DB,

    /**
     * @brief Cross connect operation status
     *
     * @type sai_ocs_cross_connect_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OCS_CROSS_CONNECT_ATTR_OPER_STATUS,

    /**
     * @brief End of attributes
     */
    SAI_OCS_CROSS_CONNECT_ATTR_END,

    /** Custom range base value */
    SAI_OCS_CROSS_CONNECT_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OCS_CROSS_CONNECT_ATTR_CUSTOM_RANGE_END

} sai_ocs_cross_connect_attr_t;

/**
 * @brief Create OCS cross connect.
 *
 * Allocates and initializes a OCS cross connect.
 *
 * @param[out] ocs_cross_connect_id OCS cross connect id
 * @param[in] switch_id Switch id on which the OCS exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_ocs_cross_connect_fn)(
        _Out_ sai_object_id_t *ocs_cross_connect_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OCS cross connect
 *
 * @param[in] ocs_cross_connect_id OCS cross connect id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_ocs_cross_connect_fn)(
        _In_ sai_object_id_t ocs_cross_connect_id);

/**
 * @brief Set OCS attribute
 *
 * @param[in] ocs_cross_connect_id OCS cross connect id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_ocs_cross_connect_attribute_fn)(
        _In_ sai_object_id_t ocs_cross_connect_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OCS cross connect attribute
 *
 * @param[in] ocs_cross_connect_id OCS cross connect id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ocs_cross_connect_attribute_fn)(
        _In_ sai_object_id_t ocs_cross_connect_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief List of OCS cross connect factory data attributes. Inventory data for all possible cross-connects,
 * factory insertion loss measurements
 */
typedef enum _sai_ocs_cross_connect_factory_data_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_START,

    /**
     * @brief Name of A side port in a cross connection
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_A_SIDE_PORT_NAME = SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_START,

    /**
     * @brief Name of B side port in a cross connection.
     *
     * @type char
     * @flags READ_ONLY
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_B_SIDE_PORT_NAME,

    /**
     * @brief Center frequency at which insertion loss is measured, e.g., 229.1 (O-band) 193.5, use int32 for representation of decimal value
     *
     * List of center frequency values. Use int32 for representation of decimal value with 3 fraction digits
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 3
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_FREQUENCY_THZ,

    /**
     * @brief Internal temperature sensor that correlates with the ambient temperature at which
     * the insertion loss is measured in Celsius, e.g., 25.00
     *
     * List of temperatures. Use int32 for representation of decimal value with 2 fraction digits
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_MEASURED_TEMPERATURE,

    /**
     * @brief Factory insertion loss in dB, e.g. 1.23
     *
     * List of insertion loss values. Use int32 for representation of decimal value with 2 fraction digits
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_INSERTION_LOSS_DB,

    /**
     * @brief Factory insertion loss in dB, e.g. 1.23
     *
     * List of insertion loss accuracy values. Use int32 for representation of decimal value with 2 fraction digits
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_INSERTION_LOSS_ACCURACY_DB,

    /**
     * @brief End of attributes
     */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_END,

    /** Custom range base value */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OCS_CROSS_CONNECT_FACTORY_DATA_ATTR_CUSTOM_RANGE_END

} sai_ocs_cross_connect_factory_data_attr_t;

/**
 * @brief Create OCS cross connect factory data entry.
 *
 * @param[out] ocs_cross_connect_factory_data_id OCS cross connect factory data id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_ocs_cross_connect_factory_data_fn)(
        _Out_ sai_object_id_t *ocs_cross_connect_factory_data_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OCS cross connect factory data entry
 *
 * @param[in] ocs_cross_connect_factory_data_id OCS cross connect Id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_ocs_cross_connect_factory_data_fn)(
        _In_ sai_object_id_t ocs_cross_connect_factory_data_id);

/**
 * @brief Set OCS cross connect factory data entry attribute
 *
 * @param[in] ocs_cross_connect_factory_data_id OCS cross connect id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_ocs_cross_connect_factory_data_attribute_fn)(
        _In_ sai_object_id_t ocs_cross_connect_factory_data_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OCS cross connect factory data attribute
 *
 * @param[in] ocs_cross_connect_factory_data_id OCS cross connect id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_ocs_cross_connect_factory_data_attribute_fn)(
        _In_ sai_object_id_t ocs_cross_connect_factory_data_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_ocs_cross_connect_api_t
{
    sai_create_ocs_cross_connect_fn                            create_ocs_cross_connect;
    sai_remove_ocs_cross_connect_fn                            remove_ocs_cross_connect;
    sai_set_ocs_cross_connect_attribute_fn                     set_ocs_cross_connect_attribute;
    sai_get_ocs_cross_connect_attribute_fn                     get_ocs_cross_connect_attribute;
    sai_bulk_object_create_fn                                  create_ocs_cross_connects;
    sai_bulk_object_remove_fn                                  remove_ocs_cross_connects;
    sai_bulk_object_set_attribute_fn                           set_ocs_cross_connects_attribute;
    sai_bulk_object_get_attribute_fn                           get_ocs_cross_connects_attribute;
    sai_create_ocs_cross_connect_factory_data_fn               create_ocs_cross_connect_factory_data;
    sai_remove_ocs_cross_connect_factory_data_fn               remove_ocs_cross_connect_factory_data;
    sai_set_ocs_cross_connect_factory_data_attribute_fn        set_ocs_cross_connect_factory_data_attribute;
    sai_get_ocs_cross_connect_factory_data_attribute_fn        get_ocs_cross_connect_factory_data_attribute;
    sai_bulk_object_create_fn                                  create_ocs_cross_connect_factory_datas;
    sai_bulk_object_remove_fn                                  remove_ocs_cross_connect_factory_datas;
    sai_bulk_object_set_attribute_fn                           set_ocs_cross_connect_factory_datas_attribute;
    sai_bulk_object_get_attribute_fn                           get_ocs_cross_connect_factory_datas_attribute;
} sai_ocs_cross_connect_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOCSCROSSCONNECT_H_ */
