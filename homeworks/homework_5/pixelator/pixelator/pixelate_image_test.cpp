#include <gtest/gtest.h>
#include "pixelator/pixelate_image.hpp"
#include "pixelator/test_global_variables.hpp"

TEST(pixelator_tests, test1) {
  pixelator::StbImageDataView image{pixelator_tests::pixelator_image_path};

  // Perform pixelation
  pixelator::Image pixelated_image = pixelator::PixelateImage(
      image, pixelator::Size{pixelator_tests::pixelator_test_new_size,
                             pixelator_tests::pixelator_test_new_size,
                             pixelator_tests::pixelator_test_new_size});
  
  EXPECT_EQ(pixelated_image.at(0,0), ftxui::Color::RGB(0,0,0));
  EXPECT_EQ(pixelated_image.at(0,1), ftxui::Color::RGB(0,0,0));

  EXPECT_EQ(pixelated_image.at(1,0), ftxui::Color::RGB(0,0,0));
  EXPECT_EQ(pixelated_image.at(1,1), ftxui::Color::RGB(0,0,0));

  EXPECT_EQ(pixelated_image.at(2,0), ftxui::Color::RGB(255,255,255));
  EXPECT_EQ(pixelated_image.at(2,1), ftxui::Color::RGB(255,255,255));
}