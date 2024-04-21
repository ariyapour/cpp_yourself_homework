#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "pixelator/drawer.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/pixelate_image.hpp"
#include "pixelator/test_global_variables.hpp"
#include <iostream>

TEST(pixelator_tests, test1){
    pixelator::StbImageDataView image{pixelator_tests::pixelator_image_path};

    const std::string test_data = "\x1B[39m\x1B[48;2;0;0;0m   \x1B[39m\x1B[49m\r\n\x1B[39m\x1B[48;2;127;127;127m   \x1B[39m\x1B[49m\r\n\x1B[39m\x1B[48;2;255;255;255m   \x1B[39m\x1B[49m\r\n   \r\n   \r\n   ";
    
    //Perform pixelation
    pixelator::Drawer drawer{ftxui::Dimension::Fixed(pixelator_tests::pixelator_drawer_size)};
    pixelator::Image pixelated_image = pixelator::PixelateImage(image, drawer.size());
    drawer.Set(pixelated_image);
    EXPECT_EQ(drawer.ToString(), test_data);
}