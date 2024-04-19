#include <gtest/gtest.h>
#include "pixelator/image.hpp"

TEST(image_tests, test1){
    pixelator::Image empty_image{};
    
    const auto rows{42};
    const auto cols{23};
    pixelator::Image image{rows, cols};

    EXPECT_EQ(empty_image.rows(),0);
    EXPECT_EQ(empty_image.cols(),0);
    EXPECT_EQ(empty_image.empty(),true);

    EXPECT_EQ(image.rows(),42);
    EXPECT_EQ(image.cols(),23);
    EXPECT_EQ(image.empty(),false);
    EXPECT_EQ(image.size().row, 42);
    EXPECT_EQ(image.size().col, 23); 
}

TEST(image_tests, test2){
    pixelator::Image image{10, 10};
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};
    image.at(4, 2) = yellowish;
    const pixelator::Image image_copy{image};

    EXPECT_EQ(image.at(4,2), yellowish);
    EXPECT_EQ(image_copy.at(4,2), yellowish);
}

TEST(image_tests, test3){
    pixelator::Image image{10, 10};
    const ftxui::Color yellowish{ftxui::Color::RGB(255, 200, 100)};
    image.at(4, 2) = yellowish;

    const pixelator::Image image_moved{std::move(image)};

    EXPECT_EQ(image_moved.at(4,2), yellowish);
}