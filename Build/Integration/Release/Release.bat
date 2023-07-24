@echo off & setlocal enabledelayedexpansion
set COMPILER=C:\ghs\comp_201517\gbuild.exe

set PRO=..\..\..\
set BM_PRO=%PRO%BootManage\Build\HUT_V3_5_BM.gpj
set PRO_Build=%PRO%Build\HUT_V3.5
rem set B_PRO=%PRO%Build\HUT_V3_5_FirmwareB.gpj
set HSM_PRO=%PRO%HSM\DemoHsm\Appl
set DIR=%PRO%Build\Integration\Release

echo Compile the project ...

set DEBUG=
set ALL=
set hsm=j

set B_BM="Y"
set B_FAB="Y"
set B_FA="N"
set B_FB="N"
set B_HSM="Y"
set B_Type="Release"
set SecBoot=
set PRO_ARG=

set PRO_TYPE="B03"
rem set B_B03="N"
rem set B_B02="N"
rem set B_P05="N"
rem set B_P03="N"

set MERGE="Y"

for %%I in (%*) do (
	if "%%I" == "-D" ( 
		set DEBUG=SUPPORT=HSM_DEBUG 
		set SecBoot=non_secboot
	) ^
 	else if "%%I" == "/BM" ( 
		set B_BM="N"
	) ^
	else if "%%I" == "/FA" ( 
		set B_FA="N" 
	) ^
    else if "%%I" == "/FB" ( 
		set B_FB="N" 
	) ^
	else if "%%I" == "/HSM" ( 
		set B_HSM="N" 
	) ^
	else if "%%I" == "/M" ( 
		set MERGE="N"
	) ^
	else if "%%I" == "/ALL" (
		set B_BM="N"
		set B_FA="N"
		set B_FB="N"
		set B_HSM="N"	
	) ^
	else if "%%I" == "-ALL" (
		set ALL=-all
		set hsm=b
	) ^
	else if "%%I" == "-Debug" (
		set B_Type="Debug"
	) ^
	else if "%%I" == "-Release" (
		set B_Type="Release"
	) ^
	else if "%%I" == "-FA" (
		set B_FA="Y"
		set B_FAB="N"
	) ^
	else if "%%I" == "-FB" (
		set B_FB="Y"
		set B_FAB="N"
	) ^
	else if "%%I" == "-H" (
		echo Release [options]
		echo Basic options:
		echo     /BM Uncompile the boot manager
		echo     /FA Uncompile the FirmwareA
		echo     /FB Uncompile the FirmwareB
		echo     /HSM  Uncompile the HSM
		echo     /ALL  UnCompile the  boot manager/FirmwareA/FirmwareB/HSM
		echo     /M Unmerged projects
		echo ------------------------------------------
		echo     -B02 : Select project B02
		echo     -B03 : Select project B03
		echo     -P03 : Select project P03
		echo     -P05 : Select project P05
		echo     -A07 : Select project A07
		echo     -A08 : Select project A08
		echo     -ES13 : Select project ES13
		echo     -EC24 : Select project EC24
		echo     -D01 : Select project D01
		echo     -P01N : Select project P01N
		echo     -ES24 : Select project ES24
		echo     -P02 : Select project P02
		echo     -B16 : Select project B16
		echo     -D Compile the HSM for Debug
		echo     -ALL Recompile all projects
		echo     -H print basic usage information
		goto END
	) ^
	else (
        set PRO_ARG=%%I
    )
)

set PRO_TYPE=%PRO_ARG:~1%

if "%ALL%"=="" ( echo Don't Rebuild All project) else ( echo Rebuild All project)
if %B_BM%=="Y" ( echo Build BootManage) else ( echo Don't Build BootManage)
if %B_FAB%=="Y" ( echo Build FirmwareA and FirmwareB)
if %B_FA%=="Y" ( echo Build FirmwareA) else ( echo Don't Build FirmwareA)
if %B_FB%=="Y" ( echo Build FirmwareB) else ( echo Don't Build FirmwareB)
if %B_HSM%=="Y" ( echo Build HSM) else ( echo Don't Build HSM)
echo Build Project %PRO_TYPE%
if %MERGE%=="Y" ( echo Merge file Enable) else ( echo Merge file Disable)
if "%DEBUG%"=="SUPPORT=HSM_DEBUG" ( echo SecBoot Disable) else ( echo SecBoot Enable)
echo Build %B_Type%

cd /d %~dp0
if %PRO_TYPE%=="N" (
	echo [5;41m Must switch a project type... [0m [34m
	echo     Release.bat -B02 : Select project B02
	echo     Release.bat -B03 : Select project B03
	echo     Release.bat -P03 : Select project P03
	echo     Release.bat -P05 : Select project P05
	echo     Release.bat -A07 : Select project A07
	echo     Release.bat -A08 : Select project A08
	echo     Release.bat -ES13 : Select project ES13
	echo     Release.bat -EC24 : Select project EC24
	echo     Release.bat -D01 : Select project D01
	echo     Release.bat -P01N : Select project P01N
	echo     Release.bat -ES24 : Select project ES24
	echo     Release.bat -P02 : Select project P02
	echo     Release.bat -B16 : Select project B16
	goto ERROR
)

if %B_BM%=="Y" (
	echo [5;41m Compile the project BootManage... [0m [34m
	"%COMPILER%" %ALL% -noreasons  -top "%BM_PRO%"
	if !errorlevel! neq 0 goto ERROR
)

if %B_FAB%=="Y" (
	echo [5;41m Compile the project %PRO_TYPE% FirmwareA and FirmwareB... [0m [34m

	cd %PRO%Build
	"%COMPILER%" %ALL% -top "HUT_V3.5_%PRO_TYPE%.gpj"
	if !errorlevel! neq 0 (
		cd /d %~dp0
		goto ERROR
	)
        cd /d %~dp0

) else (
	if %B_FA%=="Y" (
		cd %PRO%Build
		"%COMPILER%" %ALL% -top "HUT_V3.5_%PRO_TYPE%.gpj" _ghs\v3.5_project_A.gpj
		if !errorlevel! neq 0 (
			cd /d %~dp0
			goto ERROR
		)
                cd /d %~dp0
	)
	if %B_FB%=="Y" (
		cd %PRO%Build
		"%COMPILER%" %ALL% -top "HUT_V3.5_%PRO_TYPE%.gpj" _ghs\v3.5_project_B.gpj
		if !errorlevel! neq 0 (
			cd /d %~dp0
			goto ERROR
		)
                cd /d %~dp0
	)
)

if %MERGE%=="Y" (
	if %B_HSM%=="Y" (
		echo [5;41m Compile the project HSM...  [0m [34m
		cd %HSM_PRO%
		call %hsm% %DEBUG%
		cd %DIR%
	)
	if not exist .\output\map mkdir .\output\map
	if not exist ../../../BootManage/Build/output/BootManager/f1km_sk_v3_bm.hex (
		echo BootManager Hex File does not exist.
		goto ERROR
	) else (
		copy "..\..\..\BootManage\Build\output\BootManager\f1km_sk_v3_bm.map" ".\output\map\%B_Type%_%SecBoot%_f1km_sk_v3_bm.map"
	)
	if not exist ../../output/FirmwareA/f1km_sk_v3_ghs.hex (
		echo FirmwareA Hex File does not exist.
		goto ERROR

	) else (
		copy "..\..\output\FirmwareA\f1km_sk_v3_ghs.map" ".\output\map\%B_Type%_%SecBoot%_A_f1km_sk_v3_ghs.map"
	)
	if not exist ../../output/FirmwareB/f1km_sk_v3_ghs.hex (
		echo FirmwareB Hex File does not exist.
		goto ERROR
	) else (
		copy "..\..\output\FirmwareB\f1km_sk_v3_ghs.map" ".\output\map\%B_Type%_%SecBoot%_B_f1km_sk_v3_ghs.map"
	)
	if not exist ../../../HSM/DemoHsm/Appl/vHsm.hex (
		echo HSM Hex File does not exist.
		goto ERROR
	) else (
		copy "..\..\..\HSM\DemoHsm\Appl\vHsm.map" ".\output\map\%B_Type%_%SecBoot%_vHsm.map"
	)

	echo [41m Merge file  [0m [34m
	python Release.py %PRO_TYPE% %B_Type%
	if !errorlevel! neq 0 (
		echo "py error: " !errorlevel!
		goto ERROR
	)
)

echo [0m

goto END

:END
pause
exit /b 0

:ERROR
echo [0m
exit /b 1
