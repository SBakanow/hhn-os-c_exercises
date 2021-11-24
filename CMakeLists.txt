cmake_minimum_required(VERSION 3.20)
project(hhn_c C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/aufgabe1
        ${PROJECT_SOURCE_DIR}/aufgabe2)
        #${PROJECT_SOURCE_DIR}/freeListNodes)

file(GLOB main "${PROJECT_SOURCE_DIR}/main.c")
file(GLOB stack "${PROJECT_SOURCE_DIR}/aufgabe1/*.c")
file(GLOB freelist "${PROJECT_SOURCE_DIR}/aufgabe2/*.c")
#file(GLOB freeListNodes "${PROJECT_SOURCE_DIR}/freeListNodes/*.c")

add_executable(main
                ${main} ${freelist})
