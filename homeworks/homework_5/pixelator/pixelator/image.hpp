#pragma once
#include <vector>

#include "ftxui/screen/color.hpp"
#include "pixelator/stb_image_data_view.hpp"

namespace pixelator {

class Image {
 private:
  int rows_{};
  int cols_{};
  std::vector<ftxui::Color> image_data_{};

 public:
  // Default constructor
  Image() = default;
  ~Image() = default;
  Image(const pixelator::Size size);
  Image(const int rows, const int cols);
  bool empty() const;
  int rows() const;
  int cols() const;
  pixelator::Size size();
  const pixelator::Size size() const;
  const ftxui::Color &at(int row, int col) const;
  ftxui::Color &at(int row, int col);
};

}  // namespace pixelator