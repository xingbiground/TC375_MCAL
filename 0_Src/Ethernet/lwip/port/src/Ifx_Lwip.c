/**
 * \file Ifx_Lwip.c
 * \brief Source file of lwIP port to TriCore
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
//lin #include <Cpu/Std/Ifx_Types.h>
#include "IfxGeth_reg.h"
#include "Std_Types.h"
#include "Eth.h"
#include "Ifx_Lwip.h"
#include "lwipopts.h"
#include "Ifx_Netif.h"
#include "IfxGeth_Phy_Dp83825i.h"
#include <string.h>
#include <stdarg.h>


/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define IFX_LWIP_TIMER_TICK_MS      (1U)    // number of timer ticks per millisecond

#define IFX_LWIP_ARP_PERIOD         (ARP_TMR_INTERVAL / IFX_LWIP_TIMER_TICK_MS)
#define IFX_LWIP_TCP_FAST_PERIOD    (TCP_FAST_INTERVAL / IFX_LWIP_TIMER_TICK_MS)
#define IFX_LWIP_TCP_SLOW_PERIOD    (TCP_SLOW_INTERVAL / IFX_LWIP_TIMER_TICK_MS)
#define IFX_LWIP_DHCP_COARSE_PERIOD (DHCP_COARSE_TIMER_MSECS / IFX_LWIP_TIMER_TICK_MS)
#define IFX_LWIP_DHCP_FINE_PERIOD   (DHCP_FINE_TIMER_MSECS / IFX_LWIP_TIMER_TICK_MS)
#define IFX_LWIP_LINK_PERIOD        (100U / IFX_LWIP_TIMER_TICK_MS) /* 100 ms */

#define IFX_LWIP_FLAG_ARP           (1U << 1)
#define IFX_LWIP_FLAG_TCP_FAST      (1U << 2)
#define IFX_LWIP_FLAG_TCP_SLOW      (1U << 3)
#define IFX_LWIP_FLAG_LINK          (1U << 4)
#define IFX_LWIP_FLAG_DHCP_COARSE   (1U << 5)
#define IFX_LWIP_FLAG_DHCP_FINE     (1U << 6)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
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

volatile uint32 g_TickCount_1ms;
Ifx_Lwip    g_Lwip;
// IfxGeth_Eth g_IfxGeth;
// uint32 isrTxCount=0;
// uint32 isrRxCount=0;
// uint8 channel0TxBuffer1[IFXGETH_MAX_TX_DESCRIPTORS][IFXGETH_MAX_TX_BUFFER_SIZE];
// uint8 channel0RxBuffer1[IFXGETH_MAX_RX_DESCRIPTORS][IFXGETH_MAX_RX_BUFFER_SIZE];


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

#define Ifx_Lwip_timerIncr(var, PERIOD, FLAG) \
    {                                         \
        var += 1;                             \
        if (var >= PERIOD)                    \
        {                                     \
            var         = 0;                  \
            timerFlags |= FLAG;               \
        }                                     \
    }

/** \brief Timer interrupt callback */
void Ifx_Lwip_onTimerTick(void)
{
    Ifx_Lwip *lwip       = &g_Lwip;
    uint16    timerFlags = lwip->timerFlags;

    Ifx_Lwip_timerIncr(lwip->timer.arp, IFX_LWIP_ARP_PERIOD, IFX_LWIP_FLAG_ARP);

    Ifx_Lwip_timerIncr(lwip->timer.tcp_fast, IFX_LWIP_TCP_FAST_PERIOD, IFX_LWIP_FLAG_TCP_FAST);
    Ifx_Lwip_timerIncr(lwip->timer.tcp_slow, IFX_LWIP_TCP_SLOW_PERIOD, IFX_LWIP_FLAG_TCP_SLOW);

#if LWIP_DHCP
    Ifx_Lwip_timerIncr(lwip->timer.dhcp_coarse, IFX_LWIP_DHCP_COARSE_PERIOD, IFX_LWIP_FLAG_DHCP_COARSE);
    Ifx_Lwip_timerIncr(lwip->timer.dhcp_fine, IFX_LWIP_DHCP_FINE_PERIOD, IFX_LWIP_FLAG_DHCP_FINE);
#endif

    Ifx_Lwip_timerIncr(lwip->timer.link, IFX_LWIP_LINK_PERIOD, IFX_LWIP_FLAG_LINK);

    lwip->timerFlags = timerFlags;
}


/** \brief Polling the ETH receive event flags */
void Ifx_Lwip_pollReceiveFlags(void)
{
    /**
     * We are assuming that the only interrupt source is an incoming packet
     */
    //while (ethernetif_tc29x_timerFlags_interrupt())
    {
        ifx_netif_input(&g_Lwip.netif);
    }
}

#if LWIP_NETIF_EXT_STATUS_CALLBACK
static netif_ext_callback_t g_extCallback;

void netif_state_changed(struct netif* netif, netif_nsc_reason_t reason, const netif_ext_callback_args_t* args) {
    if(reason | LWIP_NSC_IPV4_ADDRESS_CHANGED) {
        LWIP_DEBUGF(NETIF_DEBUG | LWIP_DBG_TRACE | LWIP_DBG_STATE, ("netif: new ip address assigned: %"U16_F".%"U16_F".%"U16_F".%"U16_F"\n",
                        ip4_addr1_16(netif_ip4_addr(netif)),
                        ip4_addr2_16(netif_ip4_addr(netif)),
                        ip4_addr3_16(netif_ip4_addr(netif)),
                        ip4_addr4_16(netif_ip4_addr(netif))));
    }

}
#endif

//________________________________________________________________________________________
// INITIALIZATION FUNCTION

/** \brief LWIP initialization function
 *
 * The followings are executed: */
void Ifx_Lwip_init(eth_addr_t ethAddr)
{
    ip_addr_t default_ipaddr, default_netmask, default_gw;
    IP4_ADDR(&default_gw, 0,0,0,0);
    IP4_ADDR(&default_ipaddr, 192,168,8,8);
    IP4_ADDR(&default_netmask, 255,255,255,0);

    LWIP_DEBUGF(IFX_LWIP_DEBUG, ("Ifx_Lwip_init start!\n"));

    /** - initialise LWIP (lwip_init()) */
    lwip_init();

    /** - initialise and add a \ref netif */
    g_Lwip.eth_addr = ethAddr;
    netif_add(&g_Lwip.netif, &default_ipaddr, &default_netmask, &default_gw,
        (void *)0, ifx_netif_init, ethernet_input);
    netif_set_default(&g_Lwip.netif);
    netif_set_up(&g_Lwip.netif);

#if LWIP_NETIF_HOSTNAME
    g_Lwip.netif.hostname = BOARDNAME;
#endif

#if LWIP_DHCP
    /** - assign \ref dhcp to \ref netif */
    dhcp_set_struct(&g_Lwip.netif, &g_Lwip.dhcp);

    /* we start the dhcp always here also when we don't have a link here */
    dhcp_start(&g_Lwip.netif);
#endif

#if LWIP_NETIF_EXT_STATUS_CALLBACK
    netif_add_ext_callback(&g_extCallback, netif_state_changed);
#endif
    LWIP_DEBUGF(IFX_LWIP_DEBUG, ("Ifx_Lwip_init end!\n"));
}

/** Returns the current time in milliseconds,
 * may be the same as sys_jiffies or at least based on it. */
inline u32_t sys_now(void)
{
	return g_TickCount_1ms;
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

