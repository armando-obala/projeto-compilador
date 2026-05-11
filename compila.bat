@echo off
setlocal

set "WIN_BISON=win_bison"
set "WIN_FLEX=win_flex"
set "FLEX_INC=C:\winflexbison"
if not exist "%FLEX_INC%\FlexLexer.h" (
	set "FLEX_INC=%LOCALAPPDATA%\Microsoft\WinGet\Packages\WinFlexBison.win_flex_bison_Microsoft.Winget.Source_8wekyb3d8bbwe"
	set "WIN_BISON=%LOCALAPPDATA%\Microsoft\WinGet\Packages\WinFlexBison.win_flex_bison_Microsoft.Winget.Source_8wekyb3d8bbwe\win_bison.exe"
	set "WIN_FLEX=%LOCALAPPDATA%\Microsoft\WinGet\Packages\WinFlexBison.win_flex_bison_Microsoft.Winget.Source_8wekyb3d8bbwe\win_flex.exe"
)
if not exist "%FLEX_INC%\FlexLexer.h" (
	echo [ERRO] FlexLexer.h nao encontrado.
	echo [DICA] Reinstale winflexbison ou ajuste FLEX_INC no compila.bat.
	goto :end
)

"%WIN_BISON%" -d sintatico.y
if errorlevel 1 goto :end

"%WIN_FLEX%" lexico.l
if errorlevel 1 goto :end

set "GPP=g++"
where g++ >nul 2>nul
if errorlevel 1 (
	if exist "C:\msys64\ucrt64\bin\g++.exe" (
		set "GPP=C:\msys64\ucrt64\bin\g++.exe"
	) else (
		echo [ERRO] g++ nao encontrado no PATH.
		echo [DICA] Instale MSYS2 UCRT64 e/ou adicione C:\msys64\ucrt64\bin no PATH.
		goto :end
	)
)

"%GPP%" -std=c++17 -Wall -static -static-libgcc -static-libstdc++ -Iinclude -I"%FLEX_INC%" -o compilador sintatico.tab.c lex.yy.cc src/main.cpp src/ast.cpp src/symtable.cpp
if errorlevel 1 goto :end

if exist "C:\msys64\ucrt64\bin\libstdc++-6.dll" copy /Y "C:\msys64\ucrt64\bin\libstdc++-6.dll" ".\" >nul
if exist "C:\msys64\ucrt64\bin\libgcc_s_seh-1.dll" copy /Y "C:\msys64\ucrt64\bin\libgcc_s_seh-1.dll" ".\" >nul
if exist "C:\msys64\ucrt64\bin\libwinpthread-1.dll" copy /Y "C:\msys64\ucrt64\bin\libwinpthread-1.dll" ".\" >nul

:end
endlocal