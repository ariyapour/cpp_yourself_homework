#pragma once
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"
#include "pixelator/image.hpp"
namespace pixelator {
class Drawer {
private:
  ftxui::Screen screen_{0, 0};
  int rows_{};
  int cols_{};

public:
  Drawer() = default;
  Drawer(const ftxui::Dimensions &dimensions);
  void Set(pixelator::image image);
  Size size() const;
  void Draw() const;
};
} // namespace pixelator
