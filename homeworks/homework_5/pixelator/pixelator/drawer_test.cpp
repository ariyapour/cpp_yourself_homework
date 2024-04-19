#include <gtest/gtest.h>
#include <fstream>
#include "pixelator/drawer.hpp"

const std::filesystem::path image_path{"../../pixelator/test_data/grumpy.png"};
const std::filesystem::path test_path{"../../pixelator/test_data/grumpy_pixelated_211_fixed.txt"};
const int test_data_drawer_size = 211;

TEST(drawer_tests, test2){
    pixelator::Drawer full_screen_drawer{ftxui::Dimension::Full()};
    pixelator::Drawer fixed_screen_drawer{ftxui::Dimension::Fixed(42)};

    EXPECT_EQ(ftxui::Terminal::Size().dimx , full_screen_drawer.size().row);
    EXPECT_EQ(ftxui::Terminal::Size().dimy , full_screen_drawer.size().col);

    EXPECT_EQ(42 , fixed_screen_drawer.size().row);
    EXPECT_EQ(84 , fixed_screen_drawer.size().col);
}