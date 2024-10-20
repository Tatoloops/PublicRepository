@echo off
setlocal enabledelayedexpansion

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


:: --- Download Section ---

REM Set the URL and the output file name

set "URL=https://archive.apache.org/dist/tomcat/tomcat-10/v10.1.31/bin/apache-tomcat-10.1.31.exe"

set "OUTPUT_FILE=%myPath%\tomcatInstaller.exe"

REM Use curl to download the file with -L to follow redirects
curl -L -o "%OUTPUT_FILE%" "%URL%"

REM Check if the download was successful
if %errorlevel%==0 (
    echo Download completed successfully.
) else (
    echo Download failed.
    pause
    exit /b 1
)


:: --- Installation Section ---
REM Run the installer silently (with default options)
call "%OUTPUT_FILE%" /VERYSILENT /NORESTART /SP- /SUPPRESSMSGBOXES

:: --- Clean up ---

REM Clean up by deleting the installer
del "%OUTPUT_FILE%"

echo - mySql Installed successfully!