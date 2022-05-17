cmake_minimum_required(VERSION 3.10)

# set the project name
project(Graph-Isomorfizm)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenMP REQUIRED)

set(SOURCES
    src/main.cpp
    src/graph.cpp
    src/utils.cpp
)

# add the executable
add_executable(Graph-Isomorfizm ${SOURCES})

target_include_directories(Graph-Isomorfizm
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Graph-Isomorfizm PRIVATE OpenMP::OpenMP_CXX)

