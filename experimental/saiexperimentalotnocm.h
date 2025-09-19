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
 * @file    saiexperimentalotnocm.h
 *
 * @brief   This module defines SAI extensions for optical channel monitor (OCM).
 * It is derived from openconfig-channel-monitor.yang, revision 2024-04-04.
 *
 * @warning This module is a SAI experimental module
 */

#if !defined (__SAIEXPERIMENTALOTNOCM_H_)
#define __SAIEXPERIMENTALOTNOCM_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALOTNOCM SAI - Experimental: OCM specific API definitions
 *
 * @{
 */

/**
 * @brief OCM attribute IDs
 */
typedef enum _sai_otn_ocm_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_OCM_ATTR_START,

    /**
     * @brief Reference to system-supplied name of the port on the
     * optical channel monitor (OCM).
     *
     * @type char
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OCM_ATTR_NAME = SAI_OTN_OCM_ATTR_START,

    /**
     * @brief Reference to system-supplied name of the port that the
     * channel monitor is physically connected to.
     *
     * @type char
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OCM_ATTR_MONITOR_PORT,

    /**
     * @brief End of attributes
     */
    SAI_OTN_OCM_ATTR_END,

    /** Custom range base value */
    SAI_OTN_OCM_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_OCM_ATTR_CUSTOM_RANGE_END

} sai_otn_ocm_attr_t;

/**
 * @brief Create OCM.
 *
 * Allocates and initializes a OCM.
 *
 * @param[out] otn_ocm_id OCM id
 * @param[in] switch_id Switch id on which the OCM exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_ocm_fn)(
        _Out_ sai_object_id_t *otn_ocm_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OCM
 *
 * @param[in] otn_ocm_id OCM id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_ocm_fn)(
        _In_ sai_object_id_t otn_ocm_id);

/**
 * @brief Set OCM attribute
 *
 * @param[in] otn_ocm_id OCM id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_ocm_attribute_fn)(
        _In_ sai_object_id_t otn_ocm_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OCM attribute
 *
 * @param[in] otn_ocm_id OCM id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_ocm_attribute_fn)(
        _In_ sai_object_id_t otn_ocm_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief OCM channel attribute IDs
 */
typedef enum _sai_otn_ocm_channel_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_OCM_CHANNEL_ATTR_START,

    /**
     * @brief References the media channel name of the optical channel monitor.
     *
     * @type char
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OCM_CHANNEL_ATTR_NAME = SAI_OTN_OCM_CHANNEL_ATTR_START,

    /**
     * @brief The lower frequency for the spectrum defined by this media channel.
     * The frequency unit is MHz.
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OCM_CHANNEL_ATTR_LOWER_FREQUENCY,

    /**
     * @brief The upper frequency for the spectrum defined by this media channel.
     * The frequency unit is MHz.
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OCM_CHANNEL_ATTR_UPPER_FREQUENCY,

    /**
     * @brief Average measured optical power over the specified spectrum in units of 0.01dBm.
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OCM_CHANNEL_ATTR_POWER,

    /**
     * @brief Target optical power over the specified spectrum in units of 0.01dBm.
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OCM_CHANNEL_ATTR_TARGET_POWER,

    /**
     * @brief End of attributes
     */
    SAI_OTN_OCM_CHANNEL_ATTR_END,

    /** Custom range base value */
    SAI_OTN_OCM_CHANNEL_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_OCM_CHANNEL_ATTR_CUSTOM_RANGE_END

} sai_otn_ocm_channel_attr_t;

/**
 * @brief Create OCM channel.
 *
 * Allocates and initializes a OCM channel.
 *
 * @param[out] otn_ocm_channel_id OCM channel id
 * @param[in] switch_id Switch id on which the OCM exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_ocm_channel_fn)(
        _Out_ sai_object_id_t *otn_ocm_channel_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OCM channel
 *
 * @param[in] otn_ocm_channel_id OCM channel id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_ocm_channel_fn)(
        _In_ sai_object_id_t otn_ocm_channel_id);

/**
 * @brief Set OCM channel attribute
 *
 * @param[in] otn_ocm_channel_id OCM channel id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_ocm_channel_attribute_fn)(
        _In_ sai_object_id_t otn_ocm_channel_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OCM channel attribute
 *
 * @param[in] otn_ocm_channel_id OCM channel id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_ocm_channel_attribute_fn)(
        _In_ sai_object_id_t otn_ocm_channel_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_ocm_api_t
{
    sai_create_otn_ocm_fn                create_otn_ocm;
    sai_remove_otn_ocm_fn                remove_otn_ocm;
    sai_set_otn_ocm_attribute_fn         set_otn_ocm_attribute;
    sai_get_otn_ocm_attribute_fn         get_otn_ocm_attribute;

    sai_create_otn_ocm_channel_fn        create_otn_ocm_channel;
    sai_remove_otn_ocm_channel_fn        remove_otn_ocm_channel;
    sai_set_otn_ocm_channel_attribute_fn set_otn_ocm_channel_attribute;
    sai_get_otn_ocm_channel_attribute_fn get_otn_ocm_channel_attribute;
} sai_otn_ocm_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNOCM_H_ */
