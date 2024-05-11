cmake_minimum_required(VERSION 3.28)
project(MedicineManagementSystem C)

set(CMAKE_C_STANDARD 23)

add_executable(MedicineManagementSystem main.c
        Welcome.h
        Welcome.c
        Medicine.h)
