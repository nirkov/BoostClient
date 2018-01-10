cmake_minimum_required(VERSION 3.8)
project(ClientSide)

set(CMAKE_CXX_STANDARD 11)
link_libraries(boost_system boost_thread)
set(SOURCE_FILES
        include/connectionHandler.h
        src/connectionHandler.cpp
        src/Client.cpp)

add_executable(ClientSide ${SOURCE_FILES})