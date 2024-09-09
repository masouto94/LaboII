cmake_minimum_required(VERSION 3.29)
project(GuiaCLion)

set(CMAKE_CXX_STANDARD 20)

add_executable(GuiaCLion main.cpp
        Ejercicios/index.h
        Ejercicios/person.h
        Ejercicios/personArray.h)
