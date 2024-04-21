#pragma once
#include "ftxui/screen/color.hpp"
#include <filesystem>
#include <string>

namespace pixelator {
// A struct to store image size
struct Size {
  int rows;
  int cols;
  int channel{3};
};

// A struct to store colors
struct Color {
  int red;
  int green;
  int blue;
};

class StbImageDataView {
private:
  // Image size member function initialized with all values 0
  Size size_{Size{0, 0, 0}};
  // Image data (pixel color values)
  unsigned char *image_data_{nullptr};

public:
  // Default constructor initialize member variables.
  StbImageDataView() = default;
  // constructor which gets an image path and loads the image if exists
  StbImageDataView(const std::string &image_path);
  // Move constructor
  StbImageDataView(StbImageDataView &&other_image);
  // Return image size
  Size size() const;
  // Return true if image data is null
  bool empty() const;
  // Return the number of rows of the image
  int rows() const;
  // Return the number of cols of the image
  int cols() const;
  // Return the color at a specific index
  ftxui::Color at(const int &row, const int &col) const;
  // Move assignment operator
  StbImageDataView &operator=(StbImageDataView &&object);
  // Destructor
  ~StbImageDataView();
};

}; // namespace pixelator