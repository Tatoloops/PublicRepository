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

:: --- set up development path ---

::		 - Get the path to the current user's profile folder
set userFolder=%USERPROFILE%

::		 - Create the new folder in the user's folder
mkdir "%userFolder%\%folderName%"

set myPath="%userFolder%\%folderName%"

echo New folder "%folderName%" created in "%userFolder%"



:: 1. mySql
echo # --- 1. mySql ...
call "%myPath%\PublicRepository-master\scripts\dependencies\mySql_latest\setupManual.bat" %myPath% 

:: 2. tomcat 10
echo # --- 2. tomcat 10 ...
call "%myPath%\PublicRepository-master\scripts\dependencies\tomcat_10\setupManual.bat" %myPath% 

:: 3. connector 
echo # --- 2. connector ...
call "%myPath%\PublicRepository-master\scripts\packages\gatoTom\connector\connectorSetup.bat" %myPath% 

exit