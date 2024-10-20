@echo off

:: --- Retrieve Path ---
REM Check if an argument is provided
if "%~1"=="" (
    REM If no argument is provided, set the default value
    set folderName=Librarium
) else (
    REM If an argument is provided, use it
    set folderName=%~1
)

if "%~2"=="" (
    REM If no argument is provided, set the default value
    set folderName=Librarium
) else (
    REM If an argument is provided, use it
    set folderName=%~1
)

:: --- Set up Directory ---

:: - Create the new folder in the user's folder
mkdir "%USERPROFILE%\%folderName%"
set myPath="%USERPROFILE%\%folderName%"


:: --- Download Essentials ---
REM 1. download mingw64 and add to path
call "%myPath%\PublicRepository-master\scripts\dependencies\mingw64\setupAuto.bat" %myPath% 

rem :: 2. install sublime text editor
call "%myPath%\PublicRepository-master\scripts\dependencies\sublimeText\setupAuto.bat" %myPath% 

rem :: 3. install git
call "%myPath%\PublicRepository-master\scripts\dependencies\git\setupAuto.bat" %myPath% 