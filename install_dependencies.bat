@echo off
setlocal enabledelayedexpansion

echo Installing Conan package manager ...
pip install -r requirements.txt

echo Installing Conan dependencies ...
conan install . --build=missing

echo Adding Conan to system PATH env ...
call .\conanbuild.bat 
setx PATH "!PATH!"

echo Checking for ninja and cmake ...
ninja --version
cmake --version
