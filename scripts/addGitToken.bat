@echo off

REM Set your Git username and token here
set "GIT_USER=|-|-|-INSERT_username_HERE-|-|-|"
set "GIT_EMAIL=|-|-|-INSERT_email_HERE-|-|-|"
set "GIT_TOKEN=|-|-|-INSERT_token_HERE-|-|-|"

REM set name & mail
git config --global user.name %GIT_USER%
git config --global user.email %GIT_MAIL%

REM Set up the Git credentials using the credential helper
git config --global credential.helper store

REM Store the credentials (GitHub example)
echo https://%GIT_USER%:%GIT_TOKEN%@github.com > "%USERPROFILE%\.git-credentials"

echo - git token added!