add_library(string_split string_split.cpp)
target_link_libraries(string_split PUBLIC cxx_setup)

add_library(string_trim string_trim.cpp)
target_link_libraries(string_trim PUBLIC cxx_setup)

if(BUILD_TESTING)
    add_executable(string_split_test string_split_test.cpp)
    target_link_libraries(string_split_test PRIVATE string_split GTest::gtest_main)

    add_executable(string_trim_test string_trim_test.cpp)
    target_link_libraries(string_trim_test PRIVATE string_trim GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(string_split_test)
    gtest_discover_tests(string_trim_test)
    
endif()
