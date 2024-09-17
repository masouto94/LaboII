cmake_minimum_required(VERSION 3.29)
project(GuiaMemoriaDinamica C)

set(CMAKE_C_STANDARD 11)

add_executable(GuiaMemoriaDinamica main.c
        Headers/index.h
        Headers/ejercicios_memoria.h
        Headers/matrices.h
        Headers/ejercicios_archivos.h)
