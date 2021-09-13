cmake_minimum_required(VERSION 3.16.3)
project(Server)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server server/main.cpp server/Knn.cpp server/Knn.h Iris.h
        Iris.cpp server/TCPServer.cpp server/TCPServer.h)
add_executable(Client client/main.cpp client/TCPClient.cpp client/TCPClient.h Iris.h Iris.cpp Client/Command.cpp Client/Command.h Client/CLI.cpp Client/CLI.h)