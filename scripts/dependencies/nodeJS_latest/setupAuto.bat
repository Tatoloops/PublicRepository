@echo off
setlocal enabledelayedexpansion

:: --- Retrieve Path Section ---
if "%~1"=="" (
    REM If no argument is provided, set the default value and create the directory
    set "myPath=%USERPROFILE%\Librarium"
    if not exist "%myPath%" mkdir "%myPath%"
) else (
    REM If an argument is provided, use it
    set "myPath=%~1"
)

REM Set the URL and the output file name
set "URL=https://nodejs.org/dist/v22.14.0/node-v22.14.0-x64.msi"
set "INSTALLER=%myPath%\node-v22.14.0-x64.msi"

:: --- Download Section ---
echo Downloading Node.js installer...
curl -L -o "%INSTALLER%" "%URL%"
if not exist "%INSTALLER%" (
    echo Error: Failed to download Node.js installer.
    pause
    exit /b 1
)

:: --- Run the installer silently ---
echo Installing Node.js...
msiexec /i "%INSTALLER%" /qn /norestart /log "%myPath%\install_log.txt"

:: --- Wait for installation to complete ---
timeout /t 5 /nobreak >nul

:: --- Verify installation ---
where node >nul 2>nul
if %errorlevel%==0 (
    echo NodeJS installation complete.
    node -v
) else (
    echo NodeJS installation failed. Check install_log.txt for details.
    pause
    exit /b 1
)

:: --- Clean up Section ---
del "%INSTALLER%"

pause
