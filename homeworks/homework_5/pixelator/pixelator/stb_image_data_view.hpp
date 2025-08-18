#pragma once
#include <filesystem>
#include <string>

#include "ftxui/screen/color.hpp"

namespace pixelator {
inline unsigned char * AllocateMemory(const std::size_t& length){return new unsigned char[length];}
inline void FreeMemory(unsigned char * ptr) {delete[] ptr;}
// A struct to store image size
struct Size {
  int rows;
  int cols;
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
  int rows_{};
  int cols_{};
  int channels_{};
  // Image data (pixel color values)
  unsigned char *image_data_{nullptr};

 public:
  // Default constructor initialize member variables.
  StbImageDataView() = default;
  // constructor which gets an image path and loads the image if exists
  StbImageDataView(const std::string &image_path);
  // Custom copy constructor
  StbImageDataView(const StbImageDataView& other_image);
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
  // Return the number of channels of the image
  int channels() const;
  // Return the color at a specific index
  ftxui::Color at(const int &row, const int &col) const;
  // Copy assignment operator
  StbImageDataView &operator=(const StbImageDataView &other_image);
  // Move assignment operator
  StbImageDataView &operator=(StbImageDataView &&other_image);
  // Custom Destructor since we allocate memory manually in our class
  ~StbImageDataView();
};

};  // namespace pixelator