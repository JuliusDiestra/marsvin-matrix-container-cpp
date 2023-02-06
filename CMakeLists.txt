cmake_minimum_required(VERSION 3.10.2)

project(marsvin LANGUAGES CXX)

set(MARSVIN_SOURCE_CODE
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/marsvin_error_code.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/marsvin_exception.cpp
)

add_library(${PROJECT_NAME}
    SHARED
        ${MARSVIN_SOURCE_CODE}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/core/include
)

include(CTest)
if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
