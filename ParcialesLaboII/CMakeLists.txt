cmake_minimum_required(VERSION 3.29)
project(ParcialesLaboII C)

set(CMAKE_C_STANDARD 11)

add_executable(ParcialesLaboII main.c
        Headers/index.h
        Headers/parcial_1.h
        Headers/parcial_2.h
        Headers/parcial_3.h
        Headers/utils.h)
