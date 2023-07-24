 @echo off
REM ---------------------------------------------------------------------------------
REM Description: The batch file used to clear the existed old files before check in
REM              
REM Author     :  Chao Feng
REM
REM Date       : 2020-4-22
REM ---------------------------------------------------------------------------------
echo --------------------------------Start-------------------------------------------
color 5f

echo %date:~0,4%ï¿½ï¿½%date:~5,2%ï¿½ï¿½%date:~8,2%ï¿½ï¿½%time:~0,8%

REM configure the notepad  
set NOTEPAD=C:\Program Files\Notepad++\notepad++.exe

REM configure the compiler 
set COMPILER=C:\ghs\comp_201517\gbuild.exe

REM Select build type
echo.
echo --------------------------Please Select build Type---------------------------
echo.
echo 			      				[ 1. FULL ] 
echo.
echo 			      				[ 2. HALF ]
echo.
CHOICE /C 12 /T 10 /D 1 /N /M "---------------Please Input 1 or 2 ,Timeout defalut 1-------------"

if %errorlevel%==1 goto FULL_BUILD
if %errorlevel%==2 goto HALF_BUILD

:FULL_BUILD
set BUILD_TYPE=16
goto SELECT_GPJ

:HALF_BUILD
set BUILD_TYPE=4
goto SELECT_GPJ

:SELECT_GPJ
REM search GPJ Name
REM for /f "delims=\" %%a in ('dir /b /a-d /o-d "*.GPJ"') do ( set GPJ=%%a )
echo.
echo --------------------------Please choose project---------------------------
echo 			      [ 1. B02 ] 
echo.
echo 			      [ 2. B03 ]
echo. 
echo 			      [ 3. P03 ]
echo.  
echo 			      [ 4. P05 ] 
echo.
echo 			      [ 5. A07 ]
echo.
echo 			      [ 6. A08 ]
echo.
echo 			      [ 7. ES13 ]
echo.
echo 			      [ 8. ES24 ]
echo.
echo 			      [ 9. EC24 ]
echo.
echo 			      [ A. D01 ]
echo.
echo 			      [ B. D02 ]
echo.
echo 			      [ C. D03 ]
echo.
echo 			      [ D. P01N ]
echo.
echo 			      [ E. P02 ]
echo.
echo 			      [ F. B16 ]
echo.
CHOICE /C 123456789ABCDEF /T 10 /D 1 /N /M "---------------Please Input 1 or 2 or 3 or 4 or 5,Timeout defalut 1-------------"

REM " [1.B02] [2. B03] [3.P03] [4.P05] [5.OTHER]"

if %errorlevel%==1 goto B02_GPJ
if %errorlevel%==2 goto B03_GPJ
if %errorlevel%==3 goto P03_GPJ
if %errorlevel%==4 goto P05_GPJ
if %errorlevel%==5 goto A07_GPJ
if %errorlevel%==6 goto A08_GPJ
if %errorlevel%==7 goto ES13_GPJ
if %errorlevel%==8 goto ES24_GPJ
if %errorlevel%==9 goto EC24_GPJ
if %errorlevel%==10 goto D01_GPJ
if %errorlevel%==11 goto D02_GPJ
if %errorlevel%==12 goto D03_GPJ
if %errorlevel%==13 goto P01N_GPJ
if %errorlevel%==14 goto P02_GPJ
if %errorlevel%==15 goto B16_GPJ
:B02_GPJ
set GPJ="HUT_V3.5_B02.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:B03_GPJ
set GPJ="HUT_V3.5_B03.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:P03_GPJ
set GPJ="HUT_V3.5_P03.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:P05_GPJ
set GPJ="HUT_V3.5_P05.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:A07_GPJ
set GPJ="HUT_V3.5_A07.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:A08_GPJ
set GPJ="HUT_V3.5_A08.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:ES13_GPJ
set GPJ="HUT_V3.5_ES13.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:ES24_GPJ
set GPJ="HUT_V3.5_ES24.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:EC24_GPJ
set GPJ="HUT_V3.5_EC24.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:D01_GPJ
set GPJ="HUT_V3.5_D01.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:D02_GPJ
set GPJ="HUT_V3.5_D02.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:D03_GPJ
set GPJ="HUT_V3.5_D03.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:P01N_GPJ
set GPJ="HUT_V3.5_P01N.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:P02_GPJ
set GPJ="HUT_V3.5_P02.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:B16_GPJ
set GPJ="HUT_V3.5_B16.gpj _ghs\v3.5_project_A.gpj"
set GPJ_PATH=FirmwareA
goto BUILD_GPJ

:BUILD_GPJ
echo.
echo --------------------------Please choose building mode---------------------------
echo 			      [ 1. ÔöÁ¿±àÒë ] 
echo.
echo 			      [ 2. È«ÐÂ±àÒë ]
echo. 
echo 			      [ 3. ÔöÁ¿±àÒë²¢½«±àÒëÐÅÏ¢µ¼³öÖÁtxtÎÄ±¾ ]
echo.  
echo 			      [ 4. È«ÐÂ±àÒë²¢½«±àÒëÐÅÏ¢µ¼³öÖÁtxtÎÄ±¾ ] 
echo.
echo 			      [ 5. Çå³ý±àÒëÎÄ¼þ ]
echo.
CHOICE /C 12345 /T 10 /D 1 /N /M "---------------Please Input 1 or 2 or 3 or 4 or 5,Timeout defalut 1-------------"

REM " [1.ÔöÁ¿±àÒë] [2.ÍêÈ«±àÒë] [3.ÔöÁ¿±àÒë²¢µ¼³ötxt] [4.ÍêÈ«±àÒë²¢µ¼³ötxt] [5.Çå³ý]"
if %errorlevel%==1 goto NODE
if %errorlevel%==2 goto DE
if %errorlevel%==3 goto NODEN
if %errorlevel%==4 goto DEN
if %errorlevel%==5 goto DN
:DE
echo.
echo ------------------------------# Start Cleaning #--------------------------------
cd 
if exist  output\*         			 del     /S /Q	output\*
if exist  output\%GPJ_PATH%\list      rd 	 /S /Q  output\%GPJ_PATH%\list 
if exist  output\%GPJ_PATH%\objects   rd 	 /S /Q  output\%GPJ_PATH%\objects  
echo.
echo -------------------------------Clean Success!-----------------------------------
:NODE
echo.
echo ------------------------------# Start Building #--------------------------------
echo.
echo -----------------------------------Building-------------------------------------
echo.
set ns=0

@echo off
rem ï¿½ï¿½Ê¾ï¿½ï¿½Ê¼Ê±ï¿½ï¿½
set start=%time%
REM set stt=%1
set shh=%start:~0,2%*3600
set smm=%start:~3,2%*60
set sss=%start:~6,2%
"%COMPILER%" -top "%GPJ%" 2>&1 -parallel=%BUILD_TYPE%
rem ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½
set end=%time%
REM set ett=%1
set ehh=%end:~0,2%*3600
set emm=%end:~3,2%*60
set ess=%end:~6,2%
rem ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿?
set /a tdiff=(%ehh%-%shh%)+(%emm%-%smm%)+%ess%-%sss%
cd output\%GPJ_PATH%
if exist *.hex (echo ------Compiling Result: Pass---) else (echo ------Compiling Result: Fail---)

echo ------Compiling Time: %tdiff%s------
echo ----------------------------------------------------------------End-------------
echo %date:~0,4%ï¿½ï¿½%date:~5,2%ï¿½ï¿½%date:~8,2%ï¿½ï¿½%time:~0,8%
pause
goto end

:DEN
echo.
echo ------------------------------# Start Cleaning #--------------------------------
cd 
if exist  output\*         			 del     /S /Q	output\*
if exist  output\%GPJ_PATH%\list      rd 	 /S /Q  output\%GPJ_PATH%\list 
if exist  output\%GPJ_PATH%\objects   rd 	 /S /Q  output\%GPJ_PATH%\objects
echo.
echo -------------------------------Clean Success!-----------------------------------
echo.

:NODEN
echo.	
echo ------------------------------# Start Building #--------------------------------
echo.
echo -----------------Compiling is running,  Please  wait.............---------------
echo.
set start=%time:~0,8%

@echo off
rem ï¿½ï¿½Ê¾ï¿½ï¿½Ê¼Ê±ï¿½ï¿½
set start=%time%
REM set tt=%1
set shh=%start:~0,2%*3600
set smm=%start:~3,2%*60
set sss=%start:~6,2%

"%COMPILER%" -top "%GPJ%" 2>&1 -parallel=%BUILD_TYPE% -stderr=output\%GPJ_PATH%\BuildError.txt

set end=%time:~0,8%

rem ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½
set end=%time%
REM set tt=%1
set ehh=%end:~0,2%*3600
set emm=%end:~3,2%*60
set ess=%end:~6,2%
rem ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿?
set /a tdiff=(%ehh%-%shh%)+(%emm%-%smm%)+%ess%-%sss%

cd output\%GPJ_PATH%
if exist *.hex (echo ------Compiling Result: Pass---) else (echo ------Compiling Result: Fail---)
echo ------Compiling Time: %tdiff%s------
echo ------Compiling Warning and Error Information is in output\BuildError.txt-------
echo ----------------------------------------------------------------End-------------
echo %date:~0,4%ï¿½ï¿½%date:~5,2%ï¿½ï¿½%date:~8,2%ï¿½ï¿½%time:~0,8%
REM open the build result if existed  
REM cd output\%GPJ_PATH%

if exist  BuildError.txt   "%NOTEPAD%"  BuildError.txt 

pause

goto end

:DN
echo.
echo ------------------------------# Start Cleaning #--------------------------------
cd 
if exist  output\*         del     /S /Q	output\*
if exist  output\%GPJ_PATH%\list      rd /S /Q  output\%GPJ_PATH%\list 
if exist  output\%GPJ_PATH%\objects   rd /S /Q  output\%GPJ_PATH%\objects
echo.
echo -------------------------------Clean Success!-----------------------------------
echo.
pause