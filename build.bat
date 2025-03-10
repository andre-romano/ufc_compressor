@echo off

echo build.bat - Begin

echo Configuring build ...
mkdir build
cd build
cmake --preset clang++ ..

echo Building the package...
cmake --build .
cd ..

echo build.bat - End