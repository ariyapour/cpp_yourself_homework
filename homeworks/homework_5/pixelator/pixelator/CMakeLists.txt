# TODO: Add your libraries here
# You must have the following libraries:
# - stb_image_data_view
# - drawer
# - image
# - pixelate_image

add_library(stb_image_data_view stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup stb::stb ftxui::screen)

add_library(image image.cpp)
target_link_libraries(image PUBLIC cxx_setup ftxui::screen stb_image_data_view)

add_library(drawer drawer.cpp)
target_link_libraries(drawer PUBLIC cxx_setup ftxui::screen image)

add_library(pixelate_image INTERFACE)
target_link_libraries(pixelate_image INTERFACE image stb_image_data_view)

add_library(test_global_variables INTERFACE)
target_link_libraries(test_global_variables INTERFACE image)


if(BUILD_TESTING)
  # TODO: Add your tests executable with all your tests here
  # Name it pixelator_tests.
  # Also use gtest_discover_tests(pixelator_tests)
  # to register them with CTest
  add_executable(pixelate_image_test pixelate_image_test.cpp)
  target_link_libraries(pixelate_image_test PRIVATE pixelate_image test_global_variables GTest::gtest_main)

  add_executable(drawer_test drawer_test.cpp)
  target_link_libraries(drawer_test PRIVATE drawer GTest::gtest_main)

  add_executable(image_test image_test.cpp)
  target_link_libraries(image_test PRIVATE image GTest::gtest_main)

  add_executable(stb_image_data_view_test stb_image_data_view_test.cpp)
  target_link_libraries(stb_image_data_view_test PRIVATE stb_image_data_view test_global_variables GTest::gtest_main)

  include(GoogleTest)
  gtest_discover_tests(pixelate_image_test)
  gtest_discover_tests(drawer_test)
  gtest_discover_tests(image_test)
  gtest_discover_tests(stb_image_data_view_test)
endif()
