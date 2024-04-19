#include <gtest/gtest.h>
#include <iostream>
#include "pixelator/stb_image_data_view.hpp"

const std::filesystem::path image_path{"../../pixelator/test_data/grumpy.png"};

//coordinates of test pixel in test image
const int test_pixel_x = 100;
const int test_pixel_y = 150;

//Pixel coller of test image at position 100x15
const pixelator::Color test_pixel_color{185, 168, 153};

//Resolution of the test image
const int test_image_rows = 360;
const int test_image_cols = 400;

TEST(stb_image_data_view_tests, test1){
    pixelator::StbImageDataView image{image_path};
    pixelator::StbImageDataView empty_image{};
    const pixelator::Size size = image.size();
    pixelator::Color color = image.at(test_pixel_x,test_pixel_y);


    EXPECT_EQ(size.row, test_image_rows);
    EXPECT_EQ(size.col, test_image_cols);
    EXPECT_EQ(image.empty(), false);
    EXPECT_EQ(empty_image.empty(), true);
    EXPECT_EQ(color.red, test_pixel_color.red);
    EXPECT_EQ(color.blue, test_pixel_color.blue);
    EXPECT_EQ(color.green, test_pixel_color.green);
}

TEST(stb_image_data_view_tests, test2){
    pixelator::StbImageDataView image{image_path};
    pixelator::StbImageDataView image_copy = std::move(image);
    pixelator::Color color = image_copy.at(test_pixel_x,test_pixel_y);

    EXPECT_EQ(color.red, test_pixel_color.red);
    EXPECT_EQ(color.blue, test_pixel_color.blue);
    EXPECT_EQ(color.green, test_pixel_color.green);
    EXPECT_EQ(image.rows(),0);
    EXPECT_EQ(image.cols(),0);
    EXPECT_EQ(image.empty(),true);
}