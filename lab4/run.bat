@echo off
echo ========================================
echo Compiling project...
echo ========================================

g++ main.cpp -o main.exe

if %errorlevel% neq 0 (
    echo [ERROR] Compilation failed.
    pause
    exit /b %errorlevel%
)

echo [SUCCESS] Compilation completed.
echo.
echo ========================================
echo Running program:
echo ========================================
echo.

main.exe

echo.
echo ========================================
echo Program finished.
echo ========================================
pause
