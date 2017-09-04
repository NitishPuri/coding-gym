:: Set environment, make env is only set once

@echo off

IF NOT DEFINED ENV_SET SET ENV_SET="0"
IF %ENV_SET%=="1" goto end

echo "Setting environment"
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
set ENV_SET="1"
goto end

:end
