#define STB_IMAGE_IMPLEMENTATION
#include "pixelator/stb_image_data_view.hpp"
#include "stb/stb_image.h"
#include <iostream>

pixelator::StbImageDataView::StbImageDataView(const std::string &image_path) {
  image_data_ =
      stbi_load(image_path.c_str(), &size_.col, &size_.row, &size_.channel, 0);
  if (!image_data_) {
    std::cerr << "Failed to load image data from file: " << image_path
              << std::endl;
    size_ = pixelator::Size{0, 0, 0};
  }
};

pixelator::StbImageDataView::StbImageDataView(
    pixelator::StbImageDataView &&other_image)
    : size_{other_image.size_}, image_data_{other_image.image_data_} {
  other_image.image_data_ = nullptr;
  other_image.size_ = pixelator::Size{0, 0, 0};
}

pixelator::Size pixelator::StbImageDataView::size() const { return size_; }

bool pixelator::StbImageDataView::empty() const {
  return (image_data_ == nullptr) ? true : false;
}

int pixelator::StbImageDataView::rows() const { return size_.row; }

int pixelator::StbImageDataView::cols() const { return size_.col; }

pixelator::Color pixelator::StbImageDataView::at(const int &row,
                                                 const int &col) const {
  const auto index{size_.channel * (row * size_.col + col)};
  return pixelator::Color{image_data_[index], image_data_[index + 1],
                          image_data_[index + 2]};
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
  size_ = object.size();

  object.size_.row = 0;
  object.size_.col = 0;
  object.size_.channel = 0;
  object.image_data_ = nullptr;

  return *this;
}

pixelator::StbImageDataView::~StbImageDataView() {
  if (image_data_ != nullptr) {
    stbi_image_free(image_data_);
  }
}