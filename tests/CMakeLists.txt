# Test target
set(TEST_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/litestorecpp_test.cpp)
add_executable(test_litestorecpp ${TEST_SOURCES})
target_include_directories(test_litestorecpp
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
    PRIVATE ${LIB_DIR}/catch2
)
target_compile_options(test_litestorecpp
    PRIVATE -std=c++14 -g -Wall -Wextra -Werror -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
target_link_libraries(test_litestorecpp
    PRIVATE litestorecpp)