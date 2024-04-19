#pragma once
#include "ftxui/screen/color.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include <vector>

namespace pixelator {

class image {
private:
  int rows_{};
  int cols_{};
  int channels_{3};
  // Since we want tor reserve the data on construction time we create a bool
  // flag to indicate if the content is manupulated or is it the initialized and
  // reserved version
  bool empty_{true};
  std::vector<ftxui::Color> image_data_{};

public:
  image() = default;
  // Move constructor
  image(image &&other_image);
  image(const int rows, const int cols);
  bool empty() const;
  int rows() const;
  int cols() const;
  pixelator::Size size() const;
  const ftxui::Color &at(int row, int col) const;
  ftxui::Color &at(int row, int col);
  // Move assignment operator
  image &operator=(image &&other_image);
};

} // namespace pixelator