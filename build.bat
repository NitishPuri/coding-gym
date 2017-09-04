REM @echo off
cd build
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
echo .

set BUILD_CFG=Release
devenv "practice-cpp.sln" /build %BUILD_CFG%

REM msbuild  build\practice-cpp.sln

echo "Build complete,.."
cd..
