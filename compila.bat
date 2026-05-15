@echo off
setlocal

set "WIN_BISON=win_bison"
set "WIN_FLEX=win_flex"
set "FLEX_INC=C:\winflexbison"
set "GPP=C:\msys64\ucrt64\bin\g++.exe"

"%WIN_BISON%" -d sintatico.y
if errorlevel 1 goto :end

"%WIN_FLEX%" lexico.l
if errorlevel 1 goto :end

"%GPP%" -std=c++17 -Wall -Iinclude -I"%FLEX_INC%" -c src\main.cpp -o main.o
if errorlevel 1 goto :end

"%GPP%" -std=c++17 -Wall -Iinclude -I"%FLEX_INC%" -c src\ast.cpp -o ast.o
if errorlevel 1 goto :end

"%GPP%" -std=c++17 -Wall -Iinclude -I"%FLEX_INC%" -c src\symtable.cpp -o symtable.o
if errorlevel 1 goto :end

"%GPP%" -x c++ -std=c++17 -Wall -Iinclude -I"%FLEX_INC%" -c sintatico.tab.c -o sintatico.tab.o
if errorlevel 1 goto :end

"%GPP%" -std=c++17 -Wall -Iinclude -I"%FLEX_INC%" -c lex.yy.cc -o lex.yy.o
if errorlevel 1 goto :end

"%GPP%" -o compilador.exe main.o ast.o symtable.o sintatico.tab.o lex.yy.o -Wl,-subsystem,console
if errorlevel 1 goto :end

echo [OK] Compilado com sucesso.

:end
endlocal