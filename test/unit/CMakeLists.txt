find_package(GTest REQUIRED)
set(TEST_NAME test_marsvin)

add_executable(${TEST_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/test_marsvin_matrix.cpp
)

target_link_libraries(${TEST_NAME}
    marsvin
    gtest
    gtest_main
    pthread
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
