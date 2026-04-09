cmake_minimum_required(VERSION 3.10)

# Назва проєкту
project(lab0 LANGUAGES CXX)

# Стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Виконуваний файл
add_executable(${PROJECT_NAME} main.cpp)
