cmake_minimum_required(VERSION 3.9)
project(Lem_in C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(CMAKE_C_STANDARD 99)

add_executable(Lem_in src/lemin.c src/lem_in.h)

target_link_libraries(Lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)