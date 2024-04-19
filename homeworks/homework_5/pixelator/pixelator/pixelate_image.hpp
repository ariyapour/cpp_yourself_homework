#pragma once
#include<iostream>
#include "pixelator/image.hpp"
#include "pixelator/stb_image_data_view.hpp"
namespace pixelator {

int Scale(int number, float factor) {
  return static_cast<int>(number * factor);
}

inline pixelator::Image PixelateImage(pixelator::StbImageDataView &image_view,
                                      pixelator::Size new_size) {
  const auto factor_cols = new_size.col / static_cast<float>(image_view.cols());
  const auto factor_rows = new_size.row / static_cast<float>(image_view.rows());
  const auto smallest_factor = std::min(factor_cols, factor_rows);

  const auto new_rows = Scale(image_view.rows(), smallest_factor);
  const auto new_cols = Scale(image_view.cols(), smallest_factor);

  pixelator::Image results(new_rows, new_cols);
  
  // New size is bigger than original size. Dont resize. Return the original image
  // TODO: Check keeping the aspect retion carefully. there is a problem
  if (new_size.row > image_view.size().row &&
      new_size.col > image_view.size().col) {
    for (int i = 0; i < image_view.rows(); i++) {
      for (int j = 0; j < image_view.cols(); j++) {
        results.at(i, j) = ftxui::Color::RGB(image_view.at(i, j).red,
                                             image_view.at(i, j).green,
                                             image_view.at(i, j).blue);
      }
    }
    return results;
  }
  int x = 100;
  int y = 150;
  std::cout<<"Image at ----------------------------------------------:R: "<<image_view.at(x,y).red<<" G: "<<image_view.at(x,y).green<<" B: "<<image_view.at(x,y).blue<<std::endl;
  // Define a variable to store the number of pixels we should average
  const auto pixels_to_merge = static_cast<int>(1 / smallest_factor);

  // Loop through the new image and set each pixels value with the average of
  // the pixels in the original image by a window of pixels_to_mergex X
  // pixels_to_merge size.
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      // Initialize average_color to calculate average color of each window
      pixelator::Color average_color{0, 0, 0};
      for (int k = 0; k < pixels_to_merge; k++) {
        for (int l = 0; l < pixels_to_merge; l++) {
          average_color.red +=
              image_view.at(i * pixels_to_merge + k, j * pixels_to_merge + l)
                  .red;
          average_color.green +=
              image_view.at(i * pixels_to_merge + k, j * pixels_to_merge + l)
                  .green;
          average_color.blue +=
              image_view.at(i * pixels_to_merge + k, j * pixels_to_merge + l)
                  .blue;
        }
      }
      // Devide by number of cells
      average_color.red /= pixels_to_merge * pixels_to_merge;
      average_color.green /= pixels_to_merge * pixels_to_merge;
      average_color.blue /= pixels_to_merge * pixels_to_merge;

      // Set the new pixel in the new image with the average value.
      results.at(i, j) = ftxui::Color::RGB(
          average_color.red, average_color.green, average_color.blue);
    }
  }

  return results;
}
} // namespace pixelator