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

REM Open the folder in File Explorer
start "" explorer "%repoPath%"

REM Open a new console window in the folder
start "" cmd /k "cd /d %repoPath%"

REM Open the folder in Sublime Text
start "" "C:\Program Files\Sublime Text\sublime_text.exe" "%repoPath%"

echo - You are ready to start compiling in C/C++
pause