@echo off

REM Check if the required arguments are provided
if "%~1"=="" (
    echo Error: Missing repository URL.
    echo Usage: %~nx0 <repository-url> <submodule-directory>
    exit /b 1
)

if "%~2"=="" (
    echo Error: Missing submodule directory name.
    echo Usage: %~nx0 <repository-url> <submodule-directory>
    exit /b 1
)

REM Ensure the external directory exists
if not exist "external" (
    echo Creating external directory...
    mkdir external
)

REM Add the submodule
echo Adding submodule from %~1 to external\%~2...
git submodule add %~1 external\%~2

REM Check if the submodule was added successfully
if errorlevel 1 (
    echo Error: Failed to add submodule.
    exit /b %errorlevel%
)

echo Submodule added successfully.