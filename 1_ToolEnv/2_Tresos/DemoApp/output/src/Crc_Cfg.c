
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Crc_Cfg.c                                                     **
**                                                                            **
**  VERSION   : 5.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-12-03, 16:05:44       !!!IGNORE-LINE!!!                  **
**                                                                            **
**  GENERATOR : Build b200227-0222           !!!IGNORE-LINE!!!                **
**                                                                            **
**  BSW MODULE DECRIPTION : Crc.bmd                                           **
**                                                                            **
**  VARIANT   : Variant LT                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Crc configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of CRC Driver, AUTOSAR Release 4.2.2     **
**                   : Specification of Crc Driver, AUTOSAR Release 4.4.0     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

      
/*******************************************************************************
**                             Includes                                       **
*******************************************************************************/
/* Include Crc Module File */
#include "Crc.h"
/******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
#define CRC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per
 * Autosar guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly
 * included without safegaurd. It complies to Autosar guidelines. */
#include "Crc_MemMap.h"
/* [cover parentID={387BA95D-4ABF-40e0-A45C-D6EF94044C1E}]
 * [/cover] */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This data structure is quite
 * big is size, therefore link time relocation of table is
 * provided using Autosar Memmap definition guidelines         */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Crc_Table32P4 is moved to Crc_Cfg.c for
 * conditional generation but prototype is defined in Crc.c to avoid exposure
 * to user. */
const uint32 Crc_Table32P4[256] =
{
  0x00000000U, 0xF4ACFB13U, 0x1DF50D35U, 0xE959F626U,
  0x3BEA1A6AU, 0xCF46E179U, 0x261F175FU, 0xD2B3EC4CU,
  0x77D434D4U, 0x8378CFC7U, 0x6A2139E1U, 0x9E8DC2F2U,
  0x4C3E2EBEU, 0xB892D5ADU, 0x51CB238BU, 0xA567D898U,
  0xEFA869A8U, 0x1B0492BBU, 0xF25D649DU, 0x06F19F8EU,
  0xD44273C2U, 0x20EE88D1U, 0xC9B77EF7U, 0x3D1B85E4U,
  0x987C5D7CU, 0x6CD0A66FU, 0x85895049U, 0x7125AB5AU,
  0xA3964716U, 0x573ABC05U, 0xBE634A23U, 0x4ACFB130U,
  0x2BFC2843U, 0xDF50D350U, 0x36092576U, 0xC2A5DE65U,
  0x10163229U, 0xE4BAC93AU, 0x0DE33F1CU, 0xF94FC40FU,
  0x5C281C97U, 0xA884E784U, 0x41DD11A2U, 0xB571EAB1U,
  0x67C206FDU, 0x936EFDEEU, 0x7A370BC8U, 0x8E9BF0DBU,
  0xC45441EBU, 0x30F8BAF8U, 0xD9A14CDEU, 0x2D0DB7CDU,
  0xFFBE5B81U, 0x0B12A092U, 0xE24B56B4U, 0x16E7ADA7U,
  0xB380753FU, 0x472C8E2CU, 0xAE75780AU, 0x5AD98319U,
  0x886A6F55U, 0x7CC69446U, 0x959F6260U, 0x61339973U,
  0x57F85086U, 0xA354AB95U, 0x4A0D5DB3U, 0xBEA1A6A0U,
  0x6C124AECU, 0x98BEB1FFU, 0x71E747D9U, 0x854BBCCAU,
  0x202C6452U, 0xD4809F41U, 0x3DD96967U, 0xC9759274U,
  0x1BC67E38U, 0xEF6A852BU, 0x0633730DU, 0xF29F881EU,
  0xB850392EU, 0x4CFCC23DU, 0xA5A5341BU, 0x5109CF08U,
  0x83BA2344U, 0x7716D857U, 0x9E4F2E71U, 0x6AE3D562U,
  0xCF840DFAU, 0x3B28F6E9U, 0xD27100CFU, 0x26DDFBDCU,
  0xF46E1790U, 0x00C2EC83U, 0xE99B1AA5U, 0x1D37E1B6U,
  0x7C0478C5U, 0x88A883D6U, 0x61F175F0U, 0x955D8EE3U,
  0x47EE62AFU, 0xB34299BCU, 0x5A1B6F9AU, 0xAEB79489U,
  0x0BD04C11U, 0xFF7CB702U, 0x16254124U, 0xE289BA37U,
  0x303A567BU, 0xC496AD68U, 0x2DCF5B4EU, 0xD963A05DU,
  0x93AC116DU, 0x6700EA7EU, 0x8E591C58U, 0x7AF5E74BU,
  0xA8460B07U, 0x5CEAF014U, 0xB5B30632U, 0x411FFD21U,
  0xE47825B9U, 0x10D4DEAAU, 0xF98D288CU, 0x0D21D39FU,
  0xDF923FD3U, 0x2B3EC4C0U, 0xC26732E6U, 0x36CBC9F5U,
  0xAFF0A10CU, 0x5B5C5A1FU, 0xB205AC39U, 0x46A9572AU,
  0x941ABB66U, 0x60B64075U, 0x89EFB653U, 0x7D434D40U,
  0xD82495D8U, 0x2C886ECBU, 0xC5D198EDU, 0x317D63FEU,
  0xE3CE8FB2U, 0x176274A1U, 0xFE3B8287U, 0x0A977994U,
  0x4058C8A4U, 0xB4F433B7U, 0x5DADC591U, 0xA9013E82U,
  0x7BB2D2CEU, 0x8F1E29DDU, 0x6647DFFBU, 0x92EB24E8U,
  0x378CFC70U, 0xC3200763U, 0x2A79F145U, 0xDED50A56U,
  0x0C66E61AU, 0xF8CA1D09U, 0x1193EB2FU, 0xE53F103CU,
  0x840C894FU, 0x70A0725CU, 0x99F9847AU, 0x6D557F69U,
  0xBFE69325U, 0x4B4A6836U, 0xA2139E10U, 0x56BF6503U,
  0xF3D8BD9BU, 0x07744688U, 0xEE2DB0AEU, 0x1A814BBDU,
  0xC832A7F1U, 0x3C9E5CE2U, 0xD5C7AAC4U, 0x216B51D7U,
  0x6BA4E0E7U, 0x9F081BF4U, 0x7651EDD2U, 0x82FD16C1U,
  0x504EFA8DU, 0xA4E2019EU, 0x4DBBF7B8U, 0xB9170CABU,
  0x1C70D433U, 0xE8DC2F20U, 0x0185D906U, 0xF5292215U,
  0x279ACE59U, 0xD336354AU, 0x3A6FC36CU, 0xCEC3387FU,
  0xF808F18AU, 0x0CA40A99U, 0xE5FDFCBFU, 0x115107ACU,
  0xC3E2EBE0U, 0x374E10F3U, 0xDE17E6D5U, 0x2ABB1DC6U,
  0x8FDCC55EU, 0x7B703E4DU, 0x9229C86BU, 0x66853378U,
  0xB436DF34U, 0x409A2427U, 0xA9C3D201U, 0x5D6F2912U,
  0x17A09822U, 0xE30C6331U, 0x0A559517U, 0xFEF96E04U,
  0x2C4A8248U, 0xD8E6795BU, 0x31BF8F7DU, 0xC513746EU,
  0x6074ACF6U, 0x94D857E5U, 0x7D81A1C3U, 0x892D5AD0U,
  0x5B9EB69CU, 0xAF324D8FU, 0x466BBBA9U, 0xB2C740BAU,
  0xD3F4D9C9U, 0x275822DAU, 0xCE01D4FCU, 0x3AAD2FEFU,
  0xE81EC3A3U, 0x1CB238B0U, 0xF5EBCE96U, 0x01473585U,
  0xA420ED1DU, 0x508C160EU, 0xB9D5E028U, 0x4D791B3BU,
  0x9FCAF777U, 0x6B660C64U, 0x823FFA42U, 0x76930151U,
  0x3C5CB061U, 0xC8F04B72U, 0x21A9BD54U, 0xD5054647U,
  0x07B6AA0BU, 0xF31A5118U, 0x1A43A73EU, 0xEEEF5C2DU,
  0x4B8884B5U, 0xBF247FA6U, 0x567D8980U, 0xA2D17293U,
  0x70629EDFU, 0x84CE65CCU, 0x6D9793EAU, 0x993B68F9U
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
 * because of naming convention*/
#define CRC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per
 * Autosar guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly
 * included without safeguard. It complies to Autosar guidelines. */
#include "Crc_MemMap.h"


/*******************************************************************************
**                  Channel Transfer notification functions                   **
*******************************************************************************/
/* User defined notification functions to be called by CRC driver in case
* of successful channel tranfer by DMA channel*/
/* ************************************************************************** */

/*******************************************************************************
**                   Channel Error notification functions                     **
*******************************************************************************/
/* User defined notification functions to be called by CRC driver in case
* of error from the resource partitions */
/* ************************************************************************** */

/******************************************************************************
**                       Core Specific Configuration                         **
******************************************************************************/
/* None of the core is configured with FCE resources*/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
