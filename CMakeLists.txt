# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(server)

# Set the C++ compiler
set(CMAKE_CXX_COMPILER g++)

# Set compiler flags
set(CMAKE_CXX_FLAGS "-g -Wall")

# To include the package
find_package(Poco REQUIRED COMPONENTS Net)

# Define the source files
set(SRCS 
    ./networking/sockets/createSocket.cpp
    ./networking/sockets/bindingSocket.cpp
    ./networking/sockets/listeningSocket.cpp
    ./networking/server/createServer.cpp
    ./networking/requests/GET/get.cpp
    ./server.cpp
    ./startServer.cpp
)

# Include directories
include_directories(${Poco_INCLUDE_DIRS})

# Compile the source files into object files
add_executable(serve ${SRCS})

# Link the Poco library
target_link_libraries(serve ${Poco_LIBRARIES})