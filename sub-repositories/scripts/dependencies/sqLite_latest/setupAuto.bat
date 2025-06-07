@echo off

:: --- Retrieve Paths & Set variables Section ---

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

REM set variables
set URL=https://www.sqlite.org/2024/sqlite-tools-win-x64-3470000.zip
set fileToExtract=%myPath%\sqlite.zip

:: --- Download repository ---
curl -L -o "%fileToExtract%" %URL%

:: --- Extract repository ---
powershell -command "Expand-Archive -Path '%fileToExtract%' -DestinationPath '%myPath%' -Force"

:: --- Execute main script ---


:: --- Clean up ---
del "%fileToExtract%"
rem rd /s /q "%myPath%\sqlite-dll-win-x64-3470000\"