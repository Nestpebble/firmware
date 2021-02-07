/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.4 */

#ifndef PB_MESH_PB_H_INCLUDED
#define PB_MESH_PB_H_INCLUDED
#include <pb.h>
#include "portnums.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _ErrorReason {
    ErrorReason_NONE = 0,
    ErrorReason_NO_ROUTE = 1,
    ErrorReason_GOT_NAK = 2,
    ErrorReason_TIMEOUT = 3,
    ErrorReason_NO_INTERFACE = 4
} ErrorReason;

typedef enum _Constants {
    Constants_Unused = 0,
    Constants_DATA_PAYLOAD_LEN = 240
} Constants;

typedef enum _RegionCode {
    RegionCode_Unset = 0,
    RegionCode_US = 1,
    RegionCode_EU433 = 2,
    RegionCode_EU865 = 3,
    RegionCode_CN = 4,
    RegionCode_JP = 5,
    RegionCode_ANZ = 6,
    RegionCode_KR = 7,
    RegionCode_TW = 8
} RegionCode;

typedef enum _ChargeCurrent {
    ChargeCurrent_MAUnset = 0,
    ChargeCurrent_MA100 = 1,
    ChargeCurrent_MA190 = 2,
    ChargeCurrent_MA280 = 3,
    ChargeCurrent_MA360 = 4,
    ChargeCurrent_MA450 = 5,
    ChargeCurrent_MA550 = 6,
    ChargeCurrent_MA630 = 7,
    ChargeCurrent_MA700 = 8,
    ChargeCurrent_MA780 = 9,
    ChargeCurrent_MA880 = 10,
    ChargeCurrent_MA960 = 11,
    ChargeCurrent_MA1000 = 12,
    ChargeCurrent_MA1080 = 13,
    ChargeCurrent_MA1160 = 14,
    ChargeCurrent_MA1240 = 15,
    ChargeCurrent_MA1320 = 16
} ChargeCurrent;

typedef enum _GpsOperation {
    GpsOperation_GpsOpUnset = 0,
    GpsOperation_GpsOpStationary = 1,
    GpsOperation_GpsOpMobile = 2,
    GpsOperation_GpsOpTimeOnly = 3,
    GpsOperation_GpsOpDisabled = 4
} GpsOperation;

typedef enum _LocationSharing {
    LocationSharing_LocUnset = 0,
    LocationSharing_LocEnabled = 1,
    LocationSharing_LocDisabled = 2
} LocationSharing;

typedef enum _CriticalErrorCode {
    CriticalErrorCode_None = 0,
    CriticalErrorCode_TxWatchdog = 1,
    CriticalErrorCode_SleepEnterWait = 2,
    CriticalErrorCode_NoRadio = 3,
    CriticalErrorCode_Unspecified = 4,
    CriticalErrorCode_UBloxInitFailed = 5,
    CriticalErrorCode_NoAXP192 = 6,
    CriticalErrorCode_InvalidRadioSetting = 7,
    CriticalErrorCode_TransmitFailed = 8
} CriticalErrorCode;

typedef enum _ChannelSettings_ModemConfig {
    ChannelSettings_ModemConfig_Bw125Cr45Sf128 = 0,
    ChannelSettings_ModemConfig_Bw500Cr45Sf128 = 1,
    ChannelSettings_ModemConfig_Bw31_25Cr48Sf512 = 2,
    ChannelSettings_ModemConfig_Bw125Cr48Sf4096 = 3
} ChannelSettings_ModemConfig;

typedef enum _LogRecord_Level {
    LogRecord_Level_UNSET = 0,
    LogRecord_Level_CRITICAL = 50,
    LogRecord_Level_ERROR = 40,
    LogRecord_Level_WARNING = 30,
    LogRecord_Level_INFO = 20,
    LogRecord_Level_DEBUG = 10,
    LogRecord_Level_TRACE = 5
} LogRecord_Level;

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(32) ChannelSettings_psk_t;
typedef struct _ChannelSettings {
    int32_t tx_power;
    ChannelSettings_ModemConfig modem_config;
    ChannelSettings_psk_t psk;
    char name[12];
    uint32_t bandwidth;
    uint32_t spread_factor;
    uint32_t coding_rate;
    uint32_t channel_num;
    uint32_t id;
    bool uplink_enabled;
    bool downlink_enabled;
} ChannelSettings;

typedef PB_BYTES_ARRAY_T(240) Data_payload_t;
typedef struct _Data {
    PortNum portnum;
    Data_payload_t payload;
} Data;

typedef struct _LogRecord {
    char message[64];
    uint32_t time;
    char source[8];
    LogRecord_Level level;
} LogRecord;

typedef struct _MyNodeInfo {
    uint32_t my_node_num;
    bool has_gps;
    int32_t num_channels;
    char region[12];
    char hw_model[16];
    char firmware_version[12];
    CriticalErrorCode error_code;
    uint32_t error_address;
    uint32_t error_count;
    uint32_t packet_id_bits;
    uint32_t current_packet_id;
    uint32_t node_num_bits;
    uint32_t message_timeout_msec;
    uint32_t min_app_version;
} MyNodeInfo;

typedef struct _Position {
    int32_t altitude;
    int32_t battery_level;
    int32_t latitude_i;
    int32_t longitude_i;
    uint32_t time;
} Position;

typedef struct _RadioConfig_UserPreferences {
    uint32_t position_broadcast_secs;
    uint32_t send_owner_interval;
    uint32_t wait_bluetooth_secs;
    uint32_t screen_on_secs;
    uint32_t phone_timeout_secs;
    uint32_t phone_sds_timeout_sec;
    uint32_t mesh_sds_timeout_secs;
    uint32_t sds_secs;
    uint32_t ls_secs;
    uint32_t min_wake_secs;
    char wifi_ssid[33];
    char wifi_password[64];
    bool wifi_ap_mode;
    RegionCode region;
    ChargeCurrent charge_current;
    LocationSharing location_share;
    GpsOperation gps_operation;
    uint32_t gps_update_interval;
    uint32_t gps_attempt_time;
    bool is_router;
    bool is_low_power;
    bool fixed_position;
    bool factory_reset;
    bool debug_log_enabled;
    pb_size_t ignore_incoming_count;
    uint32_t ignore_incoming[3];
    bool serialplugin_enabled;
    bool serialplugin_echo;
    uint32_t serialplugin_rxd;
    uint32_t serialplugin_txd;
    uint32_t serialplugin_timeout;
    uint32_t serialplugin_mode;
    bool ext_notification_plugin_enabled;
    uint32_t ext_notification_plugin_output_ms;
    uint32_t ext_notification_plugin_output;
    bool ext_notification_plugin_active;
    bool ext_notification_plugin_alert_message;
    bool ext_notification_plugin_alert_bell;
} RadioConfig_UserPreferences;

typedef struct _RouteDiscovery {
    pb_size_t route_count;
    int32_t route[8];
} RouteDiscovery;

typedef struct _User {
    char id[16];
    char long_name[40];
    char short_name[5];
    pb_byte_t macaddr[6];
} User;

typedef struct _NodeInfo {
    uint32_t num;
    bool has_user;
    User user;
    bool has_position;
    Position position;
    uint32_t next_hop;
    float snr;
} NodeInfo;

typedef struct _RadioConfig {
    bool has_preferences;
    RadioConfig_UserPreferences preferences;
    bool has_channel_settings;
    ChannelSettings channel_settings;
} RadioConfig;

typedef struct _SubPacket {
    pb_size_t which_payload;
    union {
        Position position;
        Data data;
        User user;
        RouteDiscovery route_request;
        RouteDiscovery route_reply;
        ErrorReason error_reason;
    };
    uint32_t original_id;
    bool want_response;
    uint32_t dest;
    pb_size_t which_ack;
    union {
        uint32_t success_id;
        uint32_t fail_id;
    } ack;
    uint32_t source;
} SubPacket;

typedef PB_BYTES_ARRAY_T(256) MeshPacket_encrypted_t;
typedef struct _MeshPacket {
    uint32_t from;
    uint32_t to;
    pb_size_t which_payload;
    union {
        SubPacket decoded;
        MeshPacket_encrypted_t encrypted;
    };
    uint32_t channel_index;
    uint32_t id;
    float rx_snr;
    uint32_t rx_time;
    uint32_t hop_limit;
    bool want_ack;
} MeshPacket;

typedef struct _FromRadio {
    uint32_t num;
    pb_size_t which_variant;
    union {
        MeshPacket packet;
        MyNodeInfo my_info;
        NodeInfo node_info;
        RadioConfig radio;
        LogRecord log_record;
        uint32_t config_complete_id;
        bool rebooted;
        ChannelSettings channel;
    } variant;
} FromRadio;

typedef struct _ToRadio {
    pb_size_t which_variant;
    union {
        MeshPacket packet;
        uint32_t want_config_id;
        RadioConfig set_radio;
        User set_owner;
        ChannelSettings set_channel;
    } variant;
} ToRadio;


/* Helper constants for enums */
#define _ErrorReason_MIN ErrorReason_NONE
#define _ErrorReason_MAX ErrorReason_NO_INTERFACE
#define _ErrorReason_ARRAYSIZE ((ErrorReason)(ErrorReason_NO_INTERFACE+1))

#define _Constants_MIN Constants_Unused
#define _Constants_MAX Constants_DATA_PAYLOAD_LEN
#define _Constants_ARRAYSIZE ((Constants)(Constants_DATA_PAYLOAD_LEN+1))

#define _RegionCode_MIN RegionCode_Unset
#define _RegionCode_MAX RegionCode_TW
#define _RegionCode_ARRAYSIZE ((RegionCode)(RegionCode_TW+1))

#define _ChargeCurrent_MIN ChargeCurrent_MAUnset
#define _ChargeCurrent_MAX ChargeCurrent_MA1320
#define _ChargeCurrent_ARRAYSIZE ((ChargeCurrent)(ChargeCurrent_MA1320+1))

#define _GpsOperation_MIN GpsOperation_GpsOpUnset
#define _GpsOperation_MAX GpsOperation_GpsOpDisabled
#define _GpsOperation_ARRAYSIZE ((GpsOperation)(GpsOperation_GpsOpDisabled+1))

#define _LocationSharing_MIN LocationSharing_LocUnset
#define _LocationSharing_MAX LocationSharing_LocDisabled
#define _LocationSharing_ARRAYSIZE ((LocationSharing)(LocationSharing_LocDisabled+1))

#define _CriticalErrorCode_MIN CriticalErrorCode_None
#define _CriticalErrorCode_MAX CriticalErrorCode_TransmitFailed
#define _CriticalErrorCode_ARRAYSIZE ((CriticalErrorCode)(CriticalErrorCode_TransmitFailed+1))

#define _ChannelSettings_ModemConfig_MIN ChannelSettings_ModemConfig_Bw125Cr45Sf128
#define _ChannelSettings_ModemConfig_MAX ChannelSettings_ModemConfig_Bw125Cr48Sf4096
#define _ChannelSettings_ModemConfig_ARRAYSIZE ((ChannelSettings_ModemConfig)(ChannelSettings_ModemConfig_Bw125Cr48Sf4096+1))

#define _LogRecord_Level_MIN LogRecord_Level_UNSET
#define _LogRecord_Level_MAX LogRecord_Level_CRITICAL
#define _LogRecord_Level_ARRAYSIZE ((LogRecord_Level)(LogRecord_Level_CRITICAL+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define Position_init_default                    {0, 0, 0, 0, 0}
#define Data_init_default                        {_PortNum_MIN, {0, {0}}}
#define User_init_default                        {"", "", "", {0}}
#define RouteDiscovery_init_default              {0, {0, 0, 0, 0, 0, 0, 0, 0}}
#define SubPacket_init_default                   {0, {Position_init_default}, 0, 0, 0, 0, {0}, 0}
#define MeshPacket_init_default                  {0, 0, 0, {SubPacket_init_default}, 0, 0, 0, 0, 0, 0}
#define ChannelSettings_init_default             {0, _ChannelSettings_ModemConfig_MIN, {0, {0}}, "", 0, 0, 0, 0, 0, 0, 0}
#define RadioConfig_init_default                 {false, RadioConfig_UserPreferences_init_default, false, ChannelSettings_init_default}
#define RadioConfig_UserPreferences_init_default {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", 0, _RegionCode_MIN, _ChargeCurrent_MIN, _LocationSharing_MIN, _GpsOperation_MIN, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NodeInfo_init_default                    {0, false, User_init_default, false, Position_init_default, 0, 0}
#define MyNodeInfo_init_default                  {0, 0, 0, "", "", "", _CriticalErrorCode_MIN, 0, 0, 0, 0, 0, 0, 0}
#define LogRecord_init_default                   {"", 0, "", _LogRecord_Level_MIN}
#define FromRadio_init_default                   {0, 0, {MeshPacket_init_default}}
#define ToRadio_init_default                     {0, {MeshPacket_init_default}}
#define Position_init_zero                       {0, 0, 0, 0, 0}
#define Data_init_zero                           {_PortNum_MIN, {0, {0}}}
#define User_init_zero                           {"", "", "", {0}}
#define RouteDiscovery_init_zero                 {0, {0, 0, 0, 0, 0, 0, 0, 0}}
#define SubPacket_init_zero                      {0, {Position_init_zero}, 0, 0, 0, 0, {0}, 0}
#define MeshPacket_init_zero                     {0, 0, 0, {SubPacket_init_zero}, 0, 0, 0, 0, 0, 0}
#define ChannelSettings_init_zero                {0, _ChannelSettings_ModemConfig_MIN, {0, {0}}, "", 0, 0, 0, 0, 0, 0, 0}
#define RadioConfig_init_zero                    {false, RadioConfig_UserPreferences_init_zero, false, ChannelSettings_init_zero}
#define RadioConfig_UserPreferences_init_zero    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", 0, _RegionCode_MIN, _ChargeCurrent_MIN, _LocationSharing_MIN, _GpsOperation_MIN, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NodeInfo_init_zero                       {0, false, User_init_zero, false, Position_init_zero, 0, 0}
#define MyNodeInfo_init_zero                     {0, 0, 0, "", "", "", _CriticalErrorCode_MIN, 0, 0, 0, 0, 0, 0, 0}
#define LogRecord_init_zero                      {"", 0, "", _LogRecord_Level_MIN}
#define FromRadio_init_zero                      {0, 0, {MeshPacket_init_zero}}
#define ToRadio_init_zero                        {0, {MeshPacket_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define ChannelSettings_tx_power_tag             1
#define ChannelSettings_modem_config_tag         3
#define ChannelSettings_psk_tag                  4
#define ChannelSettings_name_tag                 5
#define ChannelSettings_bandwidth_tag            6
#define ChannelSettings_spread_factor_tag        7
#define ChannelSettings_coding_rate_tag          8
#define ChannelSettings_channel_num_tag          9
#define ChannelSettings_id_tag                   10
#define ChannelSettings_uplink_enabled_tag       16
#define ChannelSettings_downlink_enabled_tag     17
#define Data_portnum_tag                         1
#define Data_payload_tag                         2
#define LogRecord_message_tag                    1
#define LogRecord_time_tag                       2
#define LogRecord_source_tag                     3
#define LogRecord_level_tag                      4
#define MyNodeInfo_my_node_num_tag               1
#define MyNodeInfo_has_gps_tag                   2
#define MyNodeInfo_num_channels_tag              3
#define MyNodeInfo_region_tag                    4
#define MyNodeInfo_hw_model_tag                  5
#define MyNodeInfo_firmware_version_tag          6
#define MyNodeInfo_error_code_tag                7
#define MyNodeInfo_error_address_tag             8
#define MyNodeInfo_error_count_tag               9
#define MyNodeInfo_packet_id_bits_tag            10
#define MyNodeInfo_current_packet_id_tag         11
#define MyNodeInfo_node_num_bits_tag             12
#define MyNodeInfo_message_timeout_msec_tag      13
#define MyNodeInfo_min_app_version_tag           14
#define Position_altitude_tag                    3
#define Position_battery_level_tag               4
#define Position_latitude_i_tag                  7
#define Position_longitude_i_tag                 8
#define Position_time_tag                        9
#define RadioConfig_UserPreferences_position_broadcast_secs_tag 1
#define RadioConfig_UserPreferences_send_owner_interval_tag 2
#define RadioConfig_UserPreferences_wait_bluetooth_secs_tag 4
#define RadioConfig_UserPreferences_screen_on_secs_tag 5
#define RadioConfig_UserPreferences_phone_timeout_secs_tag 6
#define RadioConfig_UserPreferences_phone_sds_timeout_sec_tag 7
#define RadioConfig_UserPreferences_mesh_sds_timeout_secs_tag 8
#define RadioConfig_UserPreferences_sds_secs_tag 9
#define RadioConfig_UserPreferences_ls_secs_tag  10
#define RadioConfig_UserPreferences_min_wake_secs_tag 11
#define RadioConfig_UserPreferences_wifi_ssid_tag 12
#define RadioConfig_UserPreferences_wifi_password_tag 13
#define RadioConfig_UserPreferences_wifi_ap_mode_tag 14
#define RadioConfig_UserPreferences_region_tag   15
#define RadioConfig_UserPreferences_charge_current_tag 16
#define RadioConfig_UserPreferences_location_share_tag 32
#define RadioConfig_UserPreferences_gps_operation_tag 33
#define RadioConfig_UserPreferences_gps_update_interval_tag 34
#define RadioConfig_UserPreferences_gps_attempt_time_tag 36
#define RadioConfig_UserPreferences_is_router_tag 37
#define RadioConfig_UserPreferences_is_low_power_tag 38
#define RadioConfig_UserPreferences_fixed_position_tag 39
#define RadioConfig_UserPreferences_factory_reset_tag 100
#define RadioConfig_UserPreferences_debug_log_enabled_tag 101
#define RadioConfig_UserPreferences_ignore_incoming_tag 103
#define RadioConfig_UserPreferences_serialplugin_enabled_tag 120
#define RadioConfig_UserPreferences_serialplugin_echo_tag 121
#define RadioConfig_UserPreferences_serialplugin_rxd_tag 122
#define RadioConfig_UserPreferences_serialplugin_txd_tag 123
#define RadioConfig_UserPreferences_serialplugin_timeout_tag 124
#define RadioConfig_UserPreferences_serialplugin_mode_tag 125
#define RadioConfig_UserPreferences_ext_notification_plugin_enabled_tag 126
#define RadioConfig_UserPreferences_ext_notification_plugin_output_ms_tag 127
#define RadioConfig_UserPreferences_ext_notification_plugin_output_tag 128
#define RadioConfig_UserPreferences_ext_notification_plugin_active_tag 129
#define RadioConfig_UserPreferences_ext_notification_plugin_alert_message_tag 130
#define RadioConfig_UserPreferences_ext_notification_plugin_alert_bell_tag 131
#define RouteDiscovery_route_tag                 2
#define User_id_tag                              1
#define User_long_name_tag                       2
#define User_short_name_tag                      3
#define User_macaddr_tag                         4
#define NodeInfo_num_tag                         1
#define NodeInfo_user_tag                        2
#define NodeInfo_position_tag                    3
#define NodeInfo_next_hop_tag                    5
#define NodeInfo_snr_tag                         7
#define RadioConfig_preferences_tag              1
#define RadioConfig_channel_settings_tag         2
#define SubPacket_position_tag                   1
#define SubPacket_data_tag                       3
#define SubPacket_user_tag                       4
#define SubPacket_route_request_tag              6
#define SubPacket_route_reply_tag                7
#define SubPacket_error_reason_tag               13
#define SubPacket_original_id_tag                2
#define SubPacket_want_response_tag              5
#define SubPacket_dest_tag                       9
#define SubPacket_success_id_tag                 10
#define SubPacket_fail_id_tag                    11
#define SubPacket_source_tag                     12
#define MeshPacket_from_tag                      1
#define MeshPacket_to_tag                        2
#define MeshPacket_decoded_tag                   3
#define MeshPacket_encrypted_tag                 8
#define MeshPacket_channel_index_tag             4
#define MeshPacket_id_tag                        6
#define MeshPacket_rx_snr_tag                    7
#define MeshPacket_rx_time_tag                   9
#define MeshPacket_hop_limit_tag                 10
#define MeshPacket_want_ack_tag                  11
#define FromRadio_num_tag                        1
#define FromRadio_packet_tag                     2
#define FromRadio_my_info_tag                    3
#define FromRadio_node_info_tag                  4
#define FromRadio_radio_tag                      6
#define FromRadio_log_record_tag                 7
#define FromRadio_config_complete_id_tag         8
#define FromRadio_rebooted_tag                   9
#define FromRadio_channel_tag                    10
#define ToRadio_packet_tag                       1
#define ToRadio_want_config_id_tag               100
#define ToRadio_set_radio_tag                    101
#define ToRadio_set_owner_tag                    102
#define ToRadio_set_channel_tag                  103

/* Struct field encoding specification for nanopb */
#define Position_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    altitude,          3) \
X(a, STATIC,   SINGULAR, INT32,    battery_level,     4) \
X(a, STATIC,   SINGULAR, SINT32,   latitude_i,        7) \
X(a, STATIC,   SINGULAR, SINT32,   longitude_i,       8) \
X(a, STATIC,   SINGULAR, FIXED32,  time,              9)
#define Position_CALLBACK NULL
#define Position_DEFAULT NULL

#define Data_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    portnum,           1) \
X(a, STATIC,   SINGULAR, BYTES,    payload,           2)
#define Data_CALLBACK NULL
#define Data_DEFAULT NULL

#define User_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   id,                1) \
X(a, STATIC,   SINGULAR, STRING,   long_name,         2) \
X(a, STATIC,   SINGULAR, STRING,   short_name,        3) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, macaddr,           4)
#define User_CALLBACK NULL
#define User_DEFAULT NULL

#define RouteDiscovery_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, INT32,    route,             2)
#define RouteDiscovery_CALLBACK NULL
#define RouteDiscovery_DEFAULT NULL

#define SubPacket_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,position,position),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,data,data),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,user,user),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,route_request,route_request),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,route_reply,route_reply),   7) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,error_reason,error_reason),  13) \
X(a, STATIC,   SINGULAR, UINT32,   original_id,       2) \
X(a, STATIC,   SINGULAR, BOOL,     want_response,     5) \
X(a, STATIC,   SINGULAR, UINT32,   dest,              9) \
X(a, STATIC,   ONEOF,    UINT32,   (ack,success_id,ack.success_id),  10) \
X(a, STATIC,   ONEOF,    UINT32,   (ack,fail_id,ack.fail_id),  11) \
X(a, STATIC,   SINGULAR, UINT32,   source,           12)
#define SubPacket_CALLBACK NULL
#define SubPacket_DEFAULT NULL
#define SubPacket_payload_position_MSGTYPE Position
#define SubPacket_payload_data_MSGTYPE Data
#define SubPacket_payload_user_MSGTYPE User
#define SubPacket_payload_route_request_MSGTYPE RouteDiscovery
#define SubPacket_payload_route_reply_MSGTYPE RouteDiscovery

#define MeshPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   from,              1) \
X(a, STATIC,   SINGULAR, UINT32,   to,                2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,decoded,decoded),   3) \
X(a, STATIC,   ONEOF,    BYTES,    (payload,encrypted,encrypted),   8) \
X(a, STATIC,   SINGULAR, UINT32,   channel_index,     4) \
X(a, STATIC,   SINGULAR, UINT32,   id,                6) \
X(a, STATIC,   SINGULAR, FLOAT,    rx_snr,            7) \
X(a, STATIC,   SINGULAR, FIXED32,  rx_time,           9) \
X(a, STATIC,   SINGULAR, UINT32,   hop_limit,        10) \
X(a, STATIC,   SINGULAR, BOOL,     want_ack,         11)
#define MeshPacket_CALLBACK NULL
#define MeshPacket_DEFAULT NULL
#define MeshPacket_payload_decoded_MSGTYPE SubPacket

#define ChannelSettings_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    tx_power,          1) \
X(a, STATIC,   SINGULAR, UENUM,    modem_config,      3) \
X(a, STATIC,   SINGULAR, BYTES,    psk,               4) \
X(a, STATIC,   SINGULAR, STRING,   name,              5) \
X(a, STATIC,   SINGULAR, UINT32,   bandwidth,         6) \
X(a, STATIC,   SINGULAR, UINT32,   spread_factor,     7) \
X(a, STATIC,   SINGULAR, UINT32,   coding_rate,       8) \
X(a, STATIC,   SINGULAR, UINT32,   channel_num,       9) \
X(a, STATIC,   SINGULAR, FIXED32,  id,               10) \
X(a, STATIC,   SINGULAR, BOOL,     uplink_enabled,   16) \
X(a, STATIC,   SINGULAR, BOOL,     downlink_enabled,  17)
#define ChannelSettings_CALLBACK NULL
#define ChannelSettings_DEFAULT NULL

#define RadioConfig_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  preferences,       1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  channel_settings,   2)
#define RadioConfig_CALLBACK NULL
#define RadioConfig_DEFAULT NULL
#define RadioConfig_preferences_MSGTYPE RadioConfig_UserPreferences
#define RadioConfig_channel_settings_MSGTYPE ChannelSettings

#define RadioConfig_UserPreferences_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   position_broadcast_secs,   1) \
X(a, STATIC,   SINGULAR, UINT32,   send_owner_interval,   2) \
X(a, STATIC,   SINGULAR, UINT32,   wait_bluetooth_secs,   4) \
X(a, STATIC,   SINGULAR, UINT32,   screen_on_secs,    5) \
X(a, STATIC,   SINGULAR, UINT32,   phone_timeout_secs,   6) \
X(a, STATIC,   SINGULAR, UINT32,   phone_sds_timeout_sec,   7) \
X(a, STATIC,   SINGULAR, UINT32,   mesh_sds_timeout_secs,   8) \
X(a, STATIC,   SINGULAR, UINT32,   sds_secs,          9) \
X(a, STATIC,   SINGULAR, UINT32,   ls_secs,          10) \
X(a, STATIC,   SINGULAR, UINT32,   min_wake_secs,    11) \
X(a, STATIC,   SINGULAR, STRING,   wifi_ssid,        12) \
X(a, STATIC,   SINGULAR, STRING,   wifi_password,    13) \
X(a, STATIC,   SINGULAR, BOOL,     wifi_ap_mode,     14) \
X(a, STATIC,   SINGULAR, UENUM,    region,           15) \
X(a, STATIC,   SINGULAR, UENUM,    charge_current,   16) \
X(a, STATIC,   SINGULAR, UENUM,    location_share,   32) \
X(a, STATIC,   SINGULAR, UENUM,    gps_operation,    33) \
X(a, STATIC,   SINGULAR, UINT32,   gps_update_interval,  34) \
X(a, STATIC,   SINGULAR, UINT32,   gps_attempt_time,  36) \
X(a, STATIC,   SINGULAR, BOOL,     is_router,        37) \
X(a, STATIC,   SINGULAR, BOOL,     is_low_power,     38) \
X(a, STATIC,   SINGULAR, BOOL,     fixed_position,   39) \
X(a, STATIC,   SINGULAR, BOOL,     factory_reset,   100) \
X(a, STATIC,   SINGULAR, BOOL,     debug_log_enabled, 101) \
X(a, STATIC,   REPEATED, UINT32,   ignore_incoming, 103) \
X(a, STATIC,   SINGULAR, BOOL,     serialplugin_enabled, 120) \
X(a, STATIC,   SINGULAR, BOOL,     serialplugin_echo, 121) \
X(a, STATIC,   SINGULAR, UINT32,   serialplugin_rxd, 122) \
X(a, STATIC,   SINGULAR, UINT32,   serialplugin_txd, 123) \
X(a, STATIC,   SINGULAR, UINT32,   serialplugin_timeout, 124) \
X(a, STATIC,   SINGULAR, UINT32,   serialplugin_mode, 125) \
X(a, STATIC,   SINGULAR, BOOL,     ext_notification_plugin_enabled, 126) \
X(a, STATIC,   SINGULAR, UINT32,   ext_notification_plugin_output_ms, 127) \
X(a, STATIC,   SINGULAR, UINT32,   ext_notification_plugin_output, 128) \
X(a, STATIC,   SINGULAR, BOOL,     ext_notification_plugin_active, 129) \
X(a, STATIC,   SINGULAR, BOOL,     ext_notification_plugin_alert_message, 130) \
X(a, STATIC,   SINGULAR, BOOL,     ext_notification_plugin_alert_bell, 131)
#define RadioConfig_UserPreferences_CALLBACK NULL
#define RadioConfig_UserPreferences_DEFAULT NULL

#define NodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          3) \
X(a, STATIC,   SINGULAR, UINT32,   next_hop,          5) \
X(a, STATIC,   SINGULAR, FLOAT,    snr,               7)
#define NodeInfo_CALLBACK NULL
#define NodeInfo_DEFAULT NULL
#define NodeInfo_user_MSGTYPE User
#define NodeInfo_position_MSGTYPE Position

#define MyNodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   my_node_num,       1) \
X(a, STATIC,   SINGULAR, BOOL,     has_gps,           2) \
X(a, STATIC,   SINGULAR, INT32,    num_channels,      3) \
X(a, STATIC,   SINGULAR, STRING,   region,            4) \
X(a, STATIC,   SINGULAR, STRING,   hw_model,          5) \
X(a, STATIC,   SINGULAR, STRING,   firmware_version,   6) \
X(a, STATIC,   SINGULAR, UENUM,    error_code,        7) \
X(a, STATIC,   SINGULAR, UINT32,   error_address,     8) \
X(a, STATIC,   SINGULAR, UINT32,   error_count,       9) \
X(a, STATIC,   SINGULAR, UINT32,   packet_id_bits,   10) \
X(a, STATIC,   SINGULAR, UINT32,   current_packet_id,  11) \
X(a, STATIC,   SINGULAR, UINT32,   node_num_bits,    12) \
X(a, STATIC,   SINGULAR, UINT32,   message_timeout_msec,  13) \
X(a, STATIC,   SINGULAR, UINT32,   min_app_version,  14)
#define MyNodeInfo_CALLBACK NULL
#define MyNodeInfo_DEFAULT NULL

#define LogRecord_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   message,           1) \
X(a, STATIC,   SINGULAR, FIXED32,  time,              2) \
X(a, STATIC,   SINGULAR, STRING,   source,            3) \
X(a, STATIC,   SINGULAR, UENUM,    level,             4)
#define LogRecord_CALLBACK NULL
#define LogRecord_DEFAULT NULL

#define FromRadio_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,my_info,variant.my_info),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,node_info,variant.node_info),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,radio,variant.radio),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,log_record,variant.log_record),   7) \
X(a, STATIC,   ONEOF,    UINT32,   (variant,config_complete_id,variant.config_complete_id),   8) \
X(a, STATIC,   ONEOF,    BOOL,     (variant,rebooted,variant.rebooted),   9) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,channel,variant.channel),  10)
#define FromRadio_CALLBACK NULL
#define FromRadio_DEFAULT NULL
#define FromRadio_variant_packet_MSGTYPE MeshPacket
#define FromRadio_variant_my_info_MSGTYPE MyNodeInfo
#define FromRadio_variant_node_info_MSGTYPE NodeInfo
#define FromRadio_variant_radio_MSGTYPE RadioConfig
#define FromRadio_variant_log_record_MSGTYPE LogRecord
#define FromRadio_variant_channel_MSGTYPE ChannelSettings

#define ToRadio_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   1) \
X(a, STATIC,   ONEOF,    UINT32,   (variant,want_config_id,variant.want_config_id), 100) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_radio,variant.set_radio), 101) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_owner,variant.set_owner), 102) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_channel,variant.set_channel), 103)
#define ToRadio_CALLBACK NULL
#define ToRadio_DEFAULT NULL
#define ToRadio_variant_packet_MSGTYPE MeshPacket
#define ToRadio_variant_set_radio_MSGTYPE RadioConfig
#define ToRadio_variant_set_owner_MSGTYPE User
#define ToRadio_variant_set_channel_MSGTYPE ChannelSettings

extern const pb_msgdesc_t Position_msg;
extern const pb_msgdesc_t Data_msg;
extern const pb_msgdesc_t User_msg;
extern const pb_msgdesc_t RouteDiscovery_msg;
extern const pb_msgdesc_t SubPacket_msg;
extern const pb_msgdesc_t MeshPacket_msg;
extern const pb_msgdesc_t ChannelSettings_msg;
extern const pb_msgdesc_t RadioConfig_msg;
extern const pb_msgdesc_t RadioConfig_UserPreferences_msg;
extern const pb_msgdesc_t NodeInfo_msg;
extern const pb_msgdesc_t MyNodeInfo_msg;
extern const pb_msgdesc_t LogRecord_msg;
extern const pb_msgdesc_t FromRadio_msg;
extern const pb_msgdesc_t ToRadio_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Position_fields &Position_msg
#define Data_fields &Data_msg
#define User_fields &User_msg
#define RouteDiscovery_fields &RouteDiscovery_msg
#define SubPacket_fields &SubPacket_msg
#define MeshPacket_fields &MeshPacket_msg
#define ChannelSettings_fields &ChannelSettings_msg
#define RadioConfig_fields &RadioConfig_msg
#define RadioConfig_UserPreferences_fields &RadioConfig_UserPreferences_msg
#define NodeInfo_fields &NodeInfo_msg
#define MyNodeInfo_fields &MyNodeInfo_msg
#define LogRecord_fields &LogRecord_msg
#define FromRadio_fields &FromRadio_msg
#define ToRadio_fields &ToRadio_msg

/* Maximum encoded size of messages (where known) */
#define Position_size                            39
#define Data_size                                246
#define User_size                                72
#define RouteDiscovery_size                      88
#define SubPacket_size                           275
#define MeshPacket_size                          320
#define ChannelSettings_size                     95
#define RadioConfig_size                         382
#define RadioConfig_UserPreferences_size         282
#define NodeInfo_size                            132
#define MyNodeInfo_size                          106
#define LogRecord_size                           81
#define FromRadio_size                           391
#define ToRadio_size                             386

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
