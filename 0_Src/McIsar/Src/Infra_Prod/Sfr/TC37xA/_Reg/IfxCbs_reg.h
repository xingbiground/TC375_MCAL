/**
 * \file IfxCbs_reg.h
 * \brief
 * \copyright Copyright (c) 2021 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC37xPD_UM_V2.0.0.R0
 * Specification: TC3xx User Manual V2.0.0
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Cbs_Registers_Cfg Cbs address
 * \ingroup IfxSfr_Cbs_Registers
 * 
 * \defgroup IfxSfr_Cbs_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Cbs_Registers_Cfg
 *
 * \defgroup IfxSfr_Cbs_Registers_Cfg_Cbs 2-CBS
 * \ingroup IfxSfr_Cbs_Registers_Cfg
 *
 *
 */
#ifndef IFXCBS_REG_H
#define IFXCBS_REG_H 1
/******************************************************************************/
#include "IfxCbs_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Cbs_Registers_Cfg_BaseAddress
 * \{  */

/** \brief CBS object */
#define MODULE_CBS /*lint --e(923, 9078)*/ ((*(Ifx_CBS*)0xF0000400u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Cbs_Registers_Cfg_Cbs
 * \{  */
/** \brief 8, Module Identification Register */
#define CBS_JDPID /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_JDPID*)0xF0000408u)

/** \brief C, OCDS Interface Mode Register */
#define CBS_OIFM /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OIFM*)0xF000040Cu)

/** \brief 10, TG Input Pins Routing */
#define CBS_TIPR /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TIPR*)0xF0000410u)

/** \brief 14, TG Output Pins Routing */
#define CBS_TOPR /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TOPR*)0xF0000414u)

/** \brief 18, TG Output Pins Pulse Stretcher */
#define CBS_TOPPS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TOPPS*)0xF0000418u)

/** \brief 1C, TG Capture for TG Input Pins */
#define CBS_TCIP /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCIP*)0xF000041Cu)

/** \brief 20, TG Routing for CPU0 */
#define CBS_TRC0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xF0000420u)

/** \brief 24, TG Routing for CPU1 */
#define CBS_TRC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xF0000424u)

/** \brief 28, TG Routing for CPU2 */
#define CBS_TRC2 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xF0000428u)

/** \brief 2C, TG Routing for CPU3 */
#define CBS_TRC3 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xF000042Cu)

/** \brief 30, TG Routing for CPU4 */
#define CBS_TRC4 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xF0000430u)

/** \brief 34, TG Routing for CPU5 */
#define CBS_TRC5 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRC*)0xF0000434u)

/** \brief 38, TG Routing for HSMControl */
#define CBS_TRHSM /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRHSM*)0xF0000438u)

/** \brief 3C, TG Routing for MCDS Control */
#define CBS_TRMC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRMC*)0xF000043Cu)

/** \brief 40, TG Line Counter Control */
#define CBS_TLCC0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCC*)0xF0000440u)

/** \brief 44, TG Line Counter Control */
#define CBS_TLCC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCC*)0xF0000444u)

/** \brief 50, TG Line Counter Value */
#define CBS_TLCV0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCV*)0xF0000450u)

/** \brief 54, TG Line Counter Value */
#define CBS_TLCV1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCV*)0xF0000454u)

/** \brief 60, TG Routing for Special Signals */
#define CBS_TRSS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRSS*)0xF0000460u)

/** \brief 64, JTAGDevice Identification Register */
#define CBS_JTAGID /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_JTAGID*)0xF0000464u)

/** \brief 68, Communication Mode Data Register */
#define CBS_COMDATA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_COMDATA*)0xF0000468u)

/** \brief 6C, IOClientStatus and Control Register */
#define CBS_IOSR /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_IOSR*)0xF000046Cu)

/** \brief 70, TG Line State */
#define CBS_TLS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLS*)0xF0000470u)

/** \brief 74, TG Capture for TG Lines */
#define CBS_TCTL /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCTL*)0xF0000474u)

/** \brief 78, OCDS Enable Control Register */
#define CBS_OEC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OEC*)0xF0000478u)

/** \brief 7C, OSCU Control Register */
#define CBS_OCNTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OCNTRL*)0xF000047Cu)

/** \brief 80, OSCUStatus Register */
#define CBS_OSTATE /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_OSTATE*)0xF0000480u)

/** \brief 84, Internal Mode Status and Control Register */
#define CBS_INTMOD /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_INTMOD*)0xF0000484u)

/** \brief 88, Internally Controlled Trace Source Register */
#define CBS_ICTSA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ICTSA*)0xF0000488u)

/** \brief 8C, Internally Controlled Trace Destination Register */
#define CBS_ICTTA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ICTTA*)0xF000048Cu)

/** \brief 90, TG Line Control */
#define CBS_TLC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLC*)0xF0000490u)

/** \brief 94, TG Line 1 Suspend Targets */
#define CBS_TL1ST /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TL1ST*)0xF0000494u)

/** \brief 98, TG Line Capture and Hold Enable */
#define CBS_TLCHE /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCHE*)0xF0000498u)

/** \brief 9C, TG Line Capture and Hold Clear */
#define CBS_TLCHS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLCHS*)0xF000049Cu)

/** \brief A0, Set Trigger to Host Register */
#define CBS_TRIGS /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIGS*)0xF00004A0u)

/** \brief A4, Clear Trigger to Host Register */
#define CBS_TRIGC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIGC*)0xF00004A4u)

/** \brief A8, TG Line Timer */
#define CBS_TLT /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLT*)0xF00004A8u)

/** \brief AC, TG Lines for Trigger to Host */
#define CBS_TLTTH /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TLTTH*)0xF00004ACu)

/** \brief B0, TG Capture for Cores - BRKOUT */
#define CBS_TCCB /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCCB*)0xF00004B0u)

/** \brief B4, TG Capture for Cores - HALT */
#define CBS_TCCH /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCCH*)0xF00004B4u)

/** \brief B8, TG Capture for OTGB0/1 */
#define CBS_TCTGB /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCTGB*)0xF00004B8u)

/** \brief BC, TG Capture for MCDS */
#define CBS_TCM /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TCM*)0xF00004BCu)

/** \brief C0, TG Routing Events of CPU0 */
#define CBS_TREC0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xF00004C0u)

/** \brief C4, TG Routing Events of CPU1 */
#define CBS_TREC1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xF00004C4u)

/** \brief C8, TG Routing Events of CPU2 */
#define CBS_TREC2 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xF00004C8u)

/** \brief CC, TG Routing Events of CPU3 */
#define CBS_TREC3 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xF00004CCu)

/** \brief D0, TG Routing Events of CPU4 */
#define CBS_TREC4 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xF00004D0u)

/** \brief D4, TG Routing Events of CPU5 */
#define CBS_TREC5 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TREC*)0xF00004D4u)

/** \brief DC, TG Routing for MCDS Triggers */
#define CBS_TRMT /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRMT*)0xF00004DCu)

/** \brief E0, TG Routing for OTGBi Bits [7:0] */
#define CBS_TRTGB0_L /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_L*)0xF00004E0u)
/** Alias (User Manual Name) for CBS_TRTGB0_L.
* To use register names with standard convension, please use CBS_TRTGB0_L.
*/
#define CBS_TRTGB0L (CBS_TRTGB0_L)

/** \brief E4, TG Routing for OTGBi Bits [15:8] */
#define CBS_TRTGB0_H /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_H*)0xF00004E4u)
/** Alias (User Manual Name) for CBS_TRTGB0_H.
* To use register names with standard convension, please use CBS_TRTGB0_H.
*/
#define CBS_TRTGB0H (CBS_TRTGB0_H)

/** \brief E8, TG Routing for OTGBi Bits [7:0] */
#define CBS_TRTGB1_L /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_L*)0xF00004E8u)
/** Alias (User Manual Name) for CBS_TRTGB1_L.
* To use register names with standard convension, please use CBS_TRTGB1_L.
*/
#define CBS_TRTGB1L (CBS_TRTGB1_L)

/** \brief EC, TG Routing for OTGBi Bits [15:8] */
#define CBS_TRTGB1_H /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRTGB_H*)0xF00004ECu)
/** Alias (User Manual Name) for CBS_TRTGB1_H.
* To use register names with standard convension, please use CBS_TRTGB1_H.
*/
#define CBS_TRTGB1H (CBS_TRTGB1_H)

/** \brief F0, IFS Address Register */
#define CBS_IFSA /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_IFSA*)0xF00004F0u)

/** \brief F4, IFS Control Register */
#define CBS_IFSC /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_IFSC*)0xF00004F4u)

/** \brief 100, Trigger to Host Register 0 */
#define CBS_TRIG0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xF0000500u)

/** \brief 104, Trigger to Host Register 1 */
#define CBS_TRIG1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xF0000504u)

/** \brief 108, Trigger to Host Register 2 */
#define CBS_TRIG2 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xF0000508u)

/** \brief 10C, Trigger to Host Register 3 */
#define CBS_TRIG3 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xF000050Cu)

/** \brief 110, Trigger to Host Register 4 */
#define CBS_TRIG4 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xF0000510u)

/** \brief 114, Trigger to Host Register 5 */
#define CBS_TRIG5 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_TRIG*)0xF0000514u)

/** \brief 1F8, Access Enable Register 1 */
#define CBS_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN1*)0xF00005F8u)

/** \brief 1FC, Access Enable Register 0 */
#define CBS_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_CBS_ACCEN0*)0xF00005FCu)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXCBS_REG_H */
