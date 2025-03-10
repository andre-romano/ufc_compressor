@echo off
setlocal enabledelayedexpansion

echo Installing dependencies ...
git submodule init
git submodule update

echo Checking for ninja and cmake ...
ninja --version
cmake --version

