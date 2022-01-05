cmake_minimum_required(VERSION 3.21)
project(hw)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw main.cpp Matrix/Matrix.cpp Matrix/Matrix.h utils.cpp utils.h constants.h Model/Model.cpp Model/Model.h)

add_executable(gen_script gen_script.cpp constants.h)
