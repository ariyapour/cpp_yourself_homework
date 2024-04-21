#include <gtest/gtest.h>
#include <iostream>
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/test_global_variables.hpp"

TEST(stb_image_data_view_tests, test1){
    pixelator::StbImageDataView image{pixelator_tests::image_path};
    pixelator::StbImageDataView empty_image{};
    const pixelator::Size size = image.size();
    pixelator::Color color = image.at(pixelator_tests::test_pixel_x,pixelator_tests::test_pixel_y);


    EXPECT_EQ(size.rows, pixelator_tests::test_image_rows);
    EXPECT_EQ(size.cols, pixelator_tests::test_image_cols);
    EXPECT_EQ(image.empty(), false);
    EXPECT_EQ(empty_image.empty(), true);
    EXPECT_EQ(color.red, pixelator_tests::test_pixel_color.red);
    EXPECT_EQ(color.blue, pixelator_tests::test_pixel_color.blue);
    EXPECT_EQ(color.green, pixelator_tests::test_pixel_color.green);
}

TEST(stb_image_data_view_tests, test2){
    pixelator::StbImageDataView image{pixelator_tests::image_path};
    pixelator::StbImageDataView image_copy = std::move(image);
    pixelator::Color color = image_copy.at(pixelator_tests::test_pixel_x,pixelator_tests::test_pixel_y);

    EXPECT_EQ(color.red, pixelator_tests::test_pixel_color.red);
    EXPECT_EQ(color.blue, pixelator_tests::test_pixel_color.blue);
    EXPECT_EQ(color.green, pixelator_tests::test_pixel_color.green);
    EXPECT_EQ(image.rows(),0);
    EXPECT_EQ(image.cols(),0);
    EXPECT_EQ(image.empty(),true);
}