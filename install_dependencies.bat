@echo off

echo Installing Python dependencies (Conan pkg manager) ...
pip install -r requirements.txt

echo Installing Conan dependencies ...
conan install . --build=missing

