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

echo %date:~0,4%��%date:~5,2%��%date:~8,2%��%time:~0,8%

REM configure the notepad  
set NOTEPAD=C:\Program Files\Notepad++\notepad++.exe

REM configure the compiler 
set COMPILER=C:\ghs\comp_201517\gbuild.exe

REM search GPJ Name
REM for /f "delims=\" %%a in ('dir /b /a-d /o-d "*.GPJ"') do ( set GPJ=%%a )
set GPJ=..\HUT_V3_5_FirmwareA.gpj
set GPJ_PATH=FirmwareA
set LOG_PATH=CS_Plus

echo.
echo --------------------------Please choose building mode---------------------------
echo 			      [ 1. �������� ] 
echo.
echo 			      [ 2. ȫ�±��� ]
echo. 
echo 			      [ 3. �������벢��������Ϣ������txt�ı� ]
echo.  
echo 			      [ 4. ȫ�±��벢��������Ϣ������txt�ı� ] 
echo.
echo 			      [ 5. ��������ļ� ]
echo.
CHOICE /C 12345 /T 10 /D 1 /N /M "---------------Please Input 1 or 2 or 3 or 4 or 5,Timeout defalut 1-------------"

REM " [1.��������] [2.��ȫ����] [3.�������벢����txt] [4.��ȫ���벢����txt] [5.���]"
if %errorlevel%==1 goto NODE
if %errorlevel%==2 goto DE
if %errorlevel%==3 goto NODEN
if %errorlevel%==4 goto DEN
if %errorlevel%==5 goto DN
:DE
echo.
echo ------------------------------# Start Cleaning #--------------------------------
cd 
if exist  ..\output\*         			 del     /S /Q	..\output\*
if exist  ..\output\%GPJ_PATH%\list      rd 	 /S /Q  ..\output\%GPJ_PATH%\list 
if exist  ..\output\%GPJ_PATH%\objects   rd 	 /S /Q  ..\output\%GPJ_PATH%\objects  
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
rem ��ʾ��ʼʱ��
set start=%time%
REM set stt=%1
set shh=%start:~0,2%*3600
set smm=%start:~3,2%*60
set sss=%start:~6,2%
"%COMPILER%" -top "%GPJ%" 2>&1 -parallel
rem ��ʾ����ʱ��
set end=%time%
REM set ett=%1
set ehh=%end:~0,2%*3600
set emm=%end:~3,2%*60
set ess=%end:~6,2%
rem ����ʱ���
set /a tdiff=(%ehh%-%shh%)+(%emm%-%smm%)+%ess%-%sss%
cd ..\output\%GPJ_PATH%
if exist *.hex (echo ------Compiling Result: Pass---) else (echo ------Compiling Result: Fail---)

echo ------Compiling Time: %tdiff%s------
echo ----------------------------------------------------------------End-------------
echo %date:~0,4%��%date:~5,2%��%date:~8,2%��%time:~0,8%
pause
goto end

:DEN
echo.
echo ------------------------------# Start Cleaning #--------------------------------
cd 
if exist  ..\output\*         			 del     /S /Q	..\output\*
if exist  ..\output\%GPJ_PATH%\list      rd 	 /S /Q  ..\output\%GPJ_PATH%\list 
if exist  ..\output\%GPJ_PATH%\objects   rd 	 /S /Q  ..\output\%GPJ_PATH%\objects
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
rem ��ʾ��ʼʱ��
set start=%time%
REM set tt=%1
set shh=%start:~0,2%*3600
set smm=%start:~3,2%*60
set sss=%start:~6,2%

"%COMPILER%" -top "%GPJ%" 2>&1 -parallel -stderr=.\%LOG_PATH%\BuildLog.txt

set end=%time:~0,8%

rem ��ʾ����ʱ��
set end=%time%
REM set tt=%1
set ehh=%end:~0,2%*3600
set emm=%end:~3,2%*60
set ess=%end:~6,2%
rem ����ʱ���
set /a tdiff=(%ehh%-%shh%)+(%emm%-%smm%)+%ess%-%sss%

cd ..\output\%GPJ_PATH%
if exist *.hex (echo ------Compiling Result: Pass---) else (echo ------Compiling Result: Fail---)
echo ------Compiling Time: %tdiff%s------
echo ------Compiling Warning and Error Information is in CS_Plus\BuildLog.txt-------
echo ----------------------------------------------------------------End-------------
echo %date:~0,4%��%date:~5,2%��%date:~8,2%��%time:~0,8%
REM open the build result if existed  
REM cd ..\output\%GPJ_PATH%

if exist  BuildLog.txt   "%NOTEPAD%"  BuildLog.txt 

pause

goto end

:DN
echo.
echo ------------------------------# Start Cleaning #--------------------------------
cd 
if exist  ..\output\*         del     /S /Q	..\output\*
if exist  ..\output\%GPJ_PATH%\list      rd /S /Q  ..\output\%GPJ_PATH%\list 
if exist  ..\output\%GPJ_PATH%\objects   rd /S /Q  ..\output\%GPJ_PATH%\objects
echo.
echo -------------------------------Clean Success!-----------------------------------
echo.
pause