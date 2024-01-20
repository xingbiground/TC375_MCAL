@echo off

echo ****************************************************************************************************************
echo * File         :   PostHex.bat
echo * Description  :   Post process of hex file, just for TC375.
echo ****************************************************************************************************************

set ROOT=%~dp0
set Hexview=%ROOT%Hexview\hexview.exe

set InputFile=NOTFOUND
set OutputFile=%ROOT%Output\Output.hex
set LogFile=%ROOT%PostHex.log

set FlashRange=0xA0000000-0xA02FFFFF
set ABSwapOffset=0x300000
set CRCRange=0xA0000000-0xA02FFFFB
set CRCAddr=0xA02FFFFC

echo Looking for input hex file in %ROOT%
for %%i in (%ROOT%*.hex) do (
    echo Hex file found: %%i
    set InputFile=%%i
)
if %InputFile%==NOTFOUND (
    echo Error: No hex file found in the current directory.
    goto END
)

echo Moving code from cached area to Non-Cached area...
%Hexview% /S /MO:%InputFile%;0x20000000:0x80000000-0x80FFFFFF+%InputFile%;0x0:0xA0000000-0xA0FFFFFF     /XI:32 /L:%LogFile% -o %OutputFile%

echo Filling empty area with 0xFF...
%Hexview% /S %OutputFile% /AR:%FlashRange% /FP:0xFF /FR:%FlashRange%                                    /XI:32 /L:%LogFile% -o %OutputFile%

echo Calculating CRC for range %CRCRange%, result is in %CRCAddr%...
%Hexview% /S %OutputFile% /CS9:@%CRCAddr%;%CRCRange%                                                    /XI:32 /L:%LogFile% -o %OutputFile%

echo Duplicating hex file for B bank...
%Hexview% /S /MO:%OutputFile%;0x0:%FlashRange%+%OutputFile%;%ABSwapOffset%:%FlashRange%                 /XI:32 /L:%LogFile% -o %OutputFile%

:END
pause