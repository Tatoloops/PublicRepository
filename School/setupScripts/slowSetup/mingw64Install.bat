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

REM Define the repository directory
set "repoPath=%myPath%\repositories"

REM Create the repository directory if it doesn't exist
if not exist "%repoPath%" (
    mkdir "%repoPath%"
)


:: --- Download Section ---

REM Set the URL and the output file name
set "URL=https://github.com/niXman/mingw-builds-binaries/releases/download/14.1.0-rt_v12-rev0/x86_64-14.1.0-release-posix-seh-ucrt-rt_v12-rev0.7z"
set "OUTPUT_FILE=%myPath%\mingw64.7z"

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

:: --- Extraction Section ---

REM Option 1: Using 7-Zip
:: Uncomment the next line to use 7-Zip for extraction
:: "C:\Program Files\7-Zip\7z.exe" x "%OUTPUT_FILE%" -o"%myPath%" -y

REM Option 2: Using WinRAR
"C:\Program Files\WinRAR\WinRAR.exe" x "%OUTPUT_FILE%" "%myPath%\" -y

REM Check if extraction was successful
if %errorlevel%==0 (
    echo Extraction completed successfully.
) else (
    echo Extraction failed.
    pause
    exit /b 1
)

rem :: --- Add MinGW bin folder to PATH ---

REM ADD TO PATH MANUALLY!!!

:: --- Clean up ---

REM Clean up by deleting the installer
del "%OUTPUT_FILE%"

echo - now add mingw64 to path manually...!

pause