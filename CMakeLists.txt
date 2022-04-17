cmake_minimum_required(VERSION 3.10.2)

project(marsvin LANGUAGES CXX)

# Adding source files
add_library(${PROJECT_NAME} INTERFACE)

# Adding include directories
target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/linear-algebra/include
        ${CMAKE_CURRENT_SOURCE_DIR}/differential-calculus/include
)
