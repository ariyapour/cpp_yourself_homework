
#include "pixelator/image.hpp"

namespace pixelator_tests{
    const std::filesystem::path image_path{"../../pixelator/test_data/test_grumpy.png"};
    const std::filesystem::path pixelator_image_path{"../../pixelator/test_data/test.png"};
    const int pixelator_test_new_size = 3;

    //coordinates of test pixel in test image
    const int test_pixel_x = 100;
    const int test_pixel_y = 150;

    //Pixel coller of test image at position 100x15
    const pixelator::Color test_pixel_color{155, 140, 133};

    //Resolution of the test image
    const int test_image_rows = 268;
    const int test_image_cols = 273;

}