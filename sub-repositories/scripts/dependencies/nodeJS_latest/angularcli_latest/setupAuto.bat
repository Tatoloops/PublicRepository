@echo off

:: --- New Console ---
set temp_script=%myPath%\PublicRepository-master\scripts\dependencies\nodeJS_latest\angularcli_latest\angularcli.bat

:: If angularcli.bat exists, append commands instead of overwriting
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