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
  Drawer(const ftxui::Dimensions dimensions);
  int rows() const;
  int cols() const;
  const Size size() const;
  void Set(const pixelator::Image& image);
  void Draw() const;
  std::string ToString() const;
  ~Drawer() = default;
};
} // namespace pixelator
