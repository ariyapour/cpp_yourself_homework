#include <gtest/gtest.h>
#include "pixelator/drawer.hpp"

TEST(drawer_tests, test2){
    pixelator::Drawer full_screen_drawer{ftxui::Dimension::Full()};
    pixelator::Drawer fixed_screen_drawer{ftxui::Dimension::Fixed(42)};

    EXPECT_EQ(ftxui::Terminal::Size().dimx , full_screen_drawer.size().row);
    EXPECT_EQ(ftxui::Terminal::Size().dimy , full_screen_drawer.size().col);

    EXPECT_EQ(42 , fixed_screen_drawer.size().row);
    EXPECT_EQ(84 , fixed_screen_drawer.size().col);
}