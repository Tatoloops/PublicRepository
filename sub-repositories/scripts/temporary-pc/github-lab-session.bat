@echo off
setlocal DisableDelayedExpansion
chcp 65001 >nul
title GitHub Lab - Sesion temporal
color 0A

cls
echo ============================================================
echo         GITHUB LAB - SESION TEMPORAL (V4)
echo ============================================================
echo.
echo Esta sesion:
echo   - NO guarda el PAT en este archivo.
echo   - NO usa setx.
echo   - NO requiere Git Credential Manager.
echo   - NO modifica tu .gitconfig global real.
echo   - Prepara Git HTTPS y agentes lanzados desde la consola.
echo.
echo IMPORTANTE:
echo   El token vive en variables de entorno de esta sesion.
echo   Cierra la consola de trabajo al terminar.
echo ============================================================
echo.

where git >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Git no esta instalado o no esta en PATH.
    echo.
    pause
    exit /b 1
)

for /f "delims=" %%V in ('git --version') do echo [OK] %%V
echo.

set /p "GIT_NAME=Nombre para commits Git: "
if not defined GIT_NAME (
    echo [ERROR] El nombre no puede quedar vacio.
    pause
    exit /b 1
)

set /p "GIT_EMAIL=Email para commits Git: "
if not defined GIT_EMAIL (
    echo [ERROR] El email no puede quedar vacio.
    pause
    exit /b 1
)

set /p "GH_USER=Usuario de GitHub: "
if not defined GH_USER (
    echo [ERROR] El usuario no puede quedar vacio.
    pause
    exit /b 1
)

echo.
echo Pega tu Fine-Grained Personal Access Token.
echo No se mostrara en pantalla.
echo.

set "GH_TOKEN="
for /f "usebackq delims=" %%T in (`powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "$s=Read-Host 'GitHub token' -AsSecureString; $b=[Runtime.InteropServices.Marshal]::SecureStringToBSTR($s); try {[Runtime.InteropServices.Marshal]::PtrToStringBSTR($b)} finally {[Runtime.InteropServices.Marshal]::ZeroFreeBSTR($b)}"`) do set "GH_TOKEN=%%T"

if not defined GH_TOKEN (
    echo.
    echo [ERROR] No se recibio ningun token.
    pause
    exit /b 1
)

rem ------------------------------------------------------------
rem Variables temporales para GitHub CLI / agentes.
rem ------------------------------------------------------------
set "GITHUB_TOKEN=%GH_TOKEN%"
set "GIT_TERMINAL_PROMPT=0"

rem Git identity is provided through environment too.
set "GIT_AUTHOR_NAME=%GIT_NAME%"
set "GIT_AUTHOR_EMAIL=%GIT_EMAIL%"
set "GIT_COMMITTER_NAME=%GIT_NAME%"
set "GIT_COMMITTER_EMAIL=%GIT_EMAIL%"

rem ------------------------------------------------------------
rem Crear un gitconfig GLOBAL TEMPORAL.
rem Esto evita tocar el .gitconfig real del usuario del laboratorio.
rem ------------------------------------------------------------
set "LAB_GITCONFIG=%TEMP%\github-lab-gitconfig-%RANDOM%-%RANDOM%.ini"

type nul > "%LAB_GITCONFIG%"
if errorlevel 1 (
    echo [ERROR] No se pudo crear el gitconfig temporal.
    goto CLEAN_FAIL
)

git config --file "%LAB_GITCONFIG%" user.name "%GIT_NAME%"
if errorlevel 1 goto CONFIG_FAIL

git config --file "%LAB_GITCONFIG%" user.email "%GIT_EMAIL%"
if errorlevel 1 goto CONFIG_FAIL

rem Empty credential.helper resets helpers inherited from lower-priority
rem config scopes (for example system Git configuration).
git config --file "%LAB_GITCONFIG%" credential.helper ""
if errorlevel 1 goto CONFIG_FAIL

git config --file "%LAB_GITCONFIG%" credential.https://github.com.username "%GH_USER%"
if errorlevel 1 goto CONFIG_FAIL

rem Tell child Git processes to use our temporary global config instead
rem of the real user-global .gitconfig.
set "GIT_CONFIG_GLOBAL=%LAB_GITCONFIG%"

rem ------------------------------------------------------------
rem Crear GIT_ASKPASS temporal SIN guardar el secreto en el archivo.
rem El helper lee GH_USER / GH_TOKEN del entorno de la sesion.
rem ------------------------------------------------------------
set "ASKPASS_FILE=%TEMP%\github-lab-askpass-%RANDOM%-%RANDOM%.cmd"

> "%ASKPASS_FILE%" echo @echo off
>>"%ASKPASS_FILE%" echo setlocal DisableDelayedExpansion
>>"%ASKPASS_FILE%" echo set "ASKPASS_PROMPT=%%~1"
>>"%ASKPASS_FILE%" echo echo(%%ASKPASS_PROMPT%% ^| findstr /I /C:"username" /C:"user name" ^>nul
>>"%ASKPASS_FILE%" echo if not errorlevel 1 ^(
>>"%ASKPASS_FILE%" echo     echo(%%GH_USER%%
>>"%ASKPASS_FILE%" echo     exit /b 0
>>"%ASKPASS_FILE%" echo ^)
>>"%ASKPASS_FILE%" echo echo(%%GH_TOKEN%%

if not exist "%ASKPASS_FILE%" (
    echo.
    echo [ERROR] No se pudo crear GIT_ASKPASS temporal.
    goto CLEAN_FAIL
)

set "GIT_ASKPASS=%ASKPASS_FILE%"

rem ------------------------------------------------------------
rem Validacion del token por la API de GitHub.
rem ------------------------------------------------------------
echo.
echo Verificando el token con GitHub...
set "AUTH_USER="

for /f "usebackq delims=" %%U in (`powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "try { $h=@{Authorization=('Bearer ' + $env:GH_TOKEN); Accept='application/vnd.github+json'; 'X-GitHub-Api-Version'='2022-11-28'; 'User-Agent'='github-lab-session'}; (Invoke-RestMethod -Headers $h -Uri 'https://api.github.com/user' -Method Get).login } catch { exit 1 }"`) do set "AUTH_USER=%%U"

if not defined AUTH_USER (
    echo.
    echo [ERROR] GitHub rechazo el token o no fue posible conectar.
    echo.
    echo Comprueba que:
    echo   - sea un token NUEVO y no revocado;
    echo   - tenga acceso al repositorio necesario;
    echo   - el PC tenga acceso HTTPS a github.com.
    echo.
    goto CLEAN_FAIL
)

echo [OK] Token valido. Cuenta autenticada: %AUTH_USER%

if /I not "%AUTH_USER%"=="%GH_USER%" (
    echo.
    echo [AVISO] Ingresaste "%GH_USER%" pero el token pertenece a "%AUTH_USER%".
    echo         Se utilizara "%AUTH_USER%".
    set "GH_USER=%AUTH_USER%"
    git config --file "%LAB_GITCONFIG%" credential.https://github.com.username "%AUTH_USER%"
)

rem ------------------------------------------------------------
rem Sanity check local de Git ANTES de abrir la consola.
rem ------------------------------------------------------------
echo.
echo Comprobando configuracion temporal de Git...

git config --global --get user.name >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Git no puede leer el gitconfig temporal.
    goto CLEAN_FAIL
)

echo [OK] Configuracion Git temporal funcional.
echo.

echo ============================================================
echo               CONSOLA DE TRABAJO LISTA
echo ============================================================
echo Cuenta GitHub : %GH_USER%
echo Nombre Git    : %GIT_NAME%
echo Email Git     : %GIT_EMAIL%
echo.
echo Desde la nueva consola puedes ejecutar:
echo.
echo   git status
echo   git pull
echo   git push
echo   git fetch
echo   git clone https://github.com/%GH_USER%/REPOSITORIO.git
echo.
echo Tambien puedes iniciar tu agente desde esa consola.
echo Este heredara GH_TOKEN, GITHUB_TOKEN y GIT_ASKPASS.
echo.
echo Para terminar la sesion escribe:
echo.
echo   exit
echo.
echo en la consola de trabajo.
echo ============================================================
echo.

start "GitHub Lab - Trabajo" /wait cmd.exe /k "title GitHub Lab - Trabajo [%GH_USER%] && echo. && echo ============================================ && echo SESION GITHUB TEMPORAL ACTIVA - V4 && echo ============================================ && echo Cuenta: %GH_USER% && echo. && echo Prueba: git status  ^&  git push && echo. && echo Inicia aqui tambien tu agente si lo necesitas. && echo Para terminar, escribe EXIT. && echo."

echo.
echo La consola de trabajo fue cerrada.
goto CLEAN_OK


:CONFIG_FAIL
echo.
echo [ERROR] No se pudo construir el gitconfig temporal.
goto CLEAN_FAIL


:CLEAN_FAIL
echo.
echo Limpiando la sesion fallida...
if defined ASKPASS_FILE del /q "%ASKPASS_FILE%" >nul 2>&1
if defined LAB_GITCONFIG del /q "%LAB_GITCONFIG%" >nul 2>&1
set "GH_TOKEN="
set "GITHUB_TOKEN="
set "GH_USER="
set "GIT_ASKPASS="
set "GIT_TERMINAL_PROMPT="
set "GIT_CONFIG_GLOBAL="
set "GIT_AUTHOR_NAME="
set "GIT_AUTHOR_EMAIL="
set "GIT_COMMITTER_NAME="
set "GIT_COMMITTER_EMAIL="
set "AUTH_USER="
echo [OK] Limpieza completada.
echo.
pause
endlocal
exit /b 1


:CLEAN_OK
echo Limpiando credenciales temporales...

if defined ASKPASS_FILE del /q "%ASKPASS_FILE%" >nul 2>&1
if defined LAB_GITCONFIG del /q "%LAB_GITCONFIG%" >nul 2>&1

set "GH_TOKEN="
set "GITHUB_TOKEN="
set "GH_USER="
set "GIT_ASKPASS="
set "GIT_TERMINAL_PROMPT="
set "GIT_CONFIG_GLOBAL="
set "GIT_AUTHOR_NAME="
set "GIT_AUTHOR_EMAIL="
set "GIT_COMMITTER_NAME="
set "GIT_COMMITTER_EMAIL="
set "AUTH_USER="

echo [OK] GIT_ASKPASS temporal eliminado.
echo [OK] gitconfig temporal eliminado.
echo [OK] Variables de esta sesion limpiadas.
echo.
echo Si el PAT fue creado exclusivamente para este laboratorio,
echo revocalo desde GitHub al finalizar el dia.
echo.
pause
endlocal
exit /b 0
