:: Generate visual studio solution files from the cmake lists.
@echo off

cd build

If exist CMakeCache.txt del CMakeCache.txt

cmake -G "Visual Studio 14 2015 Win64" ..
cd ..