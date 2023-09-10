@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
    echo Please provide a folder name.
    exit /b 1
)
set "folderPath=.\cpp\%~1"
mkdir "%folderPath%"

copy ".\Solution.cpp" "%folderPath%" 

code -a "%folderPath%\Solution.cpp"
echo Folder and Solution.cpp created in: %folderPath%
exit /b 0
