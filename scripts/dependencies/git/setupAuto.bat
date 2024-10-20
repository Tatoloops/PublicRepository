@echo off

:: --- Retrieve Path Section ---

REM Check if an argument is provided
if "%~1"=="" (
    REM If no argument is provided, set the default value and create the directory
    set "myPath=%USERPROFILE%\Librarium"
    if not exist "%myPath%" (
        mkdir "%myPath%"
    )
) else (
    REM If an argument is provided, use it
    set "myPath=%~1"
)

REM Define URL and installer name (custom)
set "GIT_URL=https://github.com/git-for-windows/git/releases/download/v2.46.0.windows.1/Git-2.46.0-64-bit.exe"
set "GIT_INSTALLER=git-installer.exe"



:: --- Download Section ---

Rem Download installer
curl -L -o "%myPath%\%GIT_INSTALLER%" "%GIT_URL%"



:: --- Installation Section ---

Rem install in very silent mode
call "%myPath%\%GIT_INSTALLER%" /VERYSILENT 



:: --- Clean up Section ---

Rem delete Installer
del "%myPath%\%GIT_INSTALLER%"