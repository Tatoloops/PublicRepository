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
set "SUBLIME_URL=https://download.sublimetext.com/sublime_text_build_4180_x64_setup.exe"
set "SUBLIME_INSTALLER=SublimeTextInstaller.exe"



:: --- Download Section ---
curl -L -o "%myPath%\%SUBLIME_INSTALLER%" "%SUBLIME_URL%"

REM Run the installer silently (with default options)
call "%myPath%\%SUBLIME_INSTALLER%" /VERYSILENT /NORESTART /SP- /SUPPRESSMSGBOXES

REM Check if installation was successful
if %errorlevel%==0 (
    echo Sublime Text installation complete.
) else (
    echo Sublime Text installation failed.
    pause
    exit /b 1
)



:: --- Clean up Section ---
del "%myPath%\%SUBLIME_INSTALLER%"