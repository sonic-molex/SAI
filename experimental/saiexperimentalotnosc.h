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
 * @brief OSC stat IDs
 * The stat_t in switch is used for collecting various counters, see _sai_port_stat_t in saiport.h.
 * In OTN project stat_t is used to support stats of gauge/analog value. In openconfig yang model,
 * a gauge value(e.g., power, attenuation, tilt, loss) should support the following stats:
 * instant, avg, min, max, interval, min-time, max-time.
 */
typedef enum _sai_otn_osc_stat_t
{
    /** OSC stat range start */
    SAI_OTN_OSC_STAT_START,

    /** Input optical power instant */
    SAI_OTN_OSC_STAT_INPUT_POWER_INSTANT = SAI_OTN_OSC_STAT_START,

    /** Input optical power avg */
    SAI_OTN_OSC_STAT_INPUT_POWER_AVG,

    /** Input optical power min */
    SAI_OTN_OSC_STAT_INPUT_POWER_MIN,

    /** Input optical power max */
    SAI_OTN_OSC_STAT_INPUT_POWER_MAX,

    /** Input optical power interval */
    SAI_OTN_OSC_STAT_INPUT_POWER_INTERVAL,

    /** Input optical power min-time */
    SAI_OTN_OSC_STAT_INPUT_POWER_MIN_TIME,

    /** Input optical power max-time */
    SAI_OTN_OSC_STAT_INPUT_POWER_MAX_TIME,

    /** Output optical power instant */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_INSTANT,

    /** Output optical power avg */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_AVG,

    /** Output optical power min */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_MIN,

    /** Output optical power max */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_MAX,

    /** Output optical power interval */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_INTERVAL,

    /** Output optical power min-time */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_MIN_TIME,

    /** Output optical power max-time */
    SAI_OTN_OSC_STAT_OUTPUT_POWER_MAX_TIME,

    /** Laser bias current instant */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_INSTANT,

    /** Laser bias current avg */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_AVG,

    /** Laser bias current min */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_MIN,

    /** Laser bias current max */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_MAX,

    /** Laser bias current interval */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_INTERVAL,

    /** Laser bias current min-time */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_MIN_TIME,

    /** Laser bias current max-time */
    SAI_OTN_OSC_STAT_LASER_BIAS_CURRENT_MAX_TIME,

    /** End of statistics */
    SAI_OTN_OSC_STAT_END,

} sai_otn_osc_stat_t;

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
 * @brief Get OSC statistics.
 *
 * @param[in] otn_osc_id OSC id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_osc_stats_fn)(
        _In_ sai_object_id_t otn_osc_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get OSC statistics extended.
 *
 * @param[in] otn_osc_id OSC id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_osc_stats_ext_fn)(
        _In_ sai_object_id_t otn_osc_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear OSC statistics counters.
 *
 * @param[in] otn_osc_id OSC id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_otn_osc_stats_fn)(
        _In_ sai_object_id_t otn_osc_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_osc_api_t
{
    sai_create_otn_osc_fn                create_otn_osc;
    sai_remove_otn_osc_fn                remove_otn_osc;
    sai_set_otn_osc_attribute_fn         set_otn_osc_attribute;
    sai_get_otn_osc_attribute_fn         get_otn_osc_attribute;
    sai_get_otn_osc_stats_fn             get_otn_osc_stats;
    sai_get_otn_osc_stats_ext_fn         get_otn_osc_stats_ext;
    sai_clear_otn_osc_stats_fn           clear_otn_osc_stats;
} sai_otn_osc_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNOSC_H_ */
