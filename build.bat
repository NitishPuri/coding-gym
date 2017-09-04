:: Build the solution from cmd without opening Visual Studio.
@echo off

call env.bat

cd build
echo .

set BUILD_CFG=Release
devenv "practice-cpp.sln" /build %BUILD_CFG%

REM msbuild  build\practice-cpp.sln

echo "Build complete,.."
cd..
