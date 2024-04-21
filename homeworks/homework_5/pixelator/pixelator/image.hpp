#pragma once
#include "ftxui/screen/color.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include <vector>

namespace pixelator {

class Image {
private:
  int rows_{};
  int cols_{};
  int channels_{3};
  std::vector<ftxui::Color> image_data_{};

public:
  Image() = default;
  Image(const pixelator::Size size);
  // Move constructor
  Image(Image &&other_image);
  // copy constructor
  Image(Image &other_image);
  Image(const int rows, const int cols);
  bool empty() const;
  int rows() const;
  int cols() const;
  pixelator::Size size();
  const pixelator::Size size() const;
  const ftxui::Color &at(int row, int col) const;
  ftxui::Color &at(int row, int col);
  // Move assignment operator
  Image &operator=(Image &&other_image);
};

} // namespace pixelator