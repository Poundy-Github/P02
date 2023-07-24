@echo off & setlocal enabledelayedexpansion
set aa=1
echo -------------------------------------------------------------------------
echo                      Select a HEX file
for /f "delims=" %%i in ('dir /s/b "*.hex"') do (
	echo [8;36m !aa!: [5;32m %%i [0m
	echo.
	set "obj[!aa!]="%%i""
	set /a aa=!aa! + 1
)
echo -------------------------------------------------------------------------
if !aa! EQU 1 goto Error

rem CHOICE /C 12345 /T 10 /D 1 /N /M "---------------Please Input HEX id-------------"
set /p chooseResult=Please Input HEX id

if %aa% LSS %chooseResult%   ( 
echo Wrong choice
goto Error
)

set objLength=!aa!

set objIndex=0

set RetainedData=Y
set /p RetainedData="[5;45m���³���������Ƿ�[5;41m��������[0m (Y/n Ĭ�ϱ���)"
if %RetainedData% EQU N ( goto NoneRetainedDataUpdata )
if %RetainedData% EQU n ( goto NoneRetainedDataUpdata )

if %RetainedData% EQU Y ( goto RetainedDataUpdata )
if %RetainedData% EQU y ( goto RetainedDataUpdata )

rem for /f "usebackq delims== tokens=1-2" %%i in (`set obj[%chooseResult%]`) do (
rem 	for /f %%a in ('dir /b %%j') do (
rem 		set indexdx=%%~za
rem 	)
rem )
rem echo %indexdx%
:RetainedDataUpdata
	rem if %objIndex% equ %objLength% goto end
	for /f "usebackq delims== tokens=1-2" %%i in (`set obj[%chooseResult%]`) do (
		RFP\RFPV3.Console.exe /silent RFP\clean.rpj
		RFP\RFPV3.Console.exe RFP\download_rd.rpj /file %%j
	)

	ECHO Result Code: %ErrorLevel%
	if %ErrorLevel% EQU 1 (
		goto Error
	) else (
		goto Success
	)
	
:NoneRetainedDataUpdata
	set notarize=N
	rem set /p notarize="[5;45mִ�д˲����󽫻�[5;41m ����豸����������[5;45m���Ƿ�ȷ��ִ�У�[0m(N/y Ĭ�ϲ�ִ��)"
	rem if %notarize% EQU N ( goto RetainedDataUpdata )
	rem if %notarize% EQU n ( goto RetainedDataUpdata )

	rem if %objIndex% equ %objLength% goto end
	for /f "usebackq delims== tokens=1-2" %%i in (`set obj[%chooseResult%]`) do (
		RFP\RFPV3.Console.exe /silent RFP\clean.rpj
		RFP\RFPV3.Console.exe RFP\download.rpj /file %%j
	)

	ECHO Result Code: %ErrorLevel%
	if %ErrorLevel% EQU 1 (
		goto Error
	) else (
		goto Success
	)

:Error
	echo [5;45m -------------------- Download [5;41m Failed [5;45m --------------------[0m
	goto end
:Success
	echo [5;45m -------------------- Download [5;42m Success [5;45m -------------------[0m
	goto end
:end

pause