cmake_minimum_required(VERSION 3.16.3)
project(Server)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server Server/main.cpp Server/Knn.cpp Server/Knn.h Iris.h
        Iris.cpp Server/TCPServer.cpp Server/TCPServer.h Server/Upload.cpp Server/Upload.h Server/CLI.cpp Server/CLI.h
        Server/Command.cpp Server/Command.h Server/Settings.cpp Server/Settings.h Server/Classify.cpp
        Server/Classify.h Server/Display.cpp Server/Display.h Server/Download.cpp
        Server/Download.h Server/Matrix.cpp Server/Matrix.h)
add_executable(Client Client/main.cpp Client/TCPClient.cpp Client/TCPClient.h Iris.h Iris.cpp)