cmake_minimum_required(VERSION 3.29)
project(computer_room_rs)

set(CMAKE_CXX_STANDARD 11)

add_executable(computer_room_rs main.cpp
        Identification.h
        Student.cpp
        Student.h
        Teacher.cpp
        Teacher.h
        Administrator.cpp
        Administrator.h
        global_file.h
        global_file.cpp
        computer_room.h
        Oder_File.cpp
        Oder_File.h)
