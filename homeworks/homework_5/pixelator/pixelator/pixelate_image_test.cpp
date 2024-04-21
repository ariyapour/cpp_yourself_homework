#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "pixelator/drawer.hpp"
#include "pixelator/stb_image_data_view.hpp"
#include "pixelator/pixelate_image.hpp"
#include "pixelator/test_global_variables.hpp"


TEST(pixelator_tests, test1){
    pixelator::StbImageDataView image{pixelator_tests::image_path};

    //Load the test data
    std::ifstream inFile;
    inFile.open(pixelator_tests::test_path);
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string test_data = strStream.str();
    
    //Perform pixelation
    pixelator::Drawer drawer{ftxui::Dimension::Fixed(pixelator_tests::test_data_drawer_size)};
    drawer.Set(pixelator::PixelateImage(image, drawer.size()));
    std::string computed_result = drawer.ToString();
    EXPECT_EQ(computed_result, test_data) << "Computed results: "<< std::endl << computed_result<< std::endl<<"Test data: "<< std::endl << test_data<<std::endl;
}