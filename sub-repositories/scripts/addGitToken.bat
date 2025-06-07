echo off

REM Ask the user for their Git username, email, and token
set /p "GIT_USER=Enter your Git username: "
set /p "GIT_EMAIL=Enter your Git email: "
set /p "GIT_TOKEN=Enter your Git token: "

REM Set name & mail
git config --global user.name %GIT_USER%
git config --global user.email %GIT_EMAIL%

REM Set up the Git credentials using the credential helper
git config --global credential.helper store

REM Store the credentials (GitHub example)
echo https://%GIT_USER%:%GIT_TOKEN%@github.com > "%USERPROFILE%\.git-credentials"

REM print
echo - Git token added!