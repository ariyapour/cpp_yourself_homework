#include "pixelator/image.hpp"

pixelator::Image::Image(pixelator::Size size)
    : rows_{size.rows}, cols_{size.cols} {
  image_data_.resize(rows_ * cols_, ftxui::Color{});
};

pixelator::Image::Image(const int rows, const int cols)
    : rows_{rows}, cols_{cols} {
  image_data_.resize(rows_ * cols_, ftxui::Color{});
};

pixelator::Image::Image(pixelator::Image &&other_image)
    : rows_{other_image.rows_},
      cols_{other_image.cols_},
      image_data_{other_image.image_data_} {
  other_image.image_data_.clear();
  other_image.rows_ = 0;
  other_image.cols_ = 0;
}

pixelator::Image::Image(pixelator::Image &other_image)
    : rows_{other_image.rows_},
      cols_{other_image.cols_},
      image_data_{other_image.image_data_} {
}

bool pixelator::Image::empty() const {
  return image_data_.empty();
}

int pixelator::Image::rows() const {
  return rows_;
}

int pixelator::Image::cols() const {
  return cols_;
}

pixelator::Size pixelator::Image::size() {
  return pixelator::Size{rows_, cols_};
}

const pixelator::Size pixelator::Image::size() const {
  return pixelator::Size{rows_, cols_};
}

ftxui::Color &pixelator::Image::at(int row, int col) {
  return image_data_.at(row * cols_ + col);
}

const ftxui::Color &pixelator::Image::at(int row, int col) const {
  return image_data_.at(row * cols_ + col);
}

pixelator::Image &pixelator::Image::operator=(pixelator::Image &&other_image) {
  if (this == &other_image) {
    return *this;
  }
  if (!image_data_.empty()) {
    image_data_.clear();
  }

  image_data_ = other_image.image_data_;
  rows_ = other_image.rows_;
  cols_ = other_image.cols_;
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  return *this;
}