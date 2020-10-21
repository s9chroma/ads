@echo off

if not exist build mkdir build
pushd build
cl /Zi /FC /nologo ../ch1/main.c ../ch1/stackA.c ../ch1/stackL.c ../ch1/queueA.c ../ch1/queueL.c ../ch1/queueCL.c
if not errorlevel 1 call main.exe
popd
