#define STB_IMAGE_IMPLEMENTATION
#include "pixelator/stb_image_data_view.hpp"

#include <iostream>

#include "stb/stb_image.h"

pixelator::StbImageDataView::StbImageDataView(const std::string &image_path) {
  image_data_ = stbi_load(image_path.c_str(), &cols_, &rows_, &channels_, 0);
  if (!image_data_) {
    std::cerr << "Failed to load image data from file: " << image_path
              << std::endl;
    rows_ = 0;
    cols_ = 0;
    channels_ = 0;
  }
};

pixelator::StbImageDataView::StbImageDataView(
    const pixelator::StbImageDataView &other_imge)
    : rows_{other_imge.rows_},
      cols_{other_imge.cols_},
      channels_{other_imge.channels_},
      image_data_{AllocateMemory(other_imge.rows() * other_imge.cols() *
                                 other_imge.channels())} {
  std::copy(other_imge.image_data_,
            other_imge.image_data_ +
                other_imge.rows() * other_imge.cols() * other_imge.channels(),
            image_data_);
}

pixelator::StbImageDataView::StbImageDataView(
    pixelator::StbImageDataView &&other_image)
    : rows_{other_image.rows_},
      cols_{other_image.cols_},
      channels_{other_image.channels_},
      image_data_{other_image.image_data_} {
  other_image.image_data_ = nullptr;
  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;
}

pixelator::Size pixelator::StbImageDataView::size() const {
  return pixelator::Size{rows_, cols_};
}

bool pixelator::StbImageDataView::empty() const {
  return (image_data_ == nullptr) ? true : false;
}

int pixelator::StbImageDataView::rows() const {
  return rows_;
}

int pixelator::StbImageDataView::cols() const {
  return cols_;
}

int pixelator::StbImageDataView::channels() const {
  return channels_;
}

ftxui::Color pixelator::StbImageDataView::at(const int &row,
                                             const int &col) const {
  const auto index{channels_ * (row * cols_ + col)};
  return ftxui::Color::RGB(image_data_[index], image_data_[index + 1],
                           image_data_[index + 2]);
}

pixelator::StbImageDataView &pixelator::StbImageDataView::operator=(
    const StbImageDataView &other_image) {
  if (this == &other_image) {
    return *this;
  }
  if (image_data_ != nullptr) {
    FreeMemory(image_data_);
  }
  image_data_ = AllocateMemory(other_image.rows() * other_image.cols() *
                               other_image.channels());
  std::copy(other_image.image_data_,
            other_image.image_data_ +
                other_image.rows() * other_image.cols() * other_image.channels(),
            image_data_);
  rows_ = other_image.rows();
  cols_ = other_image.cols();
  channels_ = other_image.channels();
  return *this;
}

pixelator::StbImageDataView &pixelator::StbImageDataView::operator=(
    StbImageDataView &&other_image) {
  if (this == &other_image) {
    return *this;
  }
  if (image_data_ != nullptr) {
    stbi_image_free(image_data_);
  }
  image_data_ = other_image.image_data_;
  rows_ = other_image.rows_;
  cols_ = other_image.cols_;
  channels_ = other_image.channels_;

  other_image.rows_ = 0;
  other_image.cols_ = 0;
  other_image.channels_ = 0;
  other_image.image_data_ = nullptr;

  return *this;
}

pixelator::StbImageDataView::~StbImageDataView() {
  if (image_data_ != nullptr) {
    stbi_image_free(image_data_);
  }
}