/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Cpu0_Main.c                                                **
**                                                                            **
**  VERSION      : 0.0.1                                                      **
**                                                                            **
**  DATE         : 2016-08-17                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Example Cpu0 Main startup file                             **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Ssw_Infra.h"
#include "IFX_Os.h"
#ifdef AURIX2G_MCAL_DEMOAPP
#include "DemoApp.h"
#endif

#include "Ifx_Lwip.h"
#include "EcuM.h"
#include "Echo.h"
#include "StatusReport.h"
#include "Icu_17_TimerIp.h"
#include "Dio.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint32 SystemTick = 0;  /* System Tick, increment every millisecond */
boolean SystemTickUpdateFlag = FALSE;

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/

void core0_main (void)
{
  volatile unsigned short LoopFlag = 1U;
  unsigned short cpuWdtPassword;
  unsigned short safetyWdtPassword;
  uint32 localSysTick;
  Icu_17_TimerIp_DutyCycleType PwmMeasureValue;
  Dio_LevelType buttonLevel;


  ENABLE();
  /*
   * !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
   * Enable the watchdog in the demo if it is required and also service the watchdog periodically
   * */
  cpuWdtPassword = Ifx_Ssw_getCpuWatchdogPassword(&MODULE_SCU.WDTCPU[0]);
  safetyWdtPassword = Ifx_Ssw_getSafetyWatchdogPassword();
  Ifx_Ssw_disableCpuWatchdog(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);
  Ifx_Ssw_disableSafetyWatchdog(safetyWdtPassword);

  EcuM_Init();

  /********************************* App INIT *********************************/
  echoInit();
  StatusReport_Init();

  // #ifdef AURIX2G_MCAL_DEMOAPP
  // DemoApp_Init();
  // DemoApp();
  // #endif
  while (LoopFlag == 1U)
  {
    while(!SystemTickUpdateFlag){
      /* wait for tick update. */
    }
    SystemTickUpdateFlag = FALSE;
    localSysTick = SystemTick;

    /********************************* 1ms rbl *********************************/
    Ifx_Lwip_onTimerTick();
    Ifx_Lwip_pollTimerFlags();
    Ifx_Lwip_pollReceiveFlags();    

    /********************************* 10ms rbl *********************************/
    if(localSysTick%10 == 0){
      Icu_17_TimerIp_GetDutyCycleValues(IcuConf_IcuChannel_IcuChannel_0, &PwmMeasureValue);

      /* Button and LED interaction. */
      buttonLevel = Dio_ReadChannel(DioConf_DioChannel_BUTTON1);
      Dio_WriteChannel(DioConf_DioChannel_LED2, buttonLevel);
    }
    
    /********************************* 1000 rbl *********************************/
    if(localSysTick%1000 == 0){
      StatusReport_1000ms();
    }
  }
}

void SystemTickIsr()
{
  SystemTick++;
  SystemTickUpdateFlag = TRUE;
}
