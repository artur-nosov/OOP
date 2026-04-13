@echo off
echo Компіляція...
g++ -o lab2.exe main.cpp triangle.cpp -std=c++17

if %errorlevel% neq 0 (
    echo Помилка компіляції!
    pause
    exit /b 1
)

echo Компіляція успішна!
echo.
lab2.exe
pause
