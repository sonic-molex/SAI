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
 * @file    saiexperimentalotnosc.h
 *
 * @brief   This module defines SAI extensions for optical supervisory channel.
 * It is derived from the following yang models:
 * openconfig-optical-amplifier.yang, revision 2019-12-06
 * openconfig-transport-line-common.yang, revision 2019-06-03
 *
 * @warning This module is a SAI experimental module
 */

#if !defined (__SAIEXPERIMENTALOTNOSC_H_)
#define __SAIEXPERIMENTALOTNOSC_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALOTNOSC SAI - Experimental: OSC specific API definitions
 * @{
 */

/**
 * @brief OSC attribute IDs
 */
typedef enum _sai_otn_osc_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_OSC_ATTR_START,

    /**
     * @brief Reference to an OSC interface by name.
     *
     * @type char
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OSC_ATTR_NAME = SAI_OTN_OSC_ATTR_START,

    /**
     * @brief The input optical power of this port in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OSC_ATTR_INPUT_POWER,

    /**
     * @brief The output optical power of this port in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OSC_ATTR_OUTPUT_POWER,

    /**
     * @brief The current applied by the system to the transmit laser to
     * achieve the output power in units of 0.1mA
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 1
     */
    SAI_OTN_OSC_ATTR_LASER_BIAS_CURRENT,

    /**
     * @brief The frequency in MHz of the individual physical channel
     * (e.g. ITU C50 - 195.0THz and would be reported as 195,000,000 MHz in this model).
     *
     * @type sai_uint64_t
     * @flags READ_ONLY
     */
    SAI_OTN_OSC_ATTR_OUTPUT_FREQUENCY,

    /**
     * @brief End of attributes
     */
    SAI_OTN_OSC_ATTR_END,

    /** Custom range base value */
    SAI_OTN_OSC_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_OSC_ATTR_CUSTOM_RANGE_END

} sai_otn_osc_attr_t;

/**
 * @brief Create OSC.
 *
 * Allocates and initializes a OSC.
 *
 * @param[out] otn_osc_id OSC id
 * @param[in] switch_id Switch id on which the OSC exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_osc_fn)(
        _Out_ sai_object_id_t *otn_osc_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OSC
 *
 * @param[in] otn_osc_id OSC id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_osc_fn)(
        _In_ sai_object_id_t otn_osc_id);

/**
 * @brief Set OSC attribute
 *
 * @param[in] otn_osc_id OSC id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_osc_attribute_fn)(
        _In_ sai_object_id_t otn_osc_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OSC attribute
 *
 * @param[in] otn_osc_id OSC id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_osc_attribute_fn)(
        _In_ sai_object_id_t otn_osc_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_osc_api_t
{
    sai_create_otn_osc_fn                create_otn_osc;
    sai_remove_otn_osc_fn                remove_otn_osc;
    sai_set_otn_osc_attribute_fn         set_otn_osc_attribute;
    sai_get_otn_osc_attribute_fn         get_otn_osc_attribute;
} sai_otn_osc_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNOSC_H_ */
