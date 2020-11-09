@echo off

if not exist build mkdir build
pushd build
cl /Zi /FC /nologo ../ch2/main.c ../ch2/search_tree.c
if not errorlevel 1 call main.exe
popd
