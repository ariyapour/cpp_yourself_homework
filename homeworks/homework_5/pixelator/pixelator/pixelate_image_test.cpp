#include <gtest/gtest.h>
#include <fstream>
#include "pixelator/drawer.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/pixelate_image.hpp"
#include <iostream>
#include <filesystem>

const std::filesystem::path image_path{"../../pixelator/test_data/grumpy.png"};
const std::filesystem::path test_path{"../../pixelator/test_data/grumpy_pixelated.txt"};


TEST(pixelator_tests, test1){
    pixelator::StbImageDataView image{image_path};

    //Load the test data
    std::ifstream inFile;
    inFile.open(test_path);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string test_data = strStream.str();
    
    //Perform the pixelation
    pixelator::Drawer drawer{ftxui::Dimension::Full()};
    drawer.Set(pixelator::PixelateImage(image, drawer.size()));
    std::string computed_result = drawer.ToString();

    EXPECT_EQ(computed_result, test_data);
}