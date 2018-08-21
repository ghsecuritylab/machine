/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/*
** $Id: //Department/DaVinci/TRUNK/MT6620_5931_WiFi_Driver/include/mgmt/rsn.h#8 $
*/

/*! \file   rsn.h
    \brief  The wpa/rsn related define, macro and structure are described here.
*/




#ifndef _RSN_H
#define _RSN_H

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/

/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/
/* ----- Definitions for Cipher Suite Selectors ----- */
#define RSN_CIPHER_SUITE_USE_GROUP_KEY  0x00AC0F00
#define RSN_CIPHER_SUITE_WEP40          0x01AC0F00
#define RSN_CIPHER_SUITE_TKIP           0x02AC0F00
#define RSN_CIPHER_SUITE_CCMP           0x04AC0F00
#define RSN_CIPHER_SUITE_WEP104         0x05AC0F00

#define WPA_CIPHER_SUITE_NONE           0x00F25000
#define WPA_CIPHER_SUITE_WEP40          0x01F25000
#define WPA_CIPHER_SUITE_TKIP           0x02F25000
#define WPA_CIPHER_SUITE_CCMP           0x04F25000
#define WPA_CIPHER_SUITE_WEP104         0x05F25000

/* ----- Definitions for Authentication and Key Management Suite Selectors ----- */
#define RSN_AKM_SUITE_NONE              0x00AC0F00
#define RSN_AKM_SUITE_802_1X            0x01AC0F00
#define RSN_AKM_SUITE_PSK               0x02AC0F00

#define WPA_AKM_SUITE_NONE              0x00F25000
#define WPA_AKM_SUITE_802_1X            0x01F25000
#define WPA_AKM_SUITE_PSK               0x02F25000

#define ELEM_ID_RSN_LEN_FIXED           20  /* The RSN IE len for associate request */

#define ELEM_ID_WPA_LEN_FIXED           22  /* The RSN IE len for associate request */

#define MASK_RSNIE_CAP_PREAUTH          BIT(0)

#define GET_SELECTOR_TYPE(x)           ((UINT_8)(((x) >> 24) & 0x000000FF))
#define SET_SELECTOR_TYPE(x, y)         x = (((x) & 0x00FFFFFF) | (((UINT_32)(y) << 24) & 0xFF000000))

#define AUTH_CIPHER_CCMP                0x00000008

/* Cihpher suite flags */
#define CIPHER_FLAG_NONE                        0x00000000
#define CIPHER_FLAG_WEP40                       0x00000001 /* BIT 1 */
#define CIPHER_FLAG_TKIP                        0x00000002 /* BIT 2 */
#define CIPHER_FLAG_CCMP                        0x00000008 /* BIT 4 */
#define CIPHER_FLAG_WEP104                      0x00000010 /* BIT 5 */
#define CIPHER_FLAG_WEP128                      0x00000020 /* BIT 6 */

#define WAIT_TIME_IND_PMKID_CANDICATE_SEC       6 /* seconds */
#define TKIP_COUNTERMEASURE_SEC                 60 /* seconds */

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/

/* Flags for PMKID Candidate list structure */
#define EVENT_PMKID_CANDIDATE_PREAUTH_ENABLED   0x01

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/
#define RSN_IE(fp)              ((P_RSN_INFO_ELEM_T) fp)
#define WPA_IE(fp)              ((P_WPA_INFO_ELEM_T) fp)


/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
BOOLEAN
rsnParseRsnIE(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_RSN_INFO_ELEM_T prInfoElem,
    OUT P_RSN_INFO_T      prRsnInfo
);

BOOLEAN
rsnParseWpaIE(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_WPA_INFO_ELEM_T prInfoElem,
    OUT P_RSN_INFO_T      prWpaInfo
);

BOOLEAN
rsnSearchSupportedCipher(
    IN  P_ADAPTER_T       prAdapter,
    IN  UINT_32           u4Cipher,
    OUT PUINT_32          pu4Index
);

BOOLEAN
rsnSearchAKMSuite(
    IN  P_ADAPTER_T       prAdapter,
    IN  UINT_32           u4AkmSuite,
    OUT PUINT_32          pu4Index
);

BOOLEAN
rsnPerformPolicySelection(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_BSS_DESC_T      prBss
);

VOID
rsnGenerateWpaNoneIE(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_MSDU_INFO_T     prMsduInfo
);

VOID
rsnGenerateWPAIE(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_MSDU_INFO_T     prMsduInfo
);

VOID
rsnGenerateRSNIE(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_MSDU_INFO_T     prMsduInfo
);

BOOLEAN
rsnParseCheckForWFAInfoElem(
    IN  P_ADAPTER_T       prAdapter,
    IN  PUINT_8           pucBuf,
    OUT PUINT_8           pucOuiType,
    OUT PUINT_16          pu2SubTypeVersion
);

#if CFG_SUPPORT_AAA
void
rsnParserCheckForRSNCCMPPSK(
    P_ADAPTER_T           prAdapter,
    P_RSN_INFO_ELEM_T     prIe,
    PUINT_16              pu2StatusCode
);
#endif

VOID
rsnTkipHandleMICFailure(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_STA_RECORD_T    prSta,
    IN  BOOLEAN           fgErrorKeyType
);

VOID
rsnSelectPmkidCandidateList(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_BSS_DESC_T      prBssDesc
);

VOID
rsnUpdatePmkidCandidateList(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_BSS_DESC_T      prBssDesc
);

BOOLEAN
rsnSearchPmkidEntry(
    IN  P_ADAPTER_T       prAdapter,
    IN  PUINT_8           pucBssid,
    OUT PUINT_32          pu4EntryIndex
);

BOOLEAN
rsnCheckPmkidCandicate(
    IN  P_ADAPTER_T       prAdapter
);

VOID
rsnCheckPmkidCache(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_BSS_DESC_T      prBss
);

VOID
rsnGeneratePmkidIndication(
    IN  P_ADAPTER_T       prAdapter
);

VOID
rsnIndicatePmkidCand(
    IN  P_ADAPTER_T       prAdapter,
    IN  UINT_32           u4Parm
);
#if CFG_SUPPORT_WPS2
VOID
rsnGenerateWSCIE(
    IN  P_ADAPTER_T       prAdapter,
    IN  P_MSDU_INFO_T     prMsduInfo
);
#endif

/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif /* _RSN_H */

