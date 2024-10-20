@echo off

REM Welcome to the course, this scrip will download all neccesary files, just click next and accept everything.

echo executing script

REM Check if an argument is provided
if "%~1"=="" (
    REM If no argument is provided, set the default value
    set folderName=Librarium
) else (
    REM If an argument is provided, use it
    set folderName=%~1
)

:: 1. set up development path

::		 - Get the path to the current user's profile folder
set userFolder=%USERPROFILE%

::		 - Create the new folder in the user's folder
mkdir "%userFolder%\%folderName%"

set myPath="%userFolder%\%folderName%"

echo New folder "%folderName%" created in "%userFolder%"


:: 1. download mingw64 and add to path
call "%myPath%\gccBasics-main\setupScripts\slowSetup\mingw64Install.bat" %myPath% 

:: 2. install sublime text editor
call "%myPath%\gccBasics-main\setupScripts\slowSetup\sublimeInstall.bat" %myPath% 

:: 3. install git
call "%myPath%\gccBasics-main\setupScripts\slowSetup\gitInstall.bat" %myPath% 
