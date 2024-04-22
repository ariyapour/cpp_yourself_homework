#pragma once
#include "pixelator/image.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include <iostream>
namespace pixelator {

int Scale(int number, float factor) {
  return static_cast<int>(number * factor);
}

pixelator::Image PixelateImage(pixelator::StbImageDataView &image_view,
                               pixelator::Size new_size) {
  const auto factor_cols =
      new_size.cols / static_cast<float>(image_view.cols());
  const auto factor_rows =
      new_size.rows / static_cast<float>(image_view.rows());
  const auto smallest_factor = std::min(factor_cols, factor_rows);

  const auto new_rows = Scale(image_view.rows(), smallest_factor);
  const auto new_cols = Scale(image_view.cols(), smallest_factor);

  pixelator::Image results(new_rows, new_cols);

  // New size is bigger than original size. Dont resize. Return the original
  // image
  // TODO: Check keeping the aspect retion carefully. there is a problem
  if (new_size.rows > image_view.size().rows &&
      new_size.cols > image_view.size().cols) {
    for (int i = 0; i < image_view.rows(); i++) {
      for (int j = 0; j < image_view.cols(); j++) {
        results.at(i, j) = image_view.at(i, j);
      }
    }
    return results;
  }

  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      // Calculate the corresponding coordinates in the original image
      const int original_row = static_cast<int>(i / smallest_factor);
      const int original_col = static_cast<int>(j / smallest_factor);

      // Set the color of the pixel in the pixelated image
      results.at(i, j) = image_view.at(original_row, original_col);
    }
  }

  return results;
}
} // namespace pixelator