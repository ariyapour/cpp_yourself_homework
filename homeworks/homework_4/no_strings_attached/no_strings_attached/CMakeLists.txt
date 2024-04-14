add_library(string_split string_split.cpp)
target_link_libraries(string_split PUBLIC cxx_setup)
add_library(string_trim string_trim.cpp)
target_link_libraries(string_trim PUBLIC cxx_setup)