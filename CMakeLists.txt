cmake_minimum_required(VERSION 3.26)
project(ploio_ssh_module_)

set(CMAKE_CXX_STANDARD 17)

add_executable(ploio_ssh_module_ main.cpp
        pch.h
        hdr.h)
