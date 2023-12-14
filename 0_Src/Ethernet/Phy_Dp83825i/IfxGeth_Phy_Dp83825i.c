/**
 * \file IfxGeth_Eth_Phy_Dp83825i.c
 * \brief Source file of ETHERNET PHY DP83825I communication
 *
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "../Phy_Dp83825i/IfxGeth_Phy_Dp83825i.h"
#include "IfxGeth_regdef.h"

/******************************************************************************/
/*----------------------------------Macros------------------------------------*/
/******************************************************************************/
#define DP83_REGCR          (0x000D)
#define DP83_ADDAR          (0x000E)
#define DP83_NOINC          (0x4000)
#define DP83_TRCVID         (0x0)       /* This depends on hardware layout. */

#define IFXGETH_PHY_DP83825I_MDIO_BMCR     0x00

#define IFXGETH_PHY_DP83825I_MDIO_BMSR     0x01

#define IFXGETH_PHY_DP83825I_MDIO_PHYIDR1  0x02

#define IFXGETH_PHY_DP83825I_MDIO_PHYIDR2  0x03

#define IFXGETH_PHY_DP83825I_MDIO_ANAR     0x04

#define IFXGETH_PHY_DP83825I_MDIO_ALNPAR   0x05

#define IFXGETH_PHY_DP83825I_MDIO_ANER     0x06

#define IFXGETH_PHY_DP83825I_MDIO_PHYSTS   0x10

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

volatile uint32 Ethernet_Phy_Id1;
volatile uint32 Ethernet_Phy_Id2;
volatile boolean Phy_IdRed = FALSE;

#if CPU_WHICH_SERVICE_ETHERNET == 0
    #if defined(__GNUC__)
    #pragma section ".text_cpu0" ax
    #pragma section ".bss_cpu0" awc0
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu0"
    #pragma section farbss  "bss_cpu0"
    #pragma section fardata "data_cpu0"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu0"
    #pragma section DATA ".data_cpu0" ".bss_cpu0" far-absolute RW
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu0"
    #pragma ghs section bss= ".bss_cpu0"
    #pragma ghs section data=".data_cpu0"
    #endif
#elif ((CPU_WHICH_SERVICE_ETHERNET == 1) && (CPU_WHICH_SERVICE_ETHERNET < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu1" ax
    #pragma section ".bss_cpu1" awc1
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu1"
    #pragma section farbss  "bss_cpu1"
    #pragma section fardata "data_cpu1"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu1"
    #pragma section DATA ".data_cpu1" ".bss_cpu1" far-absolute RW
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu1"
    #pragma ghs section bss= ".bss_cpu1"
    #pragma ghs section data=".data_cpu1"
    #endif
#elif ((CPU_WHICH_SERVICE_ETHERNET == 2) && (CPU_WHICH_SERVICE_ETHERNET < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu2" ax
    #pragma section ".bss_cpu2" awc2
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu2"
    #pragma section farbss  "bss_cpu2"
    #pragma section fardata "data_cpu2"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu2"
    #pragma section DATA ".data_cpu2" ".bss_cpu2" far-absolute RW
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu2"
    #pragma ghs section bss= ".bss_cpu2"
    #pragma ghs section data=".data_cpu2"
    #endif
#elif ((CPU_WHICH_SERVICE_ETHERNET == 3) && (CPU_WHICH_SERVICE_ETHERNET < IFXCPU_NUM_MODULES))
	#if defined(__GNUC__)
    #pragma section ".text_cpu3" ax
	#pragma section ".bss_cpu3" awc3
	#endif
	#if defined(__TASKING__)
    #pragma section code    "text_cpu3"
    #pragma section farbss  "bss_cpu3"
    #pragma section fardata "data_cpu3"
	#endif
	#if defined(__DCC__)
    #pragma section CODE ".text_cpu3"
	#pragma section DATA ".data_cpu3" ".bss_cpu3" far-absolute RW
	#endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu3"
    #pragma ghs section bss= ".bss_cpu3"
    #pragma ghs section data=".data_cpu3"
    #endif
#elif ((CPU_WHICH_SERVICE_ETHERNET == 4) && (CPU_WHICH_SERVICE_ETHERNET < IFXCPU_NUM_MODULES))
	#if defined(__GNUC__)
    #pragma section ".text_cpu4" ax
	#pragma section ".bss_cpu4" awc4
	#endif
	#if defined(__TASKING__)
    #pragma section code    "text_cpu4"
    #pragma section farbss  "bss_cpu4"
    #pragma section fardata "data_cpu4"
	#endif
	#if defined(__DCC__)
    #pragma section CODE ".text_cpu4"
	#pragma section DATA ".data_cpu4" ".bss_cpu4" far-absolute RW
	#endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu4"
    #pragma ghs section bss= ".bss_cpu4"
    #pragma ghs section data=".data_cpu4"
    #endif
#elif ((CPU_WHICH_SERVICE_ETHERNET == 5) && (CPU_WHICH_SERVICE_ETHERNET < IFXCPU_NUM_MODULES))
	#if defined(__GNUC__)
    #pragma section ".text_cpu5" ax
	#pragma section ".bss_cpu5" awc5
	#endif
	#if defined(__TASKING__)
    #pragma section code    "text_cpu5"
    #pragma section farbss  "bss_cpu5"
    #pragma section fardata "data_cpu5"
	#endif
	#if defined(__DCC__)
    #pragma section CODE ".text_cpu5"
	#pragma section DATA ".data_cpu5" ".bss_cpu5" far-absolute RW
	#endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu5"
    #pragma ghs section bss= ".bss_cpu5"
    #pragma ghs section data=".data_cpu5"
    #endif
#else
#error "Set CPU_WHICH_SERVICE_ETHERNET to a valid value!"
#endif

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

uint32 IfxGeth_Eth_Phy_Dp83825i_iPhyInitDone = 0;

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/
#if defined(__GNUC__)
    #pragma section // end bss section
#endif

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
void IfxGet_Eth_Phy_Dp83825i_reset(void) {

    Phy_IdRed = TRUE;
}

uint32 IfxGeth_Eth_Phy_Dp83825i_init(void)
{
    // reset PHY
    IfxGeth_Eth_Phy_Dp83825i_write_mdio_reg(0, IFXGETH_PHY_DP83825I_MDIO_BMCR, 0x8000);   // reset
    uint16 value;

    do
    {
        IfxGeth_Eth_Phy_Dp83825i_read_mdio_reg(0, IFXGETH_PHY_DP83825I_MDIO_BMCR, &value);
    } while (value & 0x8000);                                                      // wait for reset to finish

    /* Start Phy activity */
    IfxGeth_Eth_Phy_Dp83825i_write_mdio_reg(0, IFXGETH_PHY_DP83825I_MDIO_BMCR, 0x1200);    // enable auto-negotiation, restart auto-negotiation

    // done
    IfxGeth_Eth_Phy_Dp83825i_iPhyInitDone = 1;

    return 1;
}



uint32 IfxGeth_Eth_Phy_Dp83825i_link_status(void)
{
	Ifx_GETH_MAC_PHYIF_CONTROL_STATUS link_status;
	uint16 value;
	link_status.U = 0;

    if (IfxGeth_Eth_Phy_Dp83825i_iPhyInitDone)
    {
        // We read the phy status register
        IfxGeth_Eth_Phy_Dp83825i_read_mdio_reg(0, IFXGETH_PHY_DP83825I_MDIO_PHYSTS, &value);
        if (!(value & 0x2)) 
            link_status.B.LNKSPEED = 1;
        if (value & 0x4) 
            link_status.B.LNKMOD = 1;
        IfxGeth_Eth_Phy_Dp83825i_read_mdio_reg(0, IFXGETH_PHY_DP83825I_MDIO_BMSR, &value);
        if (value & 0x4) 
            link_status.B.LNKSTS = 1;
    }

    return link_status.U;
}

static uint16 DP83_GetRegDomain(uint16 regAddr)
{
    uint16 regDomain;
    if((regAddr>=0x20) && (regAddr<=0x4D7)){
        regDomain = 0x1F;
    }else if((regAddr>=0x1000) && (regAddr<=0x1016)){
        regDomain = 0x3;
    }else if((regAddr>=0x203C) && (regAddr<=0x203D)){
        regDomain = 0x7;
    }else{
        regDomain = 0;
    }

    return regDomain;
}

Std_ReturnType IfxGeth_Eth_Phy_Dp83825i_read_mdio_reg(uint8 EthCtrl, uint16 regAddr, uint16 *pdata)
{
    Std_ReturnType ret = E_OK;
    uint16 regDomain;

    if(regAddr<=0x1F){
        ret |= Eth_ReadMii(EthCtrl, DP83_TRCVID, (uint8)regAddr, pdata);
    }else{
        regDomain = DP83_GetRegDomain(regAddr);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_REGCR, regDomain);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_ADDAR, regAddr);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_REGCR, regDomain|DP83_NOINC);
        ret |= Eth_ReadMii(EthCtrl, DP83_TRCVID, DP83_ADDAR, pdata);
    }

    return ret;
}


Std_ReturnType IfxGeth_Eth_Phy_Dp83825i_write_mdio_reg(uint8 EthCtrl, uint16 regAddr, uint16 data)
{
    Std_ReturnType ret = E_OK;
    uint16 regDomain;

    if(regAddr<=0x1F){
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, (uint8)regAddr, data);
    }else{
        regDomain = DP83_GetRegDomain(regAddr);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_REGCR, regDomain);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_ADDAR, regAddr);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_REGCR, regDomain|DP83_NOINC);
        ret |= Eth_WriteMii(EthCtrl, DP83_TRCVID, DP83_ADDAR, data);
    }

    return ret;
}

#if defined(__GNUC__)
#pragma section // end text section
#endif
#if defined(__TASKING__)
#pragma section code restore
#pragma section fardata restore
#pragma section farbss restore
#endif
#if defined(__DCC__)
#pragma section CODE
#pragma section DATA RW
#endif
#if defined(__ghs__)
#pragma ghs section text=default
#pragma ghs section data=default
#pragma ghs section bss=default
#endif
