#include "pixelator/image.hpp"

pixelator::image::image(const int rows, const int cols)
    : rows_{rows}, cols_{cols} {
  image_data_.resize(rows_ * cols_ * channels_, ftxui::Color{});
};

pixelator::image::image(pixelator::image &&other_image)
    : rows_{other_image.rows_}, cols_{other_image.cols_},
      channels_{other_image.channels_},
      image_data_{other_image.image_data_} {
  other_image.image_data_.clear();
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;
}

bool pixelator::image::empty() const {
  if (image_data_.empty()) {
    return true;
  }
  return false;
}

int pixelator::image::rows() const { return rows_; }

int pixelator::image::cols() const { return cols_; }

pixelator::Size pixelator::image::size() const {
  return pixelator::Size{rows_, cols_, channels_};
}

ftxui::Color &pixelator::image::at(int row, int col) {
  return image_data_.at(channels_ * (row * cols_ + col));
}

const ftxui::Color &pixelator::image::at(int row, int col) const {
  return image_data_.at(channels_ * (row * cols_ + col));
}

pixelator::image &pixelator::image::operator=(pixelator::image &&other_image) {
  if (this == &other_image) {
    return *this;
  }
  if (!image_data_.empty()) {
    image_data_.clear();
  }

  image_data_ = other_image.image_data_;
  rows_ = other_image.rows_;
  cols_ = other_image.cols_;
  channels_ = other_image.channels_;
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;

  return *this;
}