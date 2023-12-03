/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : CanTrcv_17_W9255_Cfg.c                                        **
**                                                                            **
**  VERSION   : 6.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-12-03, 16:05:44       !!!IGNORE-LINE!!!                  **
**                                                                            **
**  GENERATOR : Build b200227-0222           !!!IGNORE-LINE!!!                **
**                                                                            **
**  BSW MODULE DECRIPTION : CanTrcv_17_W9255.bmd                              **
**                                                                            **
**  VARIANT   : Variant PC                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CanTrcv_17_W9255 configuration generated out of ECUC file  **
**                                                                            **
**  SPECIFICATION(S) : Specification of CanTrcv Driver, AUTOSAR Release 4.2.2 **
**                                                  and AUTOSAR Release 4.4.0 **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Includes                                       **
*******************************************************************************/
/* Include CanTrcv header file */
#include "CanTrcv_17_W9255.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED

/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "CanTrcv_17_W9255_MemMap.h"

const CanTrcv_17_W9255_ChannelConfigType CanTrcv_17_W9255_ChannelConfig[CANTRCV_17_W9255_CHANNELS_USED] =
{
  /* CanTransceiver Channel 0 Specific Information */
  {
    /* CAN Transceiver state after driver initialization */
    /* Command to write to MODE_CTRL register when the requested mode is NORMAL */
    0x8108U,

    /* CanTrcvWakeupSource reference */
    CANTRCV_17_W9255_WAKEUP_SOURCE_NOT_CONFIGURED,

    /* CanTrcvPorWakeupSource reference */
    CANTRCV_17_W9255_WAKEUP_SOURCE_NOT_CONFIGURED,

    /* CanTrcvSyserrWakeupSource reference */
    CANTRCV_17_W9255_WAKEUP_SOURCE_NOT_CONFIGURED,

    /* CAN Transceiver Channel Id */
    0U,

    /* Sequence Id used */
    2U,

    /* Spi Channel Id used */
    3U,

    /*
    Wake up by bus status
    - if STD_ON, Bus is used
    - if STD_OFF, Bus is not used
    */
    STD_OFF
  }
};

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED

/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "CanTrcv_17_W9255_MemMap.h"

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_8

/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "CanTrcv_17_W9255_MemMap.h"

/* The following array gives information about the Channel state.
- if the Channel is enabled, the array member holds the Channel inex
- if the Channel is disabled, the array member holds value 0XFF
*/
const uint8 CanTrcv_17_W9255_ChannelUsed[CANTRCV_17_W9255_CHANNELS_CONFIGURED] =
{
  /* CAN Transceiver Channel Id 0 is used */
  0U
};

/* The following array gives information about the PN state.
- if PN is enabled for the Channel, the array member holds the Channel index
- if PN is disabled for the Channel, the array member holds value 0XFF
*/
const uint8 CanTrcv_17_W9255_PnConfigured[CANTRCV_17_W9255_CHANNELS_CONFIGURED] =
{
  /* PN for CAN Transceiver Channel Id 0 is not configured */
  0xFFU
};

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_8

/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "CanTrcv_17_W9255_MemMap.h"

