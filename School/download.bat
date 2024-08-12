@echo off
:: Set the URL and the output file name
set URL=https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev0/x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev0.7z
set OUTPUT_FILE=MinGW64.zip

:: Use curl to download the file
wget -o %OUTPUT_FILE% %URL%

:: Check if the download was successful
if %errorlevel%==0 (
    echo Download completed successfully.
) else (
    echo Download failed.
)
