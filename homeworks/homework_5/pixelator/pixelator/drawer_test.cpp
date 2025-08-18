#include "pixelator/drawer.hpp"
#include <gtest/gtest.h>

TEST(drawer_tests, FullAndFixedDrawerSizes) {
  pixelator::Drawer full_screen_drawer{ftxui::Dimension::Full()};
  pixelator::Drawer fixed_screen_drawer{ftxui::Dimension::Fixed(42)};

  EXPECT_EQ(ftxui::Terminal::Size().dimx, full_screen_drawer.size().rows);
  EXPECT_EQ(ftxui::Terminal::Size().dimy, full_screen_drawer.size().cols);

  EXPECT_EQ(42, fixed_screen_drawer.size().rows);
  EXPECT_EQ(84, fixed_screen_drawer.size().cols);
}