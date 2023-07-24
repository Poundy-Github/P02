 @echo off

set COMPILER=C:\ghs\comp_201517\gbuild.exe

"%COMPILER%" -top "..\HUT_V3.5_B03.gpj" ..\SWC_CLUSTER\SWC_CLUSTER.gpj -nolink
