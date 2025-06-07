@echo off
setlocal

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


:: --- Ask User for Programs to Install ---
set install_mingw=n
set install_sublime=n
set install_vscode=n
set install_git=n
set install_nodejs=n
set install_angular=n

echo Do you want to install MinGW64? (y/n)
set /p install_mingw=

echo Do you want to install Sublime Text? (y/n)
set /p install_sublime=

echo Do you want to install Visual Studio Code? (y/n)
set /p install_vscode=

echo Do you want to install Git? (y/n)
set /p install_git=

echo Do you want to install NodeJS? (y/n)
set /p install_nodeJs=

if /I "%install_nodejs%"=="y" (
    echo "Do you want to install Angular CLI? (y/n)"
    set /p install_angular=
    )


:: --- Download Essentials Based on User Choice ---
if /I "%install_mingw%"=="y" call "%myPath%\PublicRepository-master\scripts\dependencies\mingw64_latest\setupAuto.bat" "%myPath%" 
if /I "%install_sublime%"=="y" call "%myPath%\PublicRepository-master\scripts\dependencies\sublimeText_latest\setupAuto.bat" "%myPath%" 
if /I "%install_vscode%"=="y" call "%myPath%\PublicRepository-master\scripts\dependencies\visualStudioCode_latest\setupAuto.bat" "%myPath%" 
if /I "%install_git%"=="y" call "%myPath%\PublicRepository-master\scripts\dependencies\git_latest\setupAuto.bat" "%myPath%" 
if /I "%install_nodeJs%"=="y" call "%myPath%\PublicRepository-master\scripts\dependencies\nodejs_latest\setupAuto.bat" "%myPath%"
if /I "%install_angular%"=="y" call "%myPath%\PublicRepository-master\scripts\dependencies\nodejs_latest\angularcli_latest\setupAuto.bat" "%myPath%"

:: --- New Console ---
set temp_script=%myPath%\PublicRepository-master\scripts\addGitToken.bat

:: If addGitToken.bat exists, append commands instead of overwriting
if not exist "%temp_script%" (
    echo @echo off > "%temp_script%"
)

(
    echo echo Nueva consola iniciada...
    echo REM Aquí puedes colocar los comandos que quieres ejecutar después del reinicio
    echo pause
) >> "%temp_script%"

:: Open a new console and execute the script
start cmd /k "%temp_script%"
exit