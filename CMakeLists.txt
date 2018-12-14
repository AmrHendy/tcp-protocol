cmake_minimum_required(VERSION 3.12)
project(tcp_protocol)
# add CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread" for threads
# remove -DCMAKE_SH="CMAKE_SH-NOTFOUND" on other machines
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(tcp_protocol serverMain.cpp Client/Client.cpp
        Client/Client.h Server/Server.cpp Server/Server.h
        "File Handler/FileReader.cpp" "File Handler/FileReader.h"
        "File Handler/FileWriter.cpp" "File Handler/FileWriter.h"
        Sender/Sender.cpp Sender/Sender.h Packet/Packet.h
        Receiver/Receiver.cpp Receiver/Receiver.h Utils/constants.h
        Packet/PacketHandler.cpp Packet/PacketHandler.h
        "Stop and Wait/StopAndWait.cpp"
        "Stop and Wait/StopAndWait.h" SR/SR_Receiver.cpp SR/SR_Receiver.h
        SR/SR_Sender.cpp SR/SR_Sender.h
        GBN/GBN_sender.h GBN/GBN_sender.cpp)