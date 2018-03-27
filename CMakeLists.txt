cmake_minimum_required(VERSION 3.1.3)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PythonLibs 2.7 REQUIRED)
find_package(PythonInterp 2.7 REQUIRED)
find_package(Boost COMPONENTS python)

set(SOURCES test.cpp grey_wolf_optimizer.cpp  benchmark_functions.cpp  utils.cpp)
add_executable(optimize ${SOURCES})