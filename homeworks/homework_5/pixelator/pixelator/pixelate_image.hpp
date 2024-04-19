#pragma once
#include "pixelator/image.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include <iostream>
namespace pixelator {
inline pixelator::image PixelateImage(pixelator::StbImageDataView &image_view,
                                      pixelator::Size window) {
  pixelator::image results(image_view.rows(), image_view.cols());

  // For wno just return the original image
  for (int i = 0; i < image_view.rows(); i++) {
    for (int j = 0; j < image_view.cols(); j++) {
      results.at(i, j) = image_view.at(i, j);
    }
  }

  return results;
}
} // namespace pixelator