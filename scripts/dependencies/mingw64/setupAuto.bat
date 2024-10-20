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
    if not exist "%myPath%" (
        mkdir "%myPath%"
    )
)


REM DOWNLOAD
REM Set the URL and the output file name
set "URL=https://github.com/niXman/mingw-builds-binaries/releases/download/14.2.0-rt_v12-rev0/x86_64-14.2.0-release-posix-seh-ucrt-rt_v12-rev0.7z"
set "OUTPUT_FILE=%myPath%\mingw64.7z"

REM EXTRACTION
REM paths variables
set "SEVEN_ZIP_PATH=C:\Program Files\7-Zip\7z.exe"
set "WINRAR_PATH=C:\Program Files\WinRAR\WinRAR.exe"

REM Binaries paths variable
set "MINGW_BIN=%myPath%\mingw64\bin"



:: --- Download Section ---
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

REM Check if 7-Zip is installed and use it for extraction if available
if exist "%SEVEN_ZIP_PATH%" (
    echo 7-Zip found. Using it for extraction.
    "%SEVEN_ZIP_PATH%" x "%OUTPUT_FILE%" -o"%myPath%" -y
    set "EXTRACTION_TOOL=7-Zip"
) else if exist "%WINRAR_PATH%" (
    echo WinRAR found. Using it for extraction.
    "%WINRAR_PATH%" x "%OUTPUT_FILE%" "%myPath%\" -y
    set "EXTRACTION_TOOL=WinRAR"
) else (
    echo Neither 7-Zip nor WinRAR found in the default installation directories.
    echo Please install one of them or specify the correct path.
    pause
    exit /b 1
)

REM Check if extraction was successful
if %errorlevel%==0 (
    echo Extraction completed successfully using %EXTRACTION_TOOL%.
) else (
    echo Extraction failed.
    pause
    exit /b 1
)


:: --- Add MinGW bin folder to PATH ---

:: get USER PATH
for /f "tokens=2* delims= " %%a in ('reg query "HKCU\Environment" /v PATH') do set "USER_PATH=%%b"
echo User PATH: %USER_PATH%

REM Check if the bin folder exists
if exist "%MINGW_BIN%" (
    echo Bin folder found: %MINGW_BIN%
    REM Add the bin folder to PATH
    set "NEW_PATH=%USER_PATH%;%MINGW_BIN%"
    setx PATH "%NEW_PATH%"

    REM Confirm the addition to PATH
    if %errorlevel%==0 (
        echo Bin folder added to PATH successfully.
    ) else (
        echo Failed to add bin folder to PATH.
        pause
        exit /b 1
    )
) else (
    echo Bin folder not found: %MINGW_BIN%
    echo Ensure that the extraction was successful and the folder structure is correct.
    pause
    exit /b 1
)


:: --- Clean up ---

REM Clean up by deleting the installer
del "%OUTPUT_FILE%"

echo - Mingw64 added successfully!
