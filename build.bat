@echo off

echo build.bat - Begin

echo Configuring build ...
mkdir build
cd build
cmake -G "Ninja" -DCMAKE_CXX_COMPILER=clang++ ..

echo Building the package...
cmake --build .
cd ..

echo build.bat - End