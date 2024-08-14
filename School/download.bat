@echo off

:: --- Download Section ---

:: Set the URL and the output file name
set URL=https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev0/x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev0.7z
set OUTPUT_FILE=mingw64.7z
set EXTRACT_DIR=%cd%

:: Use curl to download the file with -L to follow redirects
curl -L -o %OUTPUT_FILE% %URL%

:: Check if the download was successful
if %errorlevel%==0 (
    echo Download completed successfully.
) else (
    echo Download failed.
    pause
    exit /b 1
)

:: --- Extraction Section ---

:: Option 1: Using 7-Zip
:: Uncomment the next line to use 7-Zip for extraction
"C:\Program Files\7-Zip\7z.exe" x %OUTPUT_FILE% -o%EXTRACT_DIR% -y

:: Option 2: Using WinRAR
:: Uncomment the next line to use WinRAR for extraction
:: "C:\Program Files\WinRAR\WinRAR.exe" x %OUTPUT_FILE% %EXTRACT_DIR%\ -y

:: Check if extraction was successful
if %errorlevel%==0 (
    echo Extraction completed successfully.
) else (
    echo Extraction failed.
    pause
    exit /b 1
)

:: --- Add MinGW bin folder to PATH ---

:: Navigate to the bin folder
set MINGW_BIN=%EXTRACT_DIR%\mingw64\bin

:: Check if the bin folder exists
if exist "%MINGW_BIN%" (
    echo Bin folder found: %MINGW_BIN%
    :: Add the bin folder to PATH
    setx PATH "%PATH%;%MINGW_BIN%"

    :: Confirm the addition to PATH
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

pause
