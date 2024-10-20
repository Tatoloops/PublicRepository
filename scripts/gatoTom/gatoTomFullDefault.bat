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

if "%~2"=="" (
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



:: 1. mySql
echo 1. mySql ...
rem call "%myPath%\PublicRepository-master\scripts\dependencies\mySql\setupManual.bat" %myPath% 
call "%myPath%\PublicRepository-master\scripts\dependencies\mySql\setupAuto.bat" %myPath% 

rem :: 2. install sublime text editor
rem call "%myPath%\gccBasics-main\setupScripts\fastSetup\sublimeInstall.bat" %myPath% 

rem :: 3. install git
rem call "%myPath%\gccBasics-main\setupScripts\fastSetup\gitInstall.bat" %myPath% 


rem exit
