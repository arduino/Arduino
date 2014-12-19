/*
 * wlan.h - CC31xx/CC32xx Host Driver Implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
    
#include "SimpleLink.h"

#ifndef __WLAN_H__
#define	__WLAN_H__

#ifdef	__cplusplus
extern "C" {
#endif

/*!

    \addtogroup wlan
    @{

*/


/*********************************************************************************************/
/* Macro declarations                                                                        */
/*********************************************************************************************/

#define SL_BSSID_LENGTH							                                                        (6)
#define MAXIMAL_SSID_LENGTH						                                                        (32)

#define NUM_OF_RATE_INDEXES                                                                             (20)
#define SIZE_OF_RSSI_HISTOGRAM                                                                          (6)
 
/* WLAN Disconnect Reason Codes */
#define  SL_DISCONNECT_RESERVED_0                                                                       (0)
#define  SL_DISCONNECT_UNSPECIFIED_REASON                                                               (1)
#define  SL_PREVIOUS_AUTHENTICATION_NO_LONGER_VALID                                                     (2)
#define  SL_DEAUTHENTICATED_BECAUSE_SENDING_STATION_IS_LEAVING                                          (3)
#define  SL_DISASSOCIATED_DUE_TO_INACTIVITY                                                             (4)
#define  SL_DISASSOCIATED_BECAUSE_AP_IS_UNABLE_TO_HANDLE_ALL_CURRENTLY_ASSOCIATED_STATIONS              (5)
#define  SL_CLASS_2_FRAME_RECEIVED_FROM_NONAUTHENTICATED_STATION                                        (6)
#define  SL_CLASS_3_FRAME_RECEIVED_FROM_NONASSOCIATED_STATION                                           (7)
#define  SL_DISASSOCIATED_BECAUSE_SENDING_STATION_IS_LEAVING_BSS                                        (8)
#define  SL_STATION_REQUESTING_ASSOCIATION_IS_NOT_AUTHENTICATED_WITH_RESPONDING_STATION                 (9)
#define  SL_DISASSOCIATED_BECAUSE_THE_INFORMATION_IN_THE_POWER_CAPABILITY_ELEMENT_IS_UNACCEPTABLE       (10)
#define  SL_DISASSOCIATED_BECAUSE_THE_INFORMATION_IN_THE_SUPPORTED_CHANNELS_ELEMENT_IS_UNACCEPTABLE     (11)
#define  SL_DISCONNECT_RESERVED_1                                                                       (12)
#define  SL_INVALID_INFORMATION_ELEMENT                                                                 (13)
#define  SL_MESSAGE_INTEGRITY_CODE_MIC_FAILURE                                                          (14)
#define  SL_FOUR_WAY_HANDSHAKE_TIMEOUT                                                                  (15)
#define  SL_GROUP_KEY_HANDSHAKE_TIMEOUT                                                                 (16)
#define  SL_RE_ASSOCIATION_REQUEST_PROBE_RESPONSE_BEACON_FRAME                                          (17)
#define  SL_INVALID_GROUP_CIPHER                                                                        (18)
#define  SL_INVALID_PAIRWISE_CIPHER                                                                     (19)
#define  SL_INVALID_AKMP                                                                                (20)
#define  SL_UNSUPPORTED_RSN_INFORMATION_ELEMENT_VERSION                                                 (21)
#define  SL_INVALID_RSN_INFORMATION_ELEMENT_CAPABILITIES                                                (22)
#define  SL_IEEE_802_1X_AUTHENTICATION_FAILED                                                           (23)
#define  SL_CIPHER_SUITE_REJECTED_BECAUSE_OF_THE_SECURITY_POLICY                                        (24)
#define  SL_DISCONNECT_RESERVED_2                                                                       (25)
#define  SL_DISCONNECT_RESERVED_3                                                                       (26)
#define  SL_DISCONNECT_RESERVED_4                                                                       (27)
#define  SL_DISCONNECT_RESERVED_5                                                                       (28)
#define  SL_DISCONNECT_RESERVED_6                                                                       (29)
#define  SL_DISCONNECT_RESERVED_7                                                                       (30)
#define  SL_DISCONNECT_RESERVED_8                                                                       (31)
#define  SL_DISASSOCIATED_FOR_UNSPECIFIED_QOS_RELATED_REASON                                            (32)
#define  SL_DISASSOCIATED_BECAUSE_QAP_LACKS_SUFFICIENT_BANDWIDTH_FOR_THIS_QSTA                          (33)
#define  SL_DISASSOCIATED_BECAUSE_EXCESSIVE_NUMBER_OF_FRAMES_NEED_TO_BE_ACKNOWLEDGED                    (34)
#define  SL_DISASSOCIATED_BECAUSE_QSTA_IS_TRANSMITTING_OUTSIDE_THE_LIMITS_OF_ITS_TXOPS                  (35)
#define  SL_REQUESTED_FROM_PEER_QSTA_AS_THE_QSTA_IS_LEAVING_THE_QBSS 		                            (36)
#define  SL_REQUESTED_FROM_PEER_QSTA_AS_IT_DOES_NO_WANT_TO_USE_THE_MECHANISM                            (37)
#define  SL_REQUESTED_FROM_PEER_QSTA_AS_THE_QSTA_RECEIVED_FRAMES_SETUP_IS_REQUIRED                      (38)
#define  SL_REQUESTED_FROM_PEER_QSTA_DUE_TO_TIMEOUT                                                     (39)
#define  SL_PEER_QSTA_DOES_NOT_SUPPORT_THE_REQUESTED_CIPHER_SUITE                                       (40)
#define  SL_CISCO_DEFINED                                                                               (98)
#define  SL_CISCO_DEFINED_1                                                                             (99)
#define  SL_ROAMING_TRIGGER_NONE                                                                        (100)
#define  SL_ROAMING_TRIGGER_LOW_QUALITY_FOR_BG_SCAN                                                     (101)
#define  SL_ROAMING_TRIGGER_HIGH_QUALITY_FOR_BG_SCAN                                                    (102)
#define  SL_ROAMING_TRIGGER_NORMAL_QUALITY_FOR_BG_SCAN                                                  (103)
#define  SL_ROAMING_TRIGGER_LOW_TX_RATE                                                                 (104)
#define  SL_ROAMING_TRIGGER_LOW_SNR                                                                     (105)
#define  SL_ROAMING_TRIGGER_LOW_QUALITY                                                                 (106)
#define  SL_ROAMING_TRIGGER_TSPEC_REJECTED                                                              (107)
#define  SL_ROAMING_TRIGGER_MAX_TX_RETRIES                                                              (108)
#define  SL_ROAMING_TRIGGER_BSS_LOSS                                                                    (109)
#define  SL_ROAMING_TRIGGER_BSS_LOSS_DUE_TO_MAX_TX_RETRY                                                (110)
#define  SL_ROAMING_TRIGGER_SWITCH_CHANNEL                                                              (111)
#define  SL_ROAMING_TRIGGER_AP_DISCONNECT                                                               (112)
#define  SL_ROAMING_TRIGGER_SECURITY_ATTACK                                                             (113)
#define  SL_ROAMING_TRIGGER_MAX                                                                         (114)
#define  SL_USER_INITIATED_DISCONNECTION                                                                (200)

/* Wlan error codes */
#define  SL_ERROR_KEY_ERROR                                                                             (-3)
#define  SL_ERROR_INVALID_ROLE                                                                          (-71)
#define  SL_ERROR_INVALID_SECURITY_TYPE                                                                 (-84)
#define  SL_ERROR_PASSPHRASE_TOO_LONG                                                                   (-85)
#define  SL_ERROR_EAP_WRONG_METHOD                                                                      (-88)
#define  SL_ERROR_PASSWORD_ERROR                                                                        (-89)
#define  SL_ERROR_EAP_ANONYMOUS_LEN_ERROR                                                               (-90)
#define  SL_ERROR_SSID_LEN_ERROR                                                                        (-91)
#define  SL_ERROR_USER_ID_LEN_ERROR                                                                     (-92)
#define  SL_ERROR_ILLEGAL_WEP_KEY_INDEX                                                                 (-95)
#define  SL_ERROR_INVALID_POLICY_TYPE                                                                   (-97)
#define  SL_ERROR_PM_POLICY_INVALID_OPTION                                                              (-98)
#define  SL_ERROR_PM_POLICY_INVALID_PARAMS                                                              (-99)


#define SL_SEC_TYPE_OPEN                                                                                (0)
#define SL_SEC_TYPE_WEP                                                                                 (1)
#define SL_SEC_TYPE_WPA                                                                                 (2)
#define SL_SEC_TYPE_WPS_PBC                                                                             (3)
#define SL_SEC_TYPE_WPS_PIN                                                                             (4)
#define SL_SEC_TYPE_WPA_ENT                                                                             (5)
#define SL_SEC_TYPE_P2P_PBC                                                                             (6)
#define SL_SEC_TYPE_P2P_PIN_KEYPAD				                                                        (7)
#define SL_SEC_TYPE_P2P_PIN_DISPLAY				                                                        (8)
#define SL_SEC_TYPE_P2P_PIN_AUTO				                                                        (9) /* NOT Supported yet */


#define TLS                                (0x1)
#define MSCHAP                             (0x0)
#define PSK                                (0x2) 
#define TTLS                               (0x10)
#define PEAP0                              (0x20)
#define PEAP1                              (0x40)
#define FAST                               (0x80)

#define FAST_AUTH_PROVISIONING             (0x02)
#define FAST_UNAUTH_PROVISIONING           (0x01)
#define FAST_NO_PROVISIONING               (0x00)

#define EAPMETHOD_PHASE2_SHIFT             (8)
#define EAPMETHOD_PAIRWISE_CIPHER_SHIFT    (19)
#define EAPMETHOD_GROUP_CIPHER_SHIFT       (27)

#define WPA_CIPHER_CCMP                    (0x1) 
#define WPA_CIPHER_TKIP                    (0x2)
#define CC31XX_DEFAULT_CIPHER              (WPA_CIPHER_CCMP | WPA_CIPHER_TKIP)

#define EAPMETHOD(phase1,phase2,pairwise_cipher,group_cipher) \
((phase1) | \
 ((phase2) << EAPMETHOD_PHASE2_SHIFT ) |\
 ((unsigned long)(pairwise_cipher) << EAPMETHOD_PAIRWISE_CIPHER_SHIFT ) |\
 ((unsigned long)(group_cipher) << EAPMETHOD_GROUP_CIPHER_SHIFT ))

/*                                                            phase1  phase2                     pairwise_cipher         group_cipher         */
#define SL_ENT_EAP_METHOD_TLS                       EAPMETHOD(TLS   , 0                        , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_TTLS_TLS                  EAPMETHOD(TTLS  , TLS                      , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_TTLS_MSCHAPv2             EAPMETHOD(TTLS  , MSCHAP                   , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_TTLS_PSK                  EAPMETHOD(TTLS  , PSK                      , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_PEAP0_TLS                 EAPMETHOD(PEAP0 , TLS                      , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_PEAP0_MSCHAPv2            EAPMETHOD(PEAP0 , MSCHAP                   , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER) 
#define SL_ENT_EAP_METHOD_PEAP0_PSK                 EAPMETHOD(PEAP0 , PSK                      , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_PEAP1_TLS                 EAPMETHOD(PEAP1 , TLS                      , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_PEAP1_MSCHAPv2            EAPMETHOD(PEAP1 , MSCHAP                   , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER) 
#define SL_ENT_EAP_METHOD_PEAP1_PSK                 EAPMETHOD(PEAP1 , PSK                      , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_FAST_AUTH_PROVISIONING    EAPMETHOD(FAST  , FAST_AUTH_PROVISIONING   , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_FAST_UNAUTH_PROVISIONING  EAPMETHOD(FAST  , FAST_UNAUTH_PROVISIONING , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
#define SL_ENT_EAP_METHOD_FAST_NO_PROVISIONING      EAPMETHOD(FAST  , FAST_NO_PROVISIONING     , CC31XX_DEFAULT_CIPHER , CC31XX_DEFAULT_CIPHER)
 
#define SL_LONG_PREAMBLE			       (0)
#define SL_SHORT_PREAMBLE			       (1)

#define SL_RAW_RF_TX_PARAMS_CHANNEL_SHIFT  (0)
#define SL_RAW_RF_TX_PARAMS_RATE_SHIFT     (6)
#define SL_RAW_RF_TX_PARAMS_POWER_SHIFT    (11)
#define SL_RAW_RF_TX_PARAMS_PREAMBLE_SHIFT (15)

#define SL_RAW_RF_TX_PARAMS(chan,rate,power,preamble) \
	((chan << SL_RAW_RF_TX_PARAMS_CHANNEL_SHIFT) | \
	(rate << SL_RAW_RF_TX_PARAMS_RATE_SHIFT) | \
	(power << SL_RAW_RF_TX_PARAMS_POWER_SHIFT) | \
	(preamble << SL_RAW_RF_TX_PARAMS_PREAMBLE_SHIFT))


/* wlan config application IDs */
#define SL_WLAN_CFG_AP_ID                    (0)
#define SL_WLAN_CFG_GENERAL_PARAM_ID         (1)
#define SL_WLAN_CFG_P2P_PARAM_ID 	         (2)

/* wlan AP Config set/get options */
#define WLAN_AP_OPT_SSID                     (0)
/*#define WLAN_AP_OPT_COUNTRY_CODE           (1) */
#define WLAN_AP_OPT_BEACON_INT               (2)
#define WLAN_AP_OPT_CHANNEL                  (3)
#define WLAN_AP_OPT_HIDDEN_SSID              (4)
#define WLAN_AP_OPT_DTIM_PERIOD              (5)
#define WLAN_AP_OPT_SECURITY_TYPE            (6)
#define WLAN_AP_OPT_PASSWORD                 (7)
#define WLAN_AP_OPT_WPS_STATE                (8)
#define WLAN_GENERAL_PARAM_OPT_COUNTRY_CODE  (9)
#define WLAN_GENERAL_PARAM_OPT_STA_TX_POWER  (10)
#define WLAN_GENERAL_PARAM_OPT_AP_TX_POWER   (11)

#define WLAN_P2P_OPT_DEV_NAME   			 (12)
#define WLAN_P2P_OPT_DEV_TYPE   			 (13)
#define WLAN_P2P_OPT_CHANNEL_N_REGS			 (14)
#define WLAN_GENERAL_PARAM_OPT_INFO_ELEMENT  (16)
#define WLAN_GENERAL_PARAM_OPT_SCAN_PARAMS   (18)      /* change the scan channels and RSSI threshold using this configuration option */

/* SmartConfig CIPHER options */
#define SMART_CONFIG_CIPHER_SFLASH           (0)      /* password is not delivered by the application. The Simple Manager should */
                                        		      /* check if the keys are stored in the Flash.                              */
#define SMART_CONFIG_CIPHER_AES              (1)      /* AES (other types are not supported)                                     */
#define SMART_CONFIG_CIPHER_NONE             (0xFF)   /* do not check in the flash                                               */


#define SL_POLICY_CONNECTION                 (0x10)
#define SL_POLICY_SCAN                       (0x20)
#define SL_POLICY_PM                         (0x30)
#define SL_POLICY_P2P		                 (0x40)

#define VAL_2_MASK(position,value)           ((1 & (value))<<(position))
#define MASK_2_VAL(position,mask)            (((1 << position) & (mask)) >> (position))

#define SL_CONNECTION_POLICY(Auto,Fast,Open,anyP2P,autoSmartConfig)                (VAL_2_MASK(0,Auto) | VAL_2_MASK(1,Fast) | VAL_2_MASK(2,Open) | VAL_2_MASK(3,anyP2P) | VAL_2_MASK(4,autoSmartConfig))
#define SL_SCAN_POLICY_EN(policy)            (MASK_2_VAL(0,policy))
#define SL_SCAN_POLICY(Enable)               (VAL_2_MASK(0,Enable))


#define SL_NORMAL_POLICY                    (0)
#define SL_LOW_LATENCY_POLICY               (1)
#define SL_LOW_POWER_POLICY                 (2)
#define SL_ALWAYS_ON_POLICY                 (3)
#define SL_LONG_SLEEP_INTERVAL_POLICY	    (4)

#define SL_P2P_ROLE_NEGOTIATE	            (3)
#define SL_P2P_ROLE_GROUP_OWNER             (15)
#define SL_P2P_ROLE_CLIENT		            (0)

#define SL_P2P_NEG_INITIATOR_ACTIVE		    (0)
#define SL_P2P_NEG_INITIATOR_PASSIVE	    (1)
#define SL_P2P_NEG_INITIATOR_RAND_BACKOFF   (2)

#define POLICY_VAL_2_OPTIONS(position,mask,policy)    ((mask & policy) << position )

#define SL_P2P_POLICY(p2pNegType,p2pNegInitiator)   (POLICY_VAL_2_OPTIONS(0,0xF,(p2pNegType > SL_P2P_ROLE_GROUP_OWNER ? SL_P2P_ROLE_GROUP_OWNER : p2pNegType)) | \
													 POLICY_VAL_2_OPTIONS(4,0x1,(p2pNegType > SL_P2P_ROLE_GROUP_OWNER ?				1			: 0			)) | \
													 POLICY_VAL_2_OPTIONS(5,0x3, p2pNegInitiator))


/* Info elements */

#define INFO_ELEMENT_DEFAULT_ID              (0) /* 221 will be used */

/* info element size is up to 252 bytes (+ 3 bytes of OUI). */
#define INFO_ELEMENT_MAX_SIZE                (252)

/* For AP - the total length of all info elements is 300 bytes (for example - 4 info elements of 75 bytes each) */
#define INFO_ELEMENT_MAX_TOTAL_LENGTH_AP     (300)
/* For P2P - the total length of all info elements is 150 bytes (for example - 4 info elements of 40 bytes each) */
#define INFO_ELEMENT_MAX_TOTAL_LENGTH_P2P_GO (160)

#define INFO_ELEMENT_AP_ROLE                 (0)
#define INFO_ELEMENT_P2P_GO_ROLE             (1)

/* we support up to 4 info elements per Role. */
#define MAX_PRIVATE_INFO_ELEMENTS_SUPPROTED  (4)

#define INFO_ELEMENT_DEFAULT_OUI_0           (0x08)
#define INFO_ELEMENT_DEFAULT_OUI_1           (0x00)
#define INFO_ELEMENT_DEFAULT_OUI_2           (0x28)

#define INFO_ELEMENT_DEFAULT_OUI             (0x000000)  /* 08, 00, 28 will be used */

/*********************************************************************************************/
/* Stucture/Enum declarations                                                                */
/*********************************************************************************************/

typedef enum
{
    RATE_1M         = 1,
    RATE_2M         = 2,
    RATE_5_5M       = 3,
    RATE_11M        = 4,
    RATE_6M         = 6,
    RATE_9M         = 7,
    RATE_12M        = 8,
    RATE_18M        = 9,
    RATE_24M        = 10,
    RATE_36M        = 11,
    RATE_48M        = 12,
    RATE_54M        = 13,
    RATE_MCS_0      = 14,
    RATE_MCS_1      = 15,
    RATE_MCS_2      = 16,
    RATE_MCS_3      = 17,
    RATE_MCS_4      = 18,
    RATE_MCS_5      = 19,
    RATE_MCS_6      = 20,
    RATE_MCS_7      = 21,
    MAX_NUM_RATES   = 0xFF
}SlRateIndex_e;

typedef enum {
	DEV_PW_DEFAULT=0,
	DEV_PW_PIN_KEYPAD=1,
	DEV_PW_PUSH_BUTTON=4,
	DEV_PW_PIN_DISPLAY=5
} sl_p2p_dev_password_method;


typedef struct
{
  unsigned long    status;
  unsigned long    ssid_len;
  unsigned char     ssid[32];
  unsigned long    private_token_len;
  unsigned char     private_token[32];
}slSmartConfigStartAsyncResponse_t;

typedef struct
{
  unsigned short    status;
  unsigned short    padding;
}slSmartConfigStopAsyncResponse_t;

typedef struct
{
  unsigned short    status;
  unsigned short    padding;
}slWlanConnFailureAsyncResponse_t;

typedef struct
{
  unsigned char     connection_type;/* 0-STA,3-P2P_CL */
  unsigned char     ssid_len;
  unsigned char     ssid_name[32];
  unsigned char     go_peer_device_name_len;
  unsigned char     go_peer_device_name[32];
  unsigned char     bssid[6];
  unsigned char     reason_code;
  unsigned char     padding[2];
} sl_protocol_wlanConnectAsyncResponse_t;

typedef struct
{
  unsigned char     go_peer_device_name[32];
  unsigned char     mac[6];
  unsigned char     go_peer_device_name_len;
  unsigned char     wps_dev_password_id;
  unsigned char     own_ssid[32];/* relevant for event sta-connected only */
  unsigned char     own_ssid_len;/* relevant for event sta-connected only */
  unsigned char     padding[3];
}slPeerInfoAsyncResponse_t;


typedef union
{
  slSmartConfigStartAsyncResponse_t    smartConfigStartResponse; /*SL_WLAN_SMART_CONFIG_START_EVENT*/
  slSmartConfigStopAsyncResponse_t     smartConfigStopResponse;  /*SL_WLAN_SMART_CONFIG_STOP_EVENT */
  slPeerInfoAsyncResponse_t			       APModeStaConnected;       /* SL_OPCODE_WLAN_STA_CONNECTED - relevant only in AP mode - holds information regarding a new STA connection */   
  slPeerInfoAsyncResponse_t                APModestaDisconnected;    /* SL_OPCODE_WLAN_STA_DISCONNECTED - relevant only in AP mode - holds information regarding a STA disconnection */ 
  sl_protocol_wlanConnectAsyncResponse_t   STAandP2PModeWlanConnected;   /* SL_OPCODE_WLAN_WLANASYNCCONNECTEDRESPONSE - relevant only in STA and P2P mode - holds information regarding a new connection */
  sl_protocol_wlanConnectAsyncResponse_t   STAandP2PModeDisconnected;   /* SL_OPCODE_WLAN_WLANASYNCCONNECTEDRESPONSE - relevant only in STA and P2P mode - holds information regarding a disconnection */
  slPeerInfoAsyncResponse_t                P2PModeDevFound;             /* SL_OPCODE_WLAN_P2P_DEV_FOUND - relevant only in P2P mode */
  slPeerInfoAsyncResponse_t				   P2PModeNegReqReceived;       /* SL_OPCODE_WLAN_P2P_NEG_REQ_RECEIVED - relevant only in P2P mode */
  slWlanConnFailureAsyncResponse_t         P2PModewlanConnectionFailure;   /* SL_OPCODE_WLAN_CONNECTION_FAILED - relevant only in P2P mode */

} SlWlanEventData_u;

typedef struct
{
   unsigned long     Event;
   SlWlanEventData_u        EventData;
} SlWlanEvent_t;


typedef struct 
{
    unsigned long  ReceivedValidPacketsNumber;                     /* sum of the packets that been received OK (include filtered) */
    unsigned long  ReceivedFcsErrorPacketsNumber;                  /* sum of the packets that been dropped due to FCS error */ 
    unsigned long  ReceivedPlcpErrorPacketsNumber;                 /* sum of the packets that been dropped due to PLCP error */
    signed short   AvarageDataCtrlRssi;                            /* average RSSI for all valid data packets received */
    signed short   AvarageMgMntRssi;                               /* average RSSI for all valid management packets received */
    unsigned short  RateHistogram[NUM_OF_RATE_INDEXES];             /* rate histogram for all valid packets received */
    unsigned short  RssiHistogram[SIZE_OF_RSSI_HISTOGRAM];          /* RSSI histogram from -40 until -87 (all below and above\n RSSI will appear in the first and last cells */
    unsigned long  StartTimeStamp;                                 /* the time stamp started collecting the statistics in uSec */
    unsigned long  GetTimeStamp;                                   /* the time stamp called the get statistics command */
}SlGetRxStatResponse_t;


typedef struct
{
    unsigned char ssid[MAXIMAL_SSID_LENGTH];
    unsigned char ssid_len;
    unsigned char sec_type;
    unsigned char bssid[SL_BSSID_LENGTH];
    signed   char rssi;
    char          reserved[3];
}Sl_WlanNetworkEntry_t;

 
typedef struct 
{
    unsigned char   Type;
    char*           Key;
    unsigned char   KeyLen;
}SlSecParams_t;
 
typedef struct 
{
    char*           User;
    unsigned char   UserLen;
    char*           AnonUser;
    unsigned char   AnonUserLen;
    unsigned char   CertIndex;  /* not supported */
    unsigned long   EapMethod;
}SlSecParamsExt_t;

typedef struct 
{
    char            User[32];
    unsigned char   UserLen;
    char            AnonUser[32];
    unsigned char   AnonUserLen;
    unsigned char   CertIndex;  //not supported
    unsigned long   EapMethod;
}SlGetSecParamsExt_t;

typedef enum
{
    ROLE_STA   =   0,
    ROLE_AP    =   2,
    ROLE_P2P     =   3,
    ROLE_STA_ERR =  -1,         /* Failure to load MAC\PHY in STA role */
    ROLE_AP_ERR  =  -ROLE_AP,   /* Failure to load MAC\PHY in AP role */
    ROLE_P2P_ERR =  -ROLE_P2P   /* Failure to load MAC\PHY in P2P role */
}SlWlanMode_t;

typedef struct
{
    unsigned long  G_Channels_mask;
    signed long   rssiThershold;
}slWlanScanParamCommand_t;


typedef struct {
    unsigned char   id;
    unsigned char   oui[3];
    unsigned short  length;
    unsigned char   data[252];
} sl_protocol_InfoElement_t;

typedef struct {
    unsigned char                       index;  /* 0 - MAX_PRIVATE_INFO_ELEMENTS_SUPPROTED */
    unsigned char                       role;   /* bit0: AP = 0, GO = 1                    */
    sl_protocol_InfoElement_t   ie;
} sl_protocol_WlanSetInfoElement_t;


/*********************************************************************************************/
/* Function prototypes                                                                       */
/*********************************************************************************************/


/********************************************************************************************/



/*!
    \brief Connect to wlan network as a station
    
    \param[in]      sec_type    security types options: \n
                                - SL_SEC_TYPE_OPEN
                                - SL_SEC_TYPE_WEP
                                - SL_SEC_TYPE_WPA
                                - SL_SEC_TYPE_WPA_ENT
                                - SL_SEC_TYPE_WPS_PBC
                                - SL_SEC_TYPE_WPS_PIN
     
    \param[in]      pName       up to 32 bytes in case of STA the name is the SSID of the Access Point
    \param[in]      NameLen     name length
    \param[in]      pMacAddr    6 bytes for MAC address
    \param[in]      pSecParams  Security parameters (use NULL for SL_SEC_TYPE_OPEN)
    \param[in]      pSecExtParams  Enterprise parameters (set NULL in case Enterprise parameters is not in use)
    
    \return         On success, zero is returned. On error, negative is returned
                    In case error number (-71) is returned, it indicates a connection was activated while the device it running in AP role
    
    \sa             sl_WlanDisconnect        
    \note           belongs to \ref ext_api       
    \warning        bssid alone is not allowed in this version
                    in this version only single enterprise mode could be used
*/ 
#if _SL_INCLUDE_FUNC(sl_WlanConnect)
int sl_WlanConnect(char* pName, int NameLen, unsigned char *pMacAddr, SlSecParams_t* pSecParams , SlSecParamsExt_t* pSecExtParams);
#endif

/*!
    \brief wlan disconnect
    
    Disconnect connection  
     
    \return         0 disconnected done, other already disconnected
    
    \sa             sl_WlanConnect       
    \note           belongs to \ref ext_api       
    \warning     
*/
#if _SL_INCLUDE_FUNC(sl_WlanDisconnect)
int sl_WlanDisconnect(void);
#endif

/*!
    \brief add profile 
    
    When auto start is enabled, the device connects to a
    station from the profiles table. Up to 7 profiles are
    supported. If several profiles configured the device chose
    the highest priority profile, within each priority group,
    device will chose profile based on security policy, signal
    strength, etc parameters. 


    \param[in]      pName          up to 32 bytes in case of STA the name is the 
                                   SSID of the Access Point
                                   in case of P2P the name is the remote device name
    \param[in]      NameLen     name length
    \param[in]      pMacAddr    6 bytes for MAC address
    \param[in]      pSecParams     security parameters - security type 
                                   (SL_SEC_TYPE_OPEN,SL_SEC_TYPE_WEP,SL_SEC_TYPE_WPA,
                                    SL_SEC_TYPE_P2P_PBC,SL_SEC_TYPE_P2P_PIN_KEYPAD,SL_SEC_TYPE_P2P_PIN_DISPLAY, SL_SEC_TYPE_WPA_ENT), key, and key length
                                   SL_SEC_TYPE_WPA_ENT), key, and key length
                                   in case of p2p security type pin the key refers to pin code
    \param[in]      pSecExtParams  enterprise parameters - identity, identity length, 
                                   Anonymous, Anonymous length, CertIndex (not supported,
                                   certificates need to be placed in a specific file ID),
                                   EapMethod.Use NULL in case Enterprise parameters is not in use

    \param[in]      Priority    profile priority. Lowest priority: 0
    \param[in]      Options     Not supported
     
    \return         On success, profile stored index is returned. On error, -1 is returned 


    \sa             sl_WlanProfileGet , sl_WlanProfileDel       
    \note           belongs to \ref ext_api
    \warning        Only one Enterprise profile is supported.
                    Please Note that in case of adding an existing profile (compared by pName,pMACAddr and security type) 
                    the old profile will be deleted and the same index will be returned.


*/
#if _SL_INCLUDE_FUNC(sl_WlanProfileAdd)
int sl_WlanProfileAdd(char* pName, int NameLen, unsigned char *pMacAddr, SlSecParams_t* pSecParams , SlSecParamsExt_t* pSecExtParams, unsigned long  Priority, unsigned long  Options);
#endif

/*!
    \brief get profile 
    
    read profile from the device     
     
    \param[in]      Index          profile stored index, if index does not exists
                                   error is return
    \param[out]     pName          up to 32 bytes, in case of sta mode the name of the Access Point
                                   in case of p2p mode the name of the Remote Device
    \param[out]     pNameLen       name length 
    \param[out]     pMacAddr    6 bytes for MAC address
    \param[out]     pSecParams     security parameters - security type 
                                   (LAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or
                                   WLAN_SEC_WPA2, WLAN_SEC_P2P_PBC, WLAN_SEC_P2P_PIN_KEYPAD or WLAN_SEC_P2P_DISPLAY), key and key length are not 
                                   in case of p2p security type pin the key refers to pin code
                                   return due to security reasons.
    \param[out]     pSecExtParams  enterprise parameters - identity, identity 
                                   length, Anonymous, Anonymous length
                                   CertIndex (not supported), EapMethod.
    \param[out]     Priority       profile priority

    
    
     
    \return         On success, Profile security type is returned (0 or positive number). On error, -1 is 
                    returned      
    
    \sa             sl_WlanProfileAdd , sl_WlanProfileDel       
    \note           belongs to \ref ext_api
    \warning     
*/
#if _SL_INCLUDE_FUNC(sl_WlanProfileGet)
int sl_WlanProfileGet(int Index,char* pName, int *pNameLen, unsigned char *pMacAddr, SlSecParams_t* pSecParams, SlGetSecParamsExt_t* pSecExtParams, unsigned long *pPriority);
#endif

/*!
    \brief Delete WLAN profile
    
    Delete WLAN profile  
     
    \param[in]   index  number of profile to delete   
     
    \return  On success, zero is returned. On error, -1 is 
               returned
    
    \sa   sl_WlanProfileAdd , sl_WlanProfileGet       
    \note           belongs to \ref ext_api
    \warning     
*/
#if _SL_INCLUDE_FUNC(sl_WlanProfileDel)
int sl_WlanProfileDel(int Index);
#endif

/*!
    \brief set policy values
     
    \param[in]      Type      Type of policy to be modified. The Options are:\n 
                              - SL_POLICY_CONNECTION 
                              - SL_POLICY_SCAN 
                              - SL_POLICY_PM
                              - SL_POLICY_P2P
    \param[in]      Policy    The option value which depends on action type
    \param[in]      pVal      An optional value pointer
    \param[in]      ValLen    An optional value length, in bytes
    \return         On success, zero is returned. On error, -1 is 
                    returned   
    \sa             sl_WlanPolicyGet
    \note           belongs to \ref ext_api
    \warning        
    \par            Example: 
    \code
    
    SL_POLICY_CONNECTION type defines three options available to connect the CC31xx device to the AP: \n
    -  If Auto Connect is set, the CC31xx device tries to automatically reconnect to one of its stored profiles, each time the connection fails or the device is rebooted.\n
       To set this option, use sl_WlanPolicySet(SL_POLICY_CONNECTION,SL_CONNECTION_POLICY(1,0,0,0,0),NULL,0)\n
    -  If Fast Connect is set, the CC31xx device tries to establish a fast connection to AP. \n
       To set this option, use sl_WlanPolicySet(SL_POLICY_CONNECTION,SL_CONNECTION_POLICY(0,1,0,0,0),NULL,0)
    -  (relevant for P2P mode only) - If Any P2P is set,  CC31xx device tries to automatically connect to the first P2P device avialable, supporting push button only 
       To set this option, use sl_WlanPolicySet(SL_POLICY_CONNECTION,SL_CONNECTION_POLICY(0,0,0,1,0),NULL,0)
    -  For auto smart config upon restart (any command from Host will end this state) use 
        use sl_WlanPolicySet(SL_POLICY_CONNECTION,SL_CONNECTION_POLICY(0,0,0,0,1),NULL,0)

    SL_POLICY_SCAN defines system scan time interval in case there is no connection. Default interval is 10 minutes. \n
    After settings scan interval, an immediate scan is activated. The next scan will be based on the interval settings. \n
                    -  For example, setting scan interval to 1 minute interval use:
                       unsigned long intervalInSeconds = 60;
               #define SL_SCAN_ENABLE  1
                       sl_WlanPolicySet(SL_POLICY_SCAN,SL_SCAN_ENABLE, (unsigned char *)&intervalInSeconds,sizeof(intervalInSeconds));

                    -  For example, disable scan:
               #define SL_SCAN_DISABLE  0
                       sl_WlanPolicySet(SL_POLICY_SCAN,SL_SCAN_DISABLE,0,0);
     
    SL_POLICY_PM defines a power management policy for Station mode only:
                    -  For setting normal power management policy use sl_WlanPolicySet(SL_POLICY_PM , SL_NORMAL_POLICY, NULL,0)
                    -  For setting low latency power management policy use sl_WlanPolicySet(SL_POLICY_PM , SL_LOW_LATENCY_POLICY, NULL,0)
                    -  For setting low power management policy use sl_WlanPolicySet(SL_POLICY_PM , SL_LOW_POWER_POLICY, NULL,0)
                    -  For setting always on power management policy use sl_WlanPolicySet(SL_POLICY_PM , SL_ALWAYS_ON_POLICY, NULL,0)
                    -  For setting long sleep interval policy use:
                            unsigned short PolicyBuff[4] = {0,0,800,0}; // PolicyBuff[2] is max sleep time in mSec
                            sl_WlanPolicySet(SL_POLICY_PM , SL_LONG_SLEEP_INTERVAL_POLICY, PolicyBuff,sizeof(PolicyBuff));
     
    SL_POLICY_P2P defines p2p negotiation policy parameters for P2P role:
                    - To set intent negotiation value, set on of the following:
                        SL_P2P_ROLE_NEGOTIATE   - intent 3
                        SL_P2P_ROLE_GROUP_OWNER - intent 15
                        SL_P2P_ROLE_CLIENT      - intent 0
                    - To set negotiation initiator value (initiator policy of first negotiation action frame), set on of the following:
                        SL_P2P_NEG_INITIATOR_ACTIVE
                        SL_P2P_NEG_INITIATOR_PASSIVE
                        SL_P2P_NEG_INITIATOR_RAND_BACKOFF

                    For example: set sl_WlanPolicySet(SL_POLICY_P2P, SL_P2P_POLICY(SL_P2P_ROLE_NEGOTIATE,SL_P2P_NEG_INITIATOR_RAND_BACKOFF),NULL,0);
    \endcode 
*/

#if _SL_INCLUDE_FUNC(sl_WlanPolicySet)
int sl_WlanPolicySet(unsigned char Type , const unsigned char Policy, unsigned char *pVal,unsigned char ValLen);
#endif
/*!
    \brief get policy values
     
    \param[in]      Type     SL_POLICY_CONNECTION, SL_POLICY_SCAN, SL_POLICY_PM \n

    \param[in]      Policy   argument may be set to any value \n

    \param[out]     The returned values, depends on each policy type, will be stored in the allocated buffer pointed by pVal
                    with a maximum buffer length set by the calling function and pointed to by argument *pValLen
     
    \return         On success, zero is returned. On error, -1 is returned   
     
    \sa             sl_WlanPolicySet

    \note           belongs to \ref ext_api

    \warning        The value pointed by the argument *pValLen should be set to a value different from 0 and 
                    greater than the buffer length returned from the SL device. Otherwise, an error will be returned.

*/
#if _SL_INCLUDE_FUNC(sl_WlanPolicyGet)
int sl_WlanPolicyGet(unsigned char Type , unsigned char Policy,unsigned char *pVal,unsigned char *pValLen);
#endif
/*!
    \brief Gets the WLAN scan operation results
    
    Gets scan resaults , gets entry from scan result table
     
    \param[in]   Index - Starting index identifier (range 0-19) for getting scan results
    \param[in]   Count - How many entries to fetch. Max is 20-"Index".
    \param[out]  pEntries - pointer to an allocated Sl_WlanNetworkEntry_t. 
                            the number of array items should match "Count" 
     
    \return  Number of valid networks list items
     
    \sa                
    \note       belongs to \ref ext_api
    \warning    This command do not initiate any active scanning action 
    \par        Example:
    \code       An example of fetching max 10 results:
    
                Sl_WlanNetworkEntry_t netEntries[10];
                int resultsCount = sl_WlanGetNetworkList(0,10,&netEntries[0]);
                for(i=0; i< resultsCount; i++)
                {
                      printf("%s\n",netEntries[i].ssid);
                }
    \endcode
*/
#if _SL_INCLUDE_FUNC(sl_WlanGetNetworkList)
int sl_WlanGetNetworkList(unsigned char Index, unsigned char Count, Sl_WlanNetworkEntry_t *pEntries);
#endif

/*!
    \brief   Start collecting wlan RX statistics, for unlimited time. 
            
    \return  On success, zero is returned. On error, -1 is returned   
    
    \sa     sl_WlanRxStatStop      sl_WlanRxStatGet
    \note   belongs to \ref ext_api        
    \warning  This API is deprecated and should be removed for next release
    \par        Example:
    \code       Getting wlan RX statistics:             

    void RxStatCollectTwice()
    {
        SlGetRxStatResponse_t rxStat;
		int rawSocket;
		char DataFrame[200];
		struct SlTimeval_t timeval;
		timeval.tv_sec =  0;             // Seconds
        timeval.tv_usec = 20000;         // Microseconds. 10000 microseconds resoultion

        sl_WlanRxStatStart();  // set statistics mode

		rawSocket = sl_Socket(SL_AF_RF, SL_SOCK_RAW, eChannel); 
		// set timeout - in case we have no activity for the sepcified channel
        sl_SetSockOpt(rawSocket,SL_SOL_SOCKET,SL_SO_RCVTIMEO, &timeval, sizeof(timeval));    // Enable receive timeout 
        status = sl_Recv(rawSocket, DataFrame, sizeof(DataFrame), 0);

        Sleep(1000); // sleep for 1 sec
        sl_WlanRxStatGet(&rxStat,0); // statisticcs has been cleared upon read
        Sleep(1000); // sleep for 1 sec
        sl_WlanRxStatGet(&rxStat,0); 
        
    }
    \endcode
*/
#if _SL_INCLUDE_FUNC(sl_WlanRxStatStart)
int sl_WlanRxStatStart(void);
#endif


/*!
    \brief    Stop collecting wlan RX statistic, (if previous called sl_WlanRxStatStart)
            
    \return   On success, zero is returned. On error, -1 is returned   
    
    \sa     sl_WlanRxStatStart      sl_WlanRxStatGet
    \note           belongs to \ref ext_api        
    \warning  This API is deprecated and should be removed for next release   
*/
#if _SL_INCLUDE_FUNC(sl_WlanRxStatStop)
int sl_WlanRxStatStop(void);
#endif


/*!
    \brief Get wlan RX statistics. upon calling this command, the statistics counters will be cleared.
            
    \param[in]  Flags should be 0  ( not applicable right now, will be added the future )
    \param[in]  pRxStat a pointer to SlGetRxStatResponse_t filled with Rx statistics results
    \return     On success, zero is returned. On error, -1 is returned   
    
    \sa   sl_WlanRxStatStart  sl_WlanRxStatStop  
    \note           belongs to \ref ext_api        
    \warning     
*/
#if _SL_INCLUDE_FUNC(sl_WlanRxStatGet)
int sl_WlanRxStatGet(SlGetRxStatResponse_t *pRxStat,unsigned long Flags);
#endif


/*!
    \brief Stop Smart Config procedure. Once Smart Config will be stopped,
           Asynchronous event will be received - SL_OPCODE_WLAN_SMART_CONFIG_STOP_ASYNC_RESPONSE.
            
    \param[in]  none
    \param[out] none
    
    \return     0 - if Stop Smart Config is about to be executed without errors.
    
    \sa         sl_WlanSmartConfigStart         
    \note           belongs to \ref ext_api        
    \warning      This API is deprecated and should be removed for next release   
    
*/
#if _SL_INCLUDE_FUNC(sl_WlanSmartConfigStop)
int sl_WlanSmartConfigStop(void);
#endif



/*!
    \brief  Start Smart Config procedure. The target of the procedure is to let the                      \n
            device to gain the network parameters: SSID and Password (if network is secured)             \n
            and to connect to it once located in the network range.                                      \n
            An external application should be used on a device connected to any mobile network.          \n
            The external application will transmit over the air the network parameters in secured manner.\n
            The Password may be decrypted using a Key.                                                   \n
            The decryption method may be decided in the command or embedded in the Flash.                \n
            The procedure can be activated for 1-3 group ID in the range of BIT_0 - BIT_15 where the default group ID id 0 (BIT_0) \n
            Once Smart Config has ended successfully, Asynchronous event will be received -              \n
            SL_OPCODE_WLAN_SMART_CONFIG_START_ASYNC_RESPONSE.                                            \n
            The Event will hold the SSID and an extra field that might have been delivered as well (i.e. - device name)

    \param[in]  groupIdBitmask - each bit represent a group ID that should be searched.
                                 The Default group ID id BIT_0. 2 more group can be searched 
                                 in addition. The range is BIT_0 - BIT_15.
    \param[in]   chiper - 0: check in flash, 1 - AES, 0xFF - do not check in flash
    \param[in]  publicKeyLen - public key len (used for the default group ID - BIT_0)
    \param[in]  group1KeyLen - group ID1 length
    \param[in]  group2KeyLen - group ID2 length
    \param[in]  publicKey    - public key (used for the default group ID - BIT_0)
    \param[in]  group1Key    - group ID1 key
    \param[in]  group2Key    - group ID2 key

    \param[out] none
    
    \return     0 - if Smart Config started successfully.
    
    \sa         sl_WlanSmartConfigStop 
    \note           belongs to \ref ext_api        
    \warning     
    \par     
    \code       An example of starting smart Config on group ID's 0 + 1 + 2
    
                sl_WlanSmartConfigStart(7,      //group ID's (BIT_0 | BIT_1 | BIT_2)
                                        1,      //decrypt key by AES method
                                        16,     //decryption key length for group ID0
                                        16,     //decryption key length for group ID1
                                        16,     //decryption key length for group ID2
                                        "Key0Key0Key0Key0", //decryption key for group ID0
                                        "Key1Key1Key1Key1", //decryption key for group ID1
                                        "Key2Key2Key2Key2"  //decryption key for group ID2
                                        );
    \endcode
*/
#if _SL_INCLUDE_FUNC(sl_WlanSmartConfigStart)
int sl_WlanSmartConfigStart(const unsigned long    groupIdBitmask,
                             const unsigned char    cipher,
                             const unsigned char    publicKeyLen,
                             const unsigned char    group1KeyLen,
                             const unsigned char    group2KeyLen,
                             const unsigned char*   publicKey,
                             const unsigned char*   group1Key,
                             const unsigned char*   group2Key);
#endif


/*!
    \brief Wlan set mode

    Setting WLAN mode

    \param[in] mode - WLAN mode to start the CC31xx device. Possible options are:
                    - ROLE_STA - for WLAN station mode
                    - ROLE_AP  - for WLAN AP mode
    
    \return   0 - if mode was set correctly   
    \sa        sl_Start sl_Stop
    \note           belongs to \ref ext_api        
    \warning   After setting the mode the system must be restarted for activating the new mode  
    \par       Example:
    \code
                //Switch from any role  to STA:
                sl_WlanSetMode(ROLE_STA);
                sl_Stop(0);
                sl_Start(NULL,NULL,NULL);
    \endcode
    
    \code       
                //Switch from any role to AP:
                 sl_WlanSetMode(ROLE_AP);                
                 sl_Stop(0);
                 sl_Start(NULL,NULL,NULL);
    \endcode
                 
    \code       
                //Switch from any role to P2P:
                sl_WlanSetMode(ROLE_P2P);
                sl_Stop(0);
                sl_Start(NULL,NULL,NULL);
    \endcode
*/
#if _SL_INCLUDE_FUNC(sl_WlanSetMode)
int sl_WlanSetMode(const unsigned char    mode);
#endif


/*!
    \brief     Internal function for setting WLAN configurations

    \return    On success, zero is returned. On error one of the following error codes  returned:
               - CONF_ERROR                        (-1)
               - CONF_NVMEM_ACCESS_FAILED          (-2)
               - CONF_OLD_FILE_VERSION             (-3)
               - CONF_ERROR_NO_SUCH_COUNTRY_CODE   (-4)

   
    \param[in] ConfigId -  configuration id

    \param[in] ConfigOpt - configurations option

    \param[in] ConfigLen - configurations len

    \param[in] pValues -   configurations values

    \sa         
    \note 
    \warning
    \par   Examples:
    \code
            Set SSID for AP mode example:

            unsigned char  str[33];
            memset(str, 0, 33);
            memcpy(str, ssid, len);  // ssid string of 32 characters
            sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_SSID, strlen(ssid), str);
    \endcode
    \code
           Set Country Code for AP mode example:

           unsigned char* str = (unsigned char *) country;  // string of 2 characters. i.e. - "US"
           sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_COUNTRY_CODE, 2, str); 
    \endcode
    \code
           Set Beacon Interval for AP mode example:
           Beacon interval - should be in the range of [15 - 65535]

           unsigned short  val = interval;
           sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_BEACON_INT, 2, (unsigned char *)&val); 
    \endcode
    \code
           Set channel for AP mode example:

           The channel is dependant on the country code which is set. i.e. for "US" the channel should be in the range of [1-11]
           unsigned char  val = channel;
           sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_CHANNEL, 1, (unsigned char *)&val);
    \endcode
    \code
           Set Hidden SSID Mode for AP mode example:
           hidden options:
               0: disabled
               1: Send empty (length=0) SSID in beacon and ignore probe request for broadcast SSID
               2: Clear SSID (ASCII 0), but keep the original length (this may be required with some 
                  clients that do not support empty SSID) and ignore probe requests for broadcast SSID

               unsigned char  val = hidden;
               sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_HIDDEN_SSID, 1, (unsigned char *)&val);
    \endcode
    \code
           Set DTIM Period for AP mode example:
           DTIM - should be in the range of [1 - 255]
		   
           unsigned char  val = dtim;
           sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_DTIM_PERIOD, 1, (unsigned char *)&val); 
    \endcode
    \code
          Set Security type for AP mode example:
          
          Security options are:
          Open security: SL_SEC_TYPE_OPEN
          WEP security:  SL_SEC_TYPE_WEP
          WPA security:  SL_SEC_TYPE_WPA
 
          unsigned char  val = SL_SEC_TYPE_WPA; 
          sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_SECURITY_TYPE, 1, (unsigned char *)&val);
    \endcode
    \code
         Set Password for for AP mode (for WEP or for WPA) example:
         
         Password - for WPA: 8 - 63 characters
                    for WEP: 5 / 13 characters (ascii)

         unsigned char  str[65]; 
         unsigned short  len = strlen(password); 
         memset(str, 0, 65);
         memcpy(str, password, len);
         sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_PASSWORD, len, (unsigned char *)str);
    \endcode
    \code
         Set STA mode Tx power level example:
          
         Number between 0-15, as dB offset from max power (0 will set MAX power)

         unsigned char  stapower=(unsigned char)power;
         sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_STA_TX_POWER,1,(unsigned char *)&stapower);
    \endcode
    \code
         Set AP mode Tx power level example:
          
         Number between 0-15, as dB offset from max power (0 will set MAX power)

         unsigned char  appower=(unsigned char)power;
         sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_AP_TX_POWER,1,(unsigned char *)&appower);
    \endcode
    \code
         Set P2P Device type example:
         
         Device type, maximum length of 17 characters. Device type is published under P2P I.E, allows to make devices easier to recognize.
         In case no device type is set, the default type is "1-0050F204-1" 

         unsigned char   str[17]; 
         unsigned short  len = strlen(device_type);
         memset(str, 0, 17); 
         memcpy(str, device_type, len);
         sl_WlanSet(SL_WLAN_CFG_P2P_PARAM_ID, WLAN_P2P_OPT_DEV_TYPE, len, str);
    \endcode
    \code
        Set P2P Channels example:
        
        listen channel (either 1/6/11 for 2.4GHz)
        listen regulatory class (81 for 2.4GHz)
        oper channel (either 1/6/11 for 2.4GHz)
        oper regulatory class (81 for 2.4GHz)

        listen channel and regulatory class will determine the device listen channel during p2p find listen phase
        oper channel and regulatory class will determine the operating channel preferred by this device (in case it is group owner this will be the operating channel)
        channels should be one of the social channels (1/6/11). In case no listen/oper channel selected, a random 1/6/11 will be selected.

        unsigned char  str[4];
        str[0] = (unsigned char)11;           // listen channel
        str[1] = (unsigned char)81;		      // listen regulatory class
        str[2] = (unsigned char)6;		      // oper channel
        str[3] = (unsigned char)81;	          // oper regulatory class
        sl_WlanSet(SL_WLAN_CFG_P2P_PARAM_ID, WLAN_P2P_OPT_CHANNEL_N_REGS, 4, str);
    \endcode
    \code
        Set Info Element for AP mode example:
        
        The Application can set up to MAX_PRIVATE_INFO_ELEMENTS_SUPPROTED info elements per Role (AP / P2P GO). 
        To delete an info element use the relevant index and length = 0.
        The Application can set up to MAX_PRIVATE_INFO_ELEMENTS_SUPPROTED to the same role.
        However, for AP - no more than INFO_ELEMENT_MAX_TOTAL_LENGTH_AP bytes can be stored for all info elements.
        For P2P GO - no more than INFO_ELEMENT_MAX_TOTAL_LENGTH_P2P_GO bytes can be stored for all info elements.
           
        sl_protocol_WlanSetInfoElement_t    infoele;                
        infoele.index     = Index;                  // Index of the info element. range: 0 - MAX_PRIVATE_INFO_ELEMENTS_SUPPROTED
        infoele.role      = Role;                   // INFO_ELEMENT_AP_ROLE (0) or INFO_ELEMENT_P2P_GO_ROLE (1)
        infoele.ie.id     =  Id;                    // Info element ID. if INFO_ELEMENT_DEFAULT_ID (0) is set, ID will be set to 221.
        // Organization unique ID. If all 3 bytes are zero - it will be replaced with 08,00,28.
        infoele.ie.oui[0] =  Oui0;                  // Organization unique ID first Byte 
        infoele.ie.oui[1] =  Oui1;                  // Organization unique ID second Byte
        infoele.ie.oui[2] =  Oui2;                  // Organization unique ID third Byte
        infoele.ie.length = Len;                    // Length of the info element. must be smaller than 253 bytes
        memset(infoele.ie.data, 0, INFO_ELEMENT_MAX_SIZE);
        if ( Len <= INFO_ELEMENT_MAX_SIZE )
        {
            memcpy(infoele.ie.data, IE, Len);           // Info element. length of the info element is [0-252]
            sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID,WLAN_GENERAL_PARAM_OPT_INFO_ELEMENT,sizeof(sl_protocol_WlanSetInfoElement_t),(unsigned char*) &infoele);
        }
        sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID,WLAN_GENERAL_PARAM_OPT_INFO_ELEMENT,sizeof(sl_protocol_WlanSetInfoElement_t),(unsigned char*) &infoele);                 
    \endcode

*/
#if _SL_INCLUDE_FUNC(sl_WlanSet)
int sl_WlanSet(unsigned short ConfigId ,unsigned short ConfigOpt,unsigned short ConfigLen, unsigned char *pValues);
#endif

/*!
    \brief     Internal function for getting WLAN configurations

    \return    On success, zero is returned. On error, -1 is 
               returned
   
    \param[in] ConfigId -  configuration id

    \param[out] pConfigOpt - get configurations option 

    \param[out] pConfigLen - The length of the allocated memory as input, when the
                                        function complete, the value of this parameter would be
                                        the len that actually read from the device. 
                                        If the device return length that is longer from the input 
                                        value, the function will cut the end of the returned structure
                                        and will return SL_ESMALLBUF.


    \param[out] pValues - get configurations values

    \sa         

    \note 

    \warning     

	\par    Examples:
    \code
          Scan params example:
       
          slWlanScanParamCommand_t ScanParamConfig;
          unsigned short Option = WLAN_GENERAL_PARAM_OPT_SCAN_PARAMS;
          unsigned short OptionLen = sizeof(slWlanScanParamCommand_t);
          sl_WlanGet(SL_WLAN_CFG_GENERAL_PARAM_ID ,&Option,&OptionLen,(unsigned char *)&ScanParamConfig);
    \endcode
    \code
           AP tx power example:

           int TXPower = 0;
           unsigned short Option = WLAN_GENERAL_PARAM_OPT_AP_TX_POWER;
           unsigned short OptionLen = sizeof(int);
           sl_WlanGet(SL_WLAN_CFG_GENERAL_PARAM_ID ,&Option,&OptionLen,(unsigned char *)&TXPower);
    \endcode
    \code
		   STA tx power example:
		   
		   int TXPower = 0;
           unsigned short Option = WLAN_GENERAL_PARAM_OPT_STA_TX_POWER;
           unsigned short OptionLen = sizeof(int);
 
           sl_WlanGet(SL_WLAN_CFG_GENERAL_PARAM_ID ,&Option,&OptionLen,(unsigned char *)&TXPower);
    \endcode
    \code
		   Get Device Type example:
		   
           char device_type[18];
           unsigned short len = 18;
           unsigned short config_opt = WLAN_P2P_OPT_DEV_TYPE; 
           sl_WlanGet(SL_WLAN_CFG_P2P_PARAM_ID, &config_opt , &len, (unsigned char*)device_type);
    \endcode
    \code
           Get SSID for AP mode example:
           Get up to 32 characters of SSID
          
           char ssid[32];
           unsigned short len = 32;
           unsigned short  config_opt = WLAN_AP_OPT_SSID;
           sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt , &len, (unsigned char*)ssid);
    \endcode
    \code
           Get Country Code for AP mode example:

           country code - string of 3 characters (i.e.: "US")

           char country[3];
           unsigned short len = 3;
           unsigned short  config_opt = WLAN_GENERAL_PARAM_OPT_COUNTRY_CODE;
           sl_WlanGet(SL_WLAN_CFG_GENERAL_PARAM_ID, &config_opt, &len, (unsigned char*)country);
    \endcode
    \code
           Get Beacon interval example:
           Get beacon interval - 2 bytes short integer

           unsigned short interval;
           unsigned short len = 2;
           unsigned short  config_opt = WLAN_AP_OPT_BEACON_INT;
           sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)&interval);
    \endcode
    \code
           Get channel for AP mode example:

           char channel;
           unsigned short len = 1;
           unsigned short  config_opt = WLAN_AP_OPT_CHANNEL;
           sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)&channel);
    \endcode
    \code
           Get Hidden SSID Mode for AP mode example:
           
           Possible values:
              0: disabled
              1: send empty (length=0) SSID in beacon and ignore probe request for broadcast SSID
              2: Clear SSID (ASCII 0), but keep the original length (this may be required with some 
                 clients that do not support empty SSID) and ignore probe requests for broadcast SSID

          unsigned char hidden;
          unsigned short len = 1;
          unsigned short  config_opt = WLAN_AP_OPT_HIDDEN_SSID;
          sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)&hidden); 
    \endcode
    \code
          Get DTIM Period for AP mode example:

          unsigned char dtim;
          unsigned short len = 1;
          unsigned short  config_opt = WLAN_AP_OPT_DTIM_PERIOD; 
          sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)&dtim);
    \endcode
    \code
         Get Security Type for AP mode example:
         
         The return type is mapped by
         0: OPEN
         1: WEP
         2: WPA
         
         unsigned char sec_type;
         unsigned short len = 1;
         unsigned short  config_opt = WLAN_AP_OPT_SECURITY_TYPE;
         sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)&sec_type);
    \endcode
    \code
         Get Password for for AP mode (for WEP or for WPA):
         Returns password - string, fills up to 64 characters.

         unsigned char password[64];
         unsigned short len = 64;
         memset(password,0,64);
         unsigned short config_opt = WLAN_AP_OPT_PASSWORD;
         sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)password);

    \endcode
    \code
        Get WPS Mode for for AP mode example:
        Possible values:
        state - 0: WPS Disabled
                1: WPS Enabled, not configured
                2: WPS enabled, configured

        unsigned char state;
        unsigned short len = 1;
        unsigned short  config_opt = WLAN_AP_OPT_WPS_STATE;
        sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt, &len, (unsigned char*)&state); 

    \endcode
    \code
       Get P2P Channels example:

       unsigned int listen_channel,listen_reg,oper_channel,oper_reg;
       unsigned short len = 4;
       unsigned short  config_opt = WLAN_P2P_OPT_CHANNEL_N_REGS;
       unsigned char channel_n_regs[4];
       sl_WlanGet(SL_WLAN_CFG_P2P_PARAM_ID, &config_opt, &len, (unsigned char*)channel_n_regs);
       listen_channel = channel_n_regs[0]; 
       listen_reg = channel_n_regs[1];
       oper_channel = channel_n_regs[2];
       oper_reg = channel_n_regs[3]; 
    \endcode
*/

#if _SL_INCLUDE_FUNC(sl_WlanGet)
int sl_WlanGet(unsigned short ConfigId, unsigned short *pConfigOpt,unsigned short *pConfigLen, unsigned char *pValues);
#endif
/*

 Close the Doxygen group.
 @}

 */


#ifdef  __cplusplus
}
#endif /*  __cplusplus */

#endif	/*  __WLAN_H__ */
