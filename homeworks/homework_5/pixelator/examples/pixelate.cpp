// #include "pixelator/drawer.hpp"
// #include "pixelator/pixelate_image.hpp"
#include "pixelator/stb_image_data_view.hpp"

#include <cstddef>
#include <filesystem>
#include <iostream>
#include <utility>

namespace {
// using pixelator::Drawer;
// using pixelator::PixelateImage;
using pixelator::StbImageDataView;
}  // namespace

int main(int argc, char **argv) {
  if (argc < 2) { std::cerr << "No image provided." << std::endl; }


  StbImageDataView image{argv[1]};
  if (image.empty()) {
    std::cerr << "Image could not be loaded" << std::endl;
    exit(1);
  }

  //--------My debugs
  // std::cout<<"Loaded image size: "<<image.rows()<<"x"<<image.cols()<<std::endl;

  // StbImageDataView other_image = std::move(image);
  // std::cout<<"other image After using move constructor with a loaded image: "<< other_image.rows()<<"x"<< other_image.cols()<<std::endl;
  // StbImageDataView empty_image;
  // std::cout<<"Empty image created. Image size: "<< empty_image.rows()<<"x"<< empty_image.cols()<<std::endl;
  // empty_image = std::move(image);
  // std::cout<<"Empty image assigned by other Image: "<< empty_image.rows()<<"x"<< empty_image.cols()<<std::endl;
  //--------My debugs


  // Drawer drawer{ftxui::Dimension::Full()};

  // drawer.Set(PixelateImage(image, drawer.size()));
  // drawer.Draw();
  return 0;
}
