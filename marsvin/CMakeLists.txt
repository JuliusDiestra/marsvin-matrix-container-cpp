cmake_minimum_required(VERSION 3.10.2)

project(marsvin LANGUAGES CXX)

set(MARSVIN_TOOLS_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/src/matrix.cpp
)

# Adding source files
add_library(${PROJECT_NAME}
    SHARED
        ${MARSVIN_TOOLS_SRC}            
)

# Adding include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/tools/include
)
