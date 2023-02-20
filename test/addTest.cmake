
include(CMakeParseArguments)

function(MarsvinAddTest)
    cmake_parse_arguments(
        arg
        ""
        "NAME"
        "SOURCES;INCLUDE_DIR;LINK_LIBRARIES"
        ${ARGN}
    )
    if (NOT arg_NAME)
        message(FATAL_ERROR "[MarsvinAddTest] NAME is a required argument.")
    endif()
    if (NOT arg_SOURCES)
        message(FATAL_ERROR "[MarsvinAddTest] SOURCES is a required argument.")
    endif()
    add_executable(${arg_NAME} ${arg_SOURCES})
    if (arg_INCLUDE_DIR)
        target_include_directories(${arg_NAME}
            PUBLIC
                ${arg_INCLUDE_DIR}
        )
    endif()
    target_link_libraries(${arg_NAME}
        gtest
        gtest_main
        pthread
    )
    if(arg_LINK_LIBRARIES)
        target_link_libraries(${arg_NAME} ${arg_LINK_LIBRARIES})
    endif()
    add_test(
        NAME ${arg_NAME}
        COMMAND ${arg_NAME}
    )
endfunction()
