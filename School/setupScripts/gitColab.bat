@echo off


setlocal enabledelayedexpansion

:: --- Retrieve Path Section ---

REM Check if an argument is provided
if "%~1"=="" (
    REM If no argument is provided, set the default value and create the directory
    set "repoPath=%USERPROFILE%\Librarium\repositories\gccBasics"
    mkdir "%USERPROFILE%\Librarium\repositories"
    if not exist "%repoPath%" (
        mkdir "%repoPath%"
    )
) else (
    REM If an argument is provided, use it
    set "repoPath=%~1"
)


REM Set your Git username and token here
set "GIT_USER=Tatoloops"
set "GIT_TOKEN=INSERT_TOKEN_HERE"

REM Set up the Git credentials using the credential helper
git config --global credential.helper store

REM Store the credentials (GitHub example)
echo https://%GIT_USER%:%GIT_TOKEN%@github.com > "%USERPROFILE%\.git-credentials"

REM Set up the repository URL (replace with your repository's URL)
set "REPO_URL=https://github.com/tatoloops/gccBasics.git"

REM Clone the repository into the specified directory
git clone "%REPO_URL%" "%repoPath%"


echo - git token added and repo gccBasics cloned!
