cmake_minimum_required(VERSION 3.12)
project(tcp_protocol)
# add CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread" for threads
# remove -DCMAKE_SH="CMAKE_SH-NOTFOUND" on other machines
set(CMAKE_CXX_STANDARD 14)

add_executable(tcp_protocol main.cpp Client/Client.cpp Client/Client.h Server/Server.cpp Server/Server.h "File Handler/FileHandler.cpp" "File Handler/FileHandler.h")