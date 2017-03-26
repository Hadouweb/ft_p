cmake_minimum_required(VERSION 3.6)
project(ft_p)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(client_src)
include_directories(client_src/includes)
include_directories(server_src)
include_directories(server_src/includes)

set(SRCS_CLIENT
        client_src/srcs/main.c
    )
set(HEADER_CLIENT client_src/includes/client.h)

set(SRCS_SERVER
        server_src/srcs/main.c
    )
set(HEADER_SERVER server_src/includes/server.h)

add_executable(client_src ${SRCS_CLIENT} ${HEADER_CLIENT})
add_executable(server_src ${SRCS_SERVER} ${HEADER_SERVER})