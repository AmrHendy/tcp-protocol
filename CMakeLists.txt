cmake_minimum_required(VERSION 3.12)
project(tcp_protocol)

set(CMAKE_CXX_STANDARD 14 -DCMAKE_SH="CMAKE_SH-NOTFOUND")

add_executable(tcp_protocol main.cpp Client/Client.cpp Client/Client.h)