@echo off

echo.
echo build.bat - BEGIN
echo.

echo --------------
echo  Configuring
echo --------------
echo.
mkdir build
cd build
del /q *.exe
cmake --preset clang++ ..
echo.

echo -------------
echo   Compiling
echo -------------
echo.
cmake --build .
cd ..

echo.
echo build.bat - END