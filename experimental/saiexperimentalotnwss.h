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
 * @file    saiexperimentalotnwss.h
 *
 * @brief   This module defines SAI extensions for wavelength selective switch (WSS) /
 *    dynamic gain equalizer (DGE).
 * It is derived from openconfig-wavelength-router.yang (rev 2024-04-08)
 *
 * @warning This module is a SAI experimental module
 */

#if !defined (__SAIEXPERIMENTALOTNWSS_H_)
#define __SAIEXPERIMENTALOTNWSS_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALOTNWSS SAI - Experimental: WSS specific API definitions
 *
 * @{
 */

/**
 * @brief Administrative state modes for WSS media channels.
 */
typedef enum _sai_otn_wss_admin_state_t
{
    SAI_OTN_WSS_ADMIN_STATE_ENABLED,
    SAI_OTN_WSS_ADMIN_STATE_DISABLED,
    SAI_OTN_WSS_ADMIN_STATE_MAINT,
} sai_otn_wss_admin_state_t;

/**
 * @brief Operational state of the WSS media channel.
 */
typedef enum _sai_otn_wss_oper_status_t
{
    SAI_OTN_WSS_OPER_STATUS_UP,
    SAI_OTN_WSS_OPER_STATUS_DOWN,
} sai_otn_wss_oper_status_t;

/**
 * @brief Status of injected ASE noise on the media channel.
 */
typedef enum _sai_otn_wss_ase_status_t
{
    SAI_OTN_WSS_ASE_STATUS_PRESENT,
    SAI_OTN_WSS_ASE_STATUS_NOT_PRESENT,
} sai_otn_wss_ase_status_t;

/**
 * @brief ASE control mode on a media channel.
 */
typedef enum _sai_otn_wss_ase_control_mode_t
{
    SAI_OTN_WSS_ASE_CONTROL_MODE_ENABLED,
    SAI_OTN_WSS_ASE_CONTROL_MODE_DISABLED,
    SAI_OTN_WSS_ASE_CONTROL_MODE_AUTO_ASE_ON_FAILURE,
    SAI_OTN_WSS_ASE_CONTROL_MODE_AUTO_ASE_FAILURE_AND_RESTORE,
} sai_otn_wss_ase_control_mode_t;

/**
 * @brief ASE injection mode used to determine whether ASE should be injected.
 */
typedef enum _sai_otn_wss_ase_injection_mode_t
{
    SAI_OTN_WSS_ASE_INJECTION_MODE_THRESHOLD,
    SAI_OTN_WSS_ASE_INJECTION_MODE_DELTA,
} sai_otn_wss_ase_injection_mode_t;

/**
 * @brief Attenuation control mode on a media channel.
 */
typedef enum _sai_otn_wss_attenuation_control_mode_t
{
    SAI_OTN_WSS_ATTENUATION_CONTROL_MODE_FIXED_LOSS,
    SAI_OTN_WSS_ATTENUATION_CONTROL_MODE_DYNAMIC_LOSS,
    SAI_OTN_WSS_ATTENUATION_CONTROL_MODE_DYNAMIC_LOSS_DAMPED,
    SAI_OTN_WSS_ATTENUATION_CONTROL_MODE_SET_ATTENUATION,
} sai_otn_wss_attenuation_control_mode_t;

/**
 * @brief Attenuation control range settings on a media channel.
 */
typedef enum _sai_otn_wss_attenuation_control_range_t
{
    SAI_OTN_WSS_ATTENUATION_CONTROL_RANGE_FULL,
    SAI_OTN_WSS_ATTENUATION_CONTROL_RANGE_LIMITED,
} sai_otn_wss_attenuation_control_range_t;

/**
 * @brief WSS (media channel) attribute IDs
 */
typedef enum _sai_otn_wss_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_WSS_ATTR_START,

    /**
     * @brief Identifier for the defined media channel.
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_WSS_ATTR_INDEX = SAI_OTN_WSS_ATTR_START,

    /**
     * @brief The lower frequency for the spectrum defined by this media channel.
     * The frequency unit is MHz.
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_WSS_ATTR_LOWER_FREQUENCY,

    /**
     * @brief The upper frequency for the spectrum defined by this media channel.
     * The frequency unit is MHz.
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_WSS_ATTR_UPPER_FREQUENCY,

    /**
     * @brief Sets the admin state of the media channel.
     *
     * @type sai_otn_wss_admin_state_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_WSS_ADMIN_STATE_ENABLED
     */
    SAI_OTN_WSS_ATTR_ADMIN_STATE,

    /**
     * @brief True if the media channel is a super channel.
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OTN_WSS_ATTR_SUPER_CHANNEL,

    /**
     * @brief Index of the super channel parent, if applicable.
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_OTN_WSS_ATTR_SUPER_CHANNEL_PARENT,

    /**
     * @brief Sets the ASE control mode for the media channel.
     *
     * @type sai_otn_wss_ase_control_mode_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_WSS_ASE_CONTROL_MODE_AUTO_ASE_FAILURE_AND_RESTORE
     */
    SAI_OTN_WSS_ATTR_ASE_CONTROL_MODE,

    /**
     * @brief Defines the mode used to determine whether ASE noise should be injected.
     *
     * @type sai_otn_wss_ase_injection_mode_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_WSS_ASE_INJECTION_MODE_THRESHOLD
     */
    SAI_OTN_WSS_ATTR_ASE_INJECTION_MODE,

    /**
     * @brief Optical power threshold below which ASE noise should be injected,
     * in units of 0.01 dBm.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_ATTR_ASE_INJECTION_THRESHOLD,

    /**
     * @brief Optical power loss delta which indicates that ASE noise should be injected,
     * in units of 0.01 dB.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_ATTR_ASE_INJECTION_DELTA,

    /**
     * @brief Optical power offset relative to ASE injection threshold at which point ASE
     * should be removed and the media-channel should be injected, in units of 0.01 dB.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_ATTR_MEDIA_CHANNEL_INJECTION_OFFSET,

    /**
     * @brief Sets the attenuation control mode for the media channel.
     *
     * @type sai_otn_wss_attenuation_control_mode_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_WSS_ATTENUATION_CONTROL_MODE_SET_ATTENUATION
     */
    SAI_OTN_WSS_ATTR_ATTENUATION_CONTROL_MODE,

    /**
     * @brief Sets the attenuation control range for the media channel.
     *
     * @type sai_otn_wss_attenuation_control_range_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_WSS_ATTENUATION_CONTROL_RANGE_FULL
     */
    SAI_OTN_WSS_ATTR_ATTENUATION_CONTROL_RANGE,

    /**
     * @brief Maximum undershoot compensation, in units of 0.01 dB.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_ATTR_MAX_UNDERSHOOT_COMPENSATION,

    /**
     * @brief Maximum overshoot compensation, in units of 0.01 dB.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_ATTR_MAX_OVERSHOOT_COMPENSATION,

    /**
     * @brief Source port name for the media channel.
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default ""
     */
    SAI_OTN_WSS_ATTR_SOURCE_PORT_NAME,

    /**
     * @brief Destination port name for the media channel.
     *
     * @type char
     * @flags CREATE_AND_SET
     * @default ""
     */
    SAI_OTN_WSS_ATTR_DEST_PORT_NAME,

    /**
     * @brief Operational state of the media channel.
     *
     * @type sai_otn_wss_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OTN_WSS_ATTR_OPER_STATUS,

    /**
     * @brief Status of injected ASE noise on the media channel.
     *
     * @type sai_otn_wss_ase_status_t
     * @flags READ_ONLY
     */
    SAI_OTN_WSS_ATTR_ASE_STATUS,

    /**
     * @brief End of attributes
     */
    SAI_OTN_WSS_ATTR_END,

    /** Custom range base value */
    SAI_OTN_WSS_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_WSS_ATTR_CUSTOM_RANGE_END

} sai_otn_wss_attr_t;

/**
 * @brief WSS spectrum power (per frequency slot) attribute IDs
 */
typedef enum _sai_otn_wss_spec_power_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_START,

    /**
     * @brief Reference to the parent WSS object.
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_OTN_WSS
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_WSS_ID = SAI_OTN_WSS_SPEC_POWER_ATTR_START,

    /**
     * @brief Lower frequency of the specified target spectrum power.
     * The frequency unit is MHz.
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_LOWER_FREQUENCY,

    /**
     * @brief Upper frequency of the specified target spectrum power.
     * The frequency unit is MHz.
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_UPPER_FREQUENCY,

    /**
     * @brief Target average power to achieve within the specified spectrum,
     * in units of 0.01 dBm.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_TARGET_POWER,

    /**
     * @brief Attenuation value set on this frequency slot, in units of 0.01 dB.
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_ATTENUATION,

    /**
     * @brief Actual attenuation of the media channel, in units of 0.01 dB.
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_ACTUAL_ATTENUATION,

    /**
     * @brief End of attributes
     */
    SAI_OTN_WSS_SPEC_POWER_ATTR_END,

    /** Custom range base value */
    SAI_OTN_WSS_SPEC_POWER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_WSS_SPEC_POWER_ATTR_CUSTOM_RANGE_END

} sai_otn_wss_spec_power_attr_t;

/**
 * @brief Create WSS.
 *
 * Allocates and initializes a WSS media channel.
 *
 * @param[out] otn_wss_id WSS id
 * @param[in] switch_id Switch id on which the WSS exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_wss_fn)(
        _Out_ sai_object_id_t *otn_wss_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove WSS
 *
 * @param[in] otn_wss_id WSS id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_wss_fn)(
        _In_ sai_object_id_t otn_wss_id);

/**
 * @brief Set WSS attribute
 *
 * @param[in] otn_wss_id WSS id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_wss_attribute_fn)(
        _In_ sai_object_id_t otn_wss_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get WSS attribute
 *
 * @param[in] otn_wss_id WSS id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_wss_attribute_fn)(
        _In_ sai_object_id_t otn_wss_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create WSS spectrum power entry.
 *
 * Allocates and initializes a WSS spectrum power entry.
 *
 * @param[out] otn_wss_spec_power_id WSS spectrum power entry id
 * @param[in] switch_id Switch id on which the entry exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_wss_spec_power_fn)(
        _Out_ sai_object_id_t *otn_wss_spec_power_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove WSS spectrum power entry
 *
 * @param[in] otn_wss_spec_power_id WSS spectrum power entry id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_wss_spec_power_fn)(
        _In_ sai_object_id_t otn_wss_spec_power_id);

/**
 * @brief Set WSS spectrum power entry attribute
 *
 * @param[in] otn_wss_spec_power_id WSS spectrum power entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_wss_spec_power_attribute_fn)(
        _In_ sai_object_id_t otn_wss_spec_power_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get WSS spectrum power entry attribute
 *
 * @param[in] otn_wss_spec_power_id WSS spectrum power entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_wss_spec_power_attribute_fn)(
        _In_ sai_object_id_t otn_wss_spec_power_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_wss_api_t
{
    sai_create_otn_wss_fn                       create_otn_wss;
    sai_remove_otn_wss_fn                       remove_otn_wss;
    sai_set_otn_wss_attribute_fn                set_otn_wss_attribute;
    sai_get_otn_wss_attribute_fn                get_otn_wss_attribute;

    sai_create_otn_wss_spec_power_fn            create_otn_wss_spec_power;
    sai_remove_otn_wss_spec_power_fn            remove_otn_wss_spec_power;
    sai_set_otn_wss_spec_power_attribute_fn     set_otn_wss_spec_power_attribute;
    sai_get_otn_wss_spec_power_attribute_fn     get_otn_wss_spec_power_attribute;
} sai_otn_wss_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNWSS_H_ */
