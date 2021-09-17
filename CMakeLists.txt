cmake_minimum_required(VERSION 3.16.3)
project(Server)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server Server/main.cpp Server/Knn.cpp Server/Knn.h Iris.h
        Iris.cpp Server/TCPServer.cpp Server/TCPServer.h Client/Upload.cpp Client/Upload.h Server/CLI.cpp Server/CLI.h)
add_executable(Client Client/main.cpp Client/TCPClient.cpp Client/TCPClient.h Iris.h Iris.cpp Client/Command.cpp
        Client/Command.h Client/CLI.cpp Client/CLI.h Client/Settings.cpp Client/Settings.h Client/Classify.cpp Client/Classify.h Client/Display.cpp Client/Display.h Client/Download.cpp Client/Download.h Client/Matrix.cpp Client/Matrix.h)