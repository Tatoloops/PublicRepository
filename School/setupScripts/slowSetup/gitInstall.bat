@echo off

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

echo The path is: %repoPath%


echo Git is not installed. Downloading and installing Git...

REM Define the URL for the Git installer (Windows 64-bit or 32-bit based on your system)
set "GIT_URL=https://github.com/git-for-windows/git/releases/download/v2.46.0.windows.1/Git-2.46.0-64-bit.exe"

REM Define the file name for the installer
set "GIT_INSTALLER=git-installer.exe"

REM Download the Git installer using curl
curl -L -o "%myPath%\%GIT_INSTALLER%" "%GIT_URL%"

REM Run the installer silently (with default options)
call "%myPath%\%GIT_INSTALLER%"


REM Clean up by deleting the installer
:: del "%myPath%\%GIT_INSTALLER%"

echo - Git installation complete.