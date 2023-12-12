/**
 * \file Ifx_Lwip.h
 * \brief Header file of lwIP port to TriCore
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

#ifndef IFX_LWIP_H
#define IFX_LWIP_H

//________________________________________________________________________________________
// INCLUDES

#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/sys.h"
#include "lwip/stats.h"
#include "lwip/snmp.h"
#include "lwip/ip.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include "lwip/priv/tcp_priv.h"
#include "lwip/dhcp.h"
#include "lwip/init.h"
#include "netif/etharp.h"
#include "netif/ppp/pppoe.h"
#include "Eth.h"

//________________________________________________________________________________________
// HELPER MACROS

#define MAC_ADDR(ptr, a, b, c, d, e, f) \
    (ptr)->addr[0] = a;                 \
    (ptr)->addr[1] = b;                 \
    (ptr)->addr[2] = c;                 \
    (ptr)->addr[3] = d;                 \
    (ptr)->addr[4] = e;                 \
    (ptr)->addr[5] = f;

//________________________________________________________________________________________
// TYPEDEFS

/* NOTE: these typedefs are shortcuts to the native LWIP struct types */
typedef struct netif    netif_t;
typedef struct pbuf     pbuf_t;
typedef struct dhcp     dhcp_t;
typedef struct eth_addr eth_addr_t;
typedef struct eth_hdr  eth_hdr_t;
typedef struct ip_addr  ipaddr_t;
typedef struct udp_pcb  udp_pcb_t;
typedef struct tcp_pcb  tcp_pcb_t;

//________________________________________________________________________________________
// DATA STRUCTURES

/** \brief Runtime structure of the AURIX LWIP stack */
typedef struct
{
    netif_t    netif;
#if LWIP_DHCP
    dhcp_t     dhcp;
#endif
    eth_addr_t eth_addr;
    struct
    {
        uint16 arp;
#if LWIP_DHCP
        uint16 dhcp_coarse;
        uint16 dhcp_fine;
#endif
        uint16 tcp_fast;
        uint16 tcp_slow;
        uint16 link;
    }               timer;

    volatile uint16 timerFlags;
} Ifx_Lwip;

/** \brief Configuration structure for the AURIX LWIP stack */
typedef struct
{
    ip_addr_t  ipAddr;      /**< \brief IP address, e.g. : {192,168,220,123} */
    ip_addr_t  netMask;     /**< \brief Network mask, e.g. : {255,255,255,0} */
    ip_addr_t  gateway;     /**< \brief Gateway address, e.g. : {192,168,220,1} */
    eth_addr_t ethAddr;     /**< \brief Ethernet (MAC) address, e.g. : {0x10, 0x20, 0x30, 0x40, 0x50, 0x60} */
} Ifx_Lwip_Config;

#define IFXGETH_HEADER_LENGTH 14 // words
#define IFXGETH_MAX_TX_BUFFER_SIZE (2560+IFXGETH_HEADER_LENGTH+2) // bytes
#define IFXGETH_MAX_RX_BUFFER_SIZE (2560+IFXGETH_HEADER_LENGTH+2) // bytes

//________________________________________________________________________________________
// GLOBAL VARIABLES
extern volatile uint32 g_TickCount_1ms;
extern Ifx_Lwip g_Lwip;
// IfxGeth_Eth g_IfxGeth;
// uint8 channel0TxBuffer1[IFXGETH_MAX_TX_DESCRIPTORS][IFXGETH_MAX_TX_BUFFER_SIZE];
// uint8 channel0RxBuffer1[IFXGETH_MAX_RX_DESCRIPTORS][IFXGETH_MAX_RX_BUFFER_SIZE];

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

/** \addtogroup lib_lwIP
 * \{ */
void     Ifx_Lwip_init(eth_addr_t ethAddr);
void     Ifx_Lwip_onTimerTick(void);
void     Ifx_Lwip_pollTimerFlags(void);
void     Ifx_Lwip_pollReceiveFlags(void);
INLINE netif_t *Ifx_Lwip_getNetIf(void);
INLINE uint8   *Ifx_Lwip_getIpAddrPtr(void);
INLINE uint8   *Ifx_Lwip_getHwAddrPtr(void);

/** \} */
//________________________________________________________________________________________
// INLINE FUNCTION IMPLEMENTATIONS

/** \brief Returns pointer to the default network interface */
INLINE netif_t *Ifx_Lwip_getNetIf(void)
{
    return &g_Lwip.netif;
}


/** \brief Returns pointer to the actual IP address */
INLINE uint8 *Ifx_Lwip_getIpAddrPtr(void)
{
    return (uint8 *)&g_Lwip.netif.ip_addr.addr;
}


/** \brief Returns pointer to the actual H/W (MAC) address */
INLINE uint8 *Ifx_Lwip_getHwAddrPtr(void)
{
    return g_Lwip.eth_addr.addr;
}


#endif /* __IFX_LWIP_H__ */
