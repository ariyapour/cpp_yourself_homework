#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "pixelator/drawer.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/pixelate_image.hpp"
#include "pixelator/test_global_variables.hpp"
#include <iostream>

TEST(pixelator_tests, test1){
    pixelator::StbImageDataView image{pixelator_tests::image_path};
    std::cerr<<"Loded image size: "<< image.size().row<< " X "<< image.size().col<<std::endl;
    pixelator::Color color = image.at(pixelator_tests::test_pixel_x,pixelator_tests::test_pixel_y);
    std::cerr<<"Image color at 100X150: "<< color.red<< " "<< color.green<< " "<< color.blue<<std::endl;

    //Load the test data
    std::ifstream inFile;
    inFile.open(pixelator_tests::test_path);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string test_data = strStream.str();
    
    //Perform pixelation
    pixelator::Drawer drawer{ftxui::Dimension::Fixed(pixelator_tests::test_data_drawer_size)};
    pixelator::Image pixelated_image = pixelator::PixelateImage(image, drawer.size());
    std::cerr<<"Pixelated image size: "<<pixelated_image.size().row<<"X"<< pixelated_image.size().col<<std::endl;
    drawer.Set(pixelated_image);
    EXPECT_EQ(drawer.ToString(), test_data) << "Computed results: "<< std::endl << drawer.ToString()<< std::endl<<"Test data: "<< std::endl << test_data<<std::endl;
}