@echo off
set TAR_FOLDER=%cd%\..\SWC_Sync

del /a /f /q /s %TAR_FOLDER%\*h
del /a /f /q /s %TAR_FOLDER%\*a
del /a /f /q /s %cd%\SWC_Base\*.siz
del /a /f /q /s %cd%\SWC_Base\*.dba
rd /s /q %cd%\SWC_Base\objs

for /r %cd% %%a in (*.h) do (
copy "%%a" %TAR_FOLDER%
)
for /r %cd% %%a in (*.a) do (
copy "%%a" %TAR_FOLDER%
)