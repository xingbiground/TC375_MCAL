###############################################################################
#                                                                             #
#       Copyright (c) 2018 Infineon Technologies AG. All rights reserved.     #
#                                                                             #
#                                                                             #
#                              IMPORTANT NOTICE                               #
#                                                                             #
#                                                                             #
# Infineon Technologies AG (Infineon) is supplying this file for use          #
# exclusively with Infineonís microcontroller products. This file can be      #
# freely distributed within development tools that are supporting such        #
# microcontroller products.                                                   #
#                                                                             #
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED #
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF          #
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.#
# INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,#
# OR CONSEQUENTIAL DAMAGES, FOR	ANY REASON WHATSOEVER.                        #
#                                                                             #
###############################################################################

B_CONFIG_FILES_FOLDER:= 1_ToolEnv/0_Build/1_Config

B_TOOLCHAINS_ROOT?= C:\Tools\Compilers

#Include all the required/available configuration files
-include $(B_CONFIG_FILES_FOLDER)/*/Conf*.mk \
		$(B_CONFIG_FILES_FOLDER)/*/*/Conf*.mk
		
#Use the parallel build option from make (use available CPUs from your PC).
#NOTE: this option would be moved to Config.xml in the next BIFACES release!
B_PARALLEL_BUILD= no
DECLARED_TEST_MACROS = -DAPP_SW=DEMO_APP -DDEMO_APP=1 -DAURIX2G_MCAL_DEMOAPP=1U