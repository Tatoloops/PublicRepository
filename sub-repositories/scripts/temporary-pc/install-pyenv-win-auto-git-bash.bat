@echo off
setlocal EnableExtensions DisableDelayedExpansion
chcp 65001 >nul
title pyenv-win - Configuracion automatica para Git Bash

set "PYENV_REPO=https://github.com/pyenv-win/pyenv-win.git"
set "PYENV_BASE=%USERPROFILE%\.pyenv"
set "PYENV_WIN=%PYENV_BASE%\pyenv-win"
set "HOME_PROBE=%TEMP%\pyenv-win-home-%RANDOM%-%RANDOM%.txt"

cls
echo ============================================================
echo      PYENV-WIN - INSTALADOR PARA GIT BASH
echo ============================================================
echo.
echo Este script:
echo   - localiza Git for Windows automaticamente;
echo   - localiza bash.exe sin asumir C:\Program Files\Git;
echo   - descarga pyenv-win en %%USERPROFILE%%\.pyenv;
echo   - detecta el HOME REAL utilizado por Git Bash;
echo   - configura ~/.bash_profile;
echo   - NO cambia la variable HOME;
echo   - NO usa PowerShell;
echo   - NO instala Python todavia.
echo.
echo ============================================================
echo.

rem ------------------------------------------------------------
rem 1. Encontrar Git
rem ------------------------------------------------------------
where git >nul 2>&1
if errorlevel 1 (
    echo [ERROR] No encontre git.exe en PATH.
    echo Instala Git for Windows o abre una terminal donde Git funcione.
    echo.
    pause
    exit /b 1
)

echo [OK] Git encontrado:
git --version
echo.

rem ------------------------------------------------------------
rem 2. Encontrar la raiz real de Git for Windows / bash.exe.
rem    Soporta git.exe desde:
rem      ^<Git^>\cmd\git.exe
rem      ^<Git^>\bin\git.exe
rem      ^<Git^>\mingw64\bin\git.exe
rem      instalaciones portables equivalentes
rem ------------------------------------------------------------
set "GIT_ROOT="
set "BASH_EXE="
set "GIT_BASH_EXE="

for /f "delims=" %%G in ('where git 2^>nul') do (
    if not defined BASH_EXE call :TRY_GIT_PATH "%%G"
)

rem Fallbacks habituales, solo si where git no permitio inferirlo.
if not defined BASH_EXE if exist "%ProgramFiles%\Git\bin\bash.exe" (
    set "GIT_ROOT=%ProgramFiles%\Git"
    set "BASH_EXE=%ProgramFiles%\Git\bin\bash.exe"
    set "GIT_BASH_EXE=%ProgramFiles%\Git\git-bash.exe"
)

if not defined BASH_EXE if exist "%LocalAppData%\Programs\Git\bin\bash.exe" (
    set "GIT_ROOT=%LocalAppData%\Programs\Git"
    set "BASH_EXE=%LocalAppData%\Programs\Git\bin\bash.exe"
    set "GIT_BASH_EXE=%LocalAppData%\Programs\Git\git-bash.exe"
)

if not defined BASH_EXE (
    echo [ERROR] Git funciona, pero no pude localizar bin\bash.exe.
    echo.
    echo Rutas de git.exe encontradas:
    where git
    echo.
    pause
    exit /b 1
)

echo [OK] Git for Windows:
echo      %GIT_ROOT%
echo.
echo [OK] Bash:
echo      %BASH_EXE%
echo.

rem ------------------------------------------------------------
rem 3. Instalar / detectar pyenv-win.
rem    pyenv-win recomienda clonar en %%USERPROFILE%%\.pyenv
rem    cuando se ejecuta desde Command Prompt.
rem ------------------------------------------------------------
if exist "%PYENV_WIN%\bin\pyenv" (
    echo [OK] pyenv-win ya esta instalado:
    echo      %PYENV_WIN%
    echo.
) else (
    if exist "%PYENV_BASE%" (
        echo [ERROR] Existe esta carpeta:
        echo      %PYENV_BASE%
        echo.
        echo pero no contiene una instalacion valida de pyenv-win.
        echo No la eliminare automaticamente.
        echo.
        pause
        exit /b 1
    )

    echo Descargando pyenv-win desde GitHub...
    echo.
    git clone "%PYENV_REPO%" "%PYENV_BASE%"

    if errorlevel 1 (
        echo.
        echo [ERROR] git clone fallo.
        echo.
        pause
        exit /b 1
    )

    if not exist "%PYENV_WIN%\bin\pyenv" (
        echo.
        echo [ERROR] El repositorio se descargo, pero falta:
        echo      %PYENV_WIN%\bin\pyenv
        echo.
        pause
        exit /b 1
    )

    echo.
    echo [OK] pyenv-win descargado correctamente.
    echo.
)

rem ------------------------------------------------------------
rem 4. Preguntarle AL PROPIO BASH cual es su HOME.
rem    No asumimos que HOME == USERPROFILE.
rem    Ejemplo real del laboratorio:
rem      USERPROFILE=C:\Users\USS
rem      HOME=/c/VULCAN~1
rem ------------------------------------------------------------
del /q "%HOME_PROBE%" >nul 2>&1

"%BASH_EXE%" --noprofile --norc -lc "cd ~ && pwd -W" > "%HOME_PROBE%" 2>nul

if errorlevel 1 (
    echo [ERROR] No pude consultar el HOME de Git Bash.
    del /q "%HOME_PROBE%" >nul 2>&1
    echo.
    pause
    exit /b 1
)

set "BASH_HOME_WIN="
set /p "BASH_HOME_WIN="<"%HOME_PROBE%"
del /q "%HOME_PROBE%" >nul 2>&1

if not defined BASH_HOME_WIN (
    echo [ERROR] Git Bash devolvio un HOME vacio.
    echo.
    pause
    exit /b 1
)

rem Git Bash puede devolver C:/ruta; CMD acepta la mayoria de rutas,
rem pero normalizamos a backslashes para operaciones de archivos.
set "BASH_HOME_WIN=%BASH_HOME_WIN:/=\%"
set "BASH_PROFILE=%BASH_HOME_WIN%\.bash_profile"

echo [OK] HOME real de Git Bash:
echo      %BASH_HOME_WIN%
echo.
echo [INFO] Perfil que se configurara:
echo        %BASH_PROFILE%
echo.

rem ------------------------------------------------------------
rem 5. Backup del perfil existente.
rem ------------------------------------------------------------
if exist "%BASH_PROFILE%" (
    copy /Y "%BASH_PROFILE%" "%BASH_PROFILE%.pyenv-win-backup" >nul
    if errorlevel 1 (
        echo [ERROR] No pude crear backup de:
        echo      %BASH_PROFILE%
        echo.
        pause
        exit /b 1
    )

    echo [OK] Backup:
    echo      %BASH_PROFILE%.pyenv-win-backup
    echo.
)

rem ------------------------------------------------------------
rem 6. Agregar configuracion una sola vez.
rem
rem IMPORTANTE:
rem No usamos $HOME para localizar pyenv porque en algunos PCs
rem corporativos HOME puede apuntar a otro directorio.
rem USERPROFILE contiene C:\Users\usuario; cygpath lo convierte
rem correctamente a /c/Users/usuario dentro de Git Bash.
rem ------------------------------------------------------------
findstr /C:"# >>> pyenv-win auto >>>" "%BASH_PROFILE%" >nul 2>&1
if not errorlevel 1 (
    echo [INFO] El bloque pyenv-win ya existe en ~/.bash_profile.
    echo        No se duplicara.
    echo.
    goto VERIFY
)

>>"%BASH_PROFILE%" echo.
>>"%BASH_PROFILE%" echo # ^>^>^> pyenv-win auto ^>^>^>
>>"%BASH_PROFILE%" echo PYENV_WIN_USER_HOME="$^(cygpath -u "$USERPROFILE"^)"
>>"%BASH_PROFILE%" echo export PYENV="$PYENV_WIN_USER_HOME/.pyenv/pyenv-win"
>>"%BASH_PROFILE%" echo export PYENV_ROOT="$PYENV"
>>"%BASH_PROFILE%" echo export PYENV_HOME="$PYENV"
>>"%BASH_PROFILE%" echo export PATH="$PYENV/bin:$PYENV/shims:$PATH"
>>"%BASH_PROFILE%" echo # ^<^<^< pyenv-win auto ^<^<^<

if errorlevel 1 (
    echo [ERROR] No pude modificar:
    echo      %BASH_PROFILE%
    echo.
    pause
    exit /b 1
)

echo [OK] ~/.bash_profile configurado.
echo.

:VERIFY
rem ------------------------------------------------------------
rem 7. Verificar desde un LOGIN SHELL nuevo.
rem    -l hace que Bash cargue ~/.bash_profile.
rem ------------------------------------------------------------
echo Verificando pyenv desde Git Bash...
echo.

"%BASH_EXE%" -lc "command -v pyenv && pyenv --version"

if errorlevel 1 (
    echo.
    echo [ERROR] pyenv-win esta instalado pero Bash aun no lo resuelve.
    echo.
    echo Diagnostico:
    echo   pyenv-win : %PYENV_WIN%
    echo   Bash HOME : %BASH_HOME_WIN%
    echo   Perfil    : %BASH_PROFILE%
    echo.
    echo Revisa el backup:
    echo   %BASH_PROFILE%.pyenv-win-backup
    echo.
    pause
    exit /b 1
)

echo.
echo ============================================================
echo                    TODO LISTO
echo ============================================================
echo.
echo pyenv-win esta instalado y configurado para Git Bash.
echo.
echo Abre/reabre Git Bash y prueba:
echo.
echo   pyenv --version
echo   pyenv install -l ^| grep "3\.12"
echo.
echo Para instalar Python:
echo.
echo   pyenv install 3.12.10
echo.
echo Para PuzzlePress:
echo.
echo   cd ~/Development/repositories/PuzzlePress
echo   pyenv local 3.12.10
echo   python --version
echo.
echo Si existe un .venv antiguo:
echo.
echo   rm -rf .venv
echo   python -m venv .venv
echo   source .venv/Scripts/activate
echo.
echo ============================================================
echo.

rem ------------------------------------------------------------
rem 8. Abrir Git Bash nuevo si git-bash.exe existe.
rem ------------------------------------------------------------
if exist "%GIT_BASH_EXE%" (
    choice /C SN /N /M "Abrir Git Bash ahora? [S/N]: "
    if errorlevel 2 goto END
    if errorlevel 1 start "" "%GIT_BASH_EXE%"
)

:END
echo.
pause
endlocal
exit /b 0


rem ============================================================
rem SUBRUTINA: probar una ruta devuelta por "where git"
rem ============================================================
:TRY_GIT_PATH
set "CAND_GIT=%~1"

rem Caso comun: <Git>\cmd\git.exe o <Git>\bin\git.exe
for %%D in ("%~dp1..") do set "CAND_ROOT=%%~fD"
if exist "%CAND_ROOT%\bin\bash.exe" (
    set "GIT_ROOT=%CAND_ROOT%"
    set "BASH_EXE=%CAND_ROOT%\bin\bash.exe"
    if exist "%CAND_ROOT%\git-bash.exe" set "GIT_BASH_EXE=%CAND_ROOT%\git-bash.exe"
    exit /b 0
)

rem Caso posible: <Git>\mingw64\bin\git.exe / <Git>\usr\bin\git.exe
for %%D in ("%~dp1..\..") do set "CAND_ROOT=%%~fD"
if exist "%CAND_ROOT%\bin\bash.exe" (
    set "GIT_ROOT=%CAND_ROOT%"
    set "BASH_EXE=%CAND_ROOT%\bin\bash.exe"
    if exist "%CAND_ROOT%\git-bash.exe" set "GIT_BASH_EXE=%CAND_ROOT%\git-bash.exe"
    exit /b 0
)

exit /b 0
