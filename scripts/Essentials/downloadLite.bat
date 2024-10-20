@echo off


:: --- download  (curl) ---

:: curl -L -o {filename} {URL} 

curl -L -o "mingw64.7z" "https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev0/x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev0.7z"




:: --- extract (winrar) ---
::    . == %cd%
:: "path\to\WinRAR.exe" x {fileToExtract} {extractDirectory} -y

"C:\Program Files\WinRAR\WinRAR.exe" x "mingw64.7z" "%cd%" -y







:: --- set PATH (setx/set) ---

:: setx PATH "%PATH%;path\to\binaryFolder"

setx PATH "%PATH%;%cd%\mingw64\bin"


pause