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

REM web
set "URL=https://downloads.mysql.com/archives/get/p/25/file/mysql-installer-web-community-8.0.39.0.msi"

REM full
rem set "URL=https://downloads.mysql.com/archives/get/p/25/file/mysql-installer-community-8.0.39.0.msi"

set "OUTPUT_FILE=%myPath%\mySqlInstaller.msi"

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
REM open the installer guide, to manually install it.
call %myPath%/PublicRepository-master/scripts/dependencies/mySql_latest/installation.md

REM Run the installer 
call "%OUTPUT_FILE%" 


:: --- Clean up ---

REM Clean up by deleting the installer
del "%OUTPUT_FILE%"

echo - mySql Installed successfully!