@echo off

:: --- Create Librarium Folder ---
set folderName=Librarium
mkdir "%USERPROFILE%\%folderName%"

:: --- Set variables ---
set myPath=%USERPROFILE%\%folderName%
set myRepo=https://github.com/Tatoloops/PublicRepository/archive/refs/heads/master.zip
set fileToExtract=%myPath%\PublicRepository.zip

:: --- Download repository ---
curl -L -o "%fileToExtract%" %myRepo%

:: --- Extract repository ---
powershell -command "Expand-Archive -Path '%fileToExtract%' -DestinationPath '%myPath%' -Force"

:: --- Execute main script ---
call "%myPath%\PublicRepository-master\scripts\packages\Essentials\EssentialsDefault.bat" %folderName%

:: --- Clean up ---
del "%fileToExtract%"
rd /s /q "%myPath%\PublicRepository-master\"