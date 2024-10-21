# Path variable configurations settings

:: --- get ---

:: get USER PATH
for /f "tokens=2* delims= " %%a in ('reg query "HKCU\Environment" /v PATH') do set "USER_PATH=%%b"
:: get SYSTEM PATH (not tested)
for /f "tokens=2* delims= " %%a in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v PATH') do set "SYSTEM_PATH=%%b"


:: --- set ---

:: set USER PATH
setx PATH "%USER_PATH%;%MINGW_BIN%"
:: set SYSTEM PATH (not tested)
setx PATH "%SYSTEM_PATH%;%MINGW_BIN%" /m


:: --- print ---

:: print USER PATH
echo User PATH: %USER_PATH%
:: print SYSTEM PATH
echo System PATH: %SYSTEM_PATH%