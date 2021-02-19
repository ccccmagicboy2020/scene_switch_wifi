SET C51INC=d:\cccc2020\TOOL\Keil\C51\Inc;d:\cccc2020\TOOL\Keil\C51\Inc\Holychip
SET C51LIB=d:\cccc2020\TOOL\Keil\C51\Lib
SET CPU_TYPE=HC89S003F4
SET CPU_VENDOR=HC89S Series
SET UV2_TARGET=Target 1
SET CPU_XTAL=0x01E84800
@echo off
set UV=d:\cccc2020\TOOL\Keil\UV4\UV4.exe
set UV_PRO_PATH=d:\cccc2020\CODE\bt\testmyself3152\Project\HC-MCU-XBR.uvproj
echo Init building ...
echo .>build_log.txt
%UV% -j0 -r %UV_PRO_PATH% -o %cd%\build_log.txt
type build_log.txt
echo Done.
pause