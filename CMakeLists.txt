cmake_minimum_required(VERSION 4.3)

project(cnc-td-ps1)

include_directories(include)
set(SOURCE_FILES
        src/main.c
        src/cnc_types.c)
add_executable(default ${SOURCE_FILES})
