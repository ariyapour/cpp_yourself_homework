#define STB_IMAGE_IMPLEMENTATION
#include "pixelator/stb_image_data_view.hpp"
#include "stb/stb_image.h"
#include <iostream>

pixelator::StbImageDataView::StbImageDataView(const std::string &image_path) {
  image_data_ = stbi_load(image_path.c_str(), &cols_, &rows_,
                          &channels_, 0);
  if (!image_data_) {
    std::cerr << "Failed to load image data from file: " << image_path
              << std::endl;
    rows_ = 0;
    cols_ = 0;
    channels_ = 0;
  }
};

pixelator::StbImageDataView::StbImageDataView(
    pixelator::StbImageDataView &&other_image)
    : rows_{other_image.rows_}, cols_{other_image.cols_}, channels_{other_image.channels_}, image_data_{other_image.image_data_} {
  other_image.image_data_ = nullptr;
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;
}

pixelator::Size pixelator::StbImageDataView::size() const { return pixelator::Size{rows_,cols_}; }

bool pixelator::StbImageDataView::empty() const {
  return (image_data_ == nullptr) ? true : false;
}

int pixelator::StbImageDataView::rows() const { return rows_; }

int pixelator::StbImageDataView::cols() const { return cols_; }

ftxui::Color pixelator::StbImageDataView::at(const int &row,
                                             const int &col) const {
  const auto index{channels_ * (row * cols_ + col)};
  return ftxui::Color::RGB(image_data_[index], image_data_[index + 1],
                           image_data_[index + 2]);
}

pixelator::StbImageDataView &
pixelator::StbImageDataView::operator=(StbImageDataView &&object) {
  if (this == &object) {
    return *this;
  }
  if (image_data_ != nullptr) {
    stbi_image_free(image_data_);
  }
  image_data_ = object.image_data_;
  rows_ = object.rows_;
  cols_ = object.cols_;
  channels_ = object.channels_;

  object.rows_ = 0;
  object.cols_ = 0;
  object.channels_ = 0;
  object.image_data_ = nullptr;

  return *this;
}

pixelator::StbImageDataView::~StbImageDataView() {
  if (image_data_ != nullptr) {
    stbi_image_free(image_data_);
  }
}