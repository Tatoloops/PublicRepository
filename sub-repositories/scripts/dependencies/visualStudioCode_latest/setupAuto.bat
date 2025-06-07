@echo off
setlocal enabledelayedexpansion

:: --- Retrieve Path Section ---
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

REM Set the URL and the output file name
set "URL=https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-user"
set "INSTALLER=visualStudioCodeInstaller.exe"



:: --- Download Section ---
curl -L -o "%myPath%\%INSTALLER%" "%URL%"

REM Run the installer silently (with default options)
call "%myPath%\%INSTALLER%" /VERYSILENT /NORESTART /SP- /SUPPRESSMSGBOXES

REM Check if installation was successful
if %errorlevel%==0 (
    echo Visual Studio Code installation complete.
) else (
    echo Visual Studio Code installation failed.
    pause
    exit /b 1
)



:: --- Clean up Section ---
del "%myPath%\%INSTALLER%"