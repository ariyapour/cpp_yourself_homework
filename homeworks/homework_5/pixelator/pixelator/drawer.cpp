#include "pixelator/drawer.hpp"
#include <iostream>
#include <algorithm>

pixelator::Drawer::Drawer(const ftxui::Dimensions dimensions) {
  if (dimensions.dimx == ftxui::Dimension::Full().dimx &&
      dimensions.dimy == ftxui::Dimension::Full().dimy) {
    rows_ = ftxui::Dimension::Full().dimx;
    cols_ = ftxui::Dimension::Full().dimy;
  } else {
    rows_ = dimensions.dimx;
    cols_ = rows_ * 2;
  }
  screen_ = ftxui::Screen::Create({rows_, cols_});
}

int pixelator::Drawer::rows() const { return rows_; }

int pixelator::Drawer::cols() const { return cols_; }

const pixelator::Size pixelator::Drawer::size() const {
  return pixelator::Size{rows_, cols_};
}

void pixelator::Drawer::Set(pixelator::Image image) {
  for (int i = 0; i < image.rows(); i++) {
    for (int j = 0; j < image.cols(); j++) {
      auto &pixel_left = screen_.PixelAt(j * 2, i);
      pixel_left.background_color = image.at(i, j);
      pixel_left.character = ' ';
      auto &pixel_right = screen_.PixelAt(j * 2 + 1, i);
      pixel_right.background_color = image.at(i, j);
      pixel_right.character = ' ';
    }
  }

  return;
}

void pixelator::Drawer::Draw() const {
  screen_.Print();
  return;
}

std::string pixelator::Drawer::ToString() const {
  std::string string_image = screen_.ToString();

  //Remove new line characters from the end of the string

  while (!string_image.empty() && (string_image[string_image.size() - 1] == '\r' || string_image[string_image.size() - 1] == '\n') )
  {
    string_image.erase(string_image.size() - 1);
  }
  
  return string_image;
}