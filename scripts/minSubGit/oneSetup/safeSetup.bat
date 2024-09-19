@echo off

:: - Create the new folder in the user's folder
set folderName=Librarium
mkdir "%USERPROFILE%\%folderName%"

:: Set variables
set myPath=%USERPROFILE%\%folderName%
set myRepo=https://github.com/Tatoloops/gccBasics/archive/refs/heads/main.zip
set fileToExtract=%myPath%\repo.zip

:: Download repository
curl -L -o "%fileToExtract%" %myRepo%

:: Extract the zip file using the built-in File Explorer
powershell -command "Expand-Archive -Path '%fileToExtract%' -DestinationPath '%myPath%' -Force"

:: Execute main script
call "%myPath%\gccBasics-main\setupScripts\setupSAFE.bat" %folderName%