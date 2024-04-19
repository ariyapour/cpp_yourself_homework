#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "pixelator/drawer.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/pixelate_image.hpp"

const std::filesystem::path image_path{"../../pixelator/test_data/grumpy.png"};
const std::filesystem::path test_path{"../../pixelator/test_data/grumpy_pixelated_211_fixed.txt"};
const int test_data_drawer_size = 211;


TEST(pixelator_tests, test1){
    pixelator::StbImageDataView image{image_path};

    //Load the test data
    std::ifstream inFile;
    inFile.open(test_path);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string test_data = strStream.str();
    
    //Perform pixelation
    pixelator::Drawer drawer{ftxui::Dimension::Fixed(test_data_drawer_size)};
    drawer.Set(pixelator::PixelateImage(image, drawer.size()));
    std::string computed_result = drawer.ToString();

    EXPECT_EQ(computed_result, test_data);
}