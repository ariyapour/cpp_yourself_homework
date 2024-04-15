#define STB_IMAGE_IMPLEMENTATION
#include "pixelator/stb_image_data_view.hpp"
#include "stb/stb_image.h"

pixelator::StbImageDataView::StbImageDataView(const std::string& image_path)
:image_path_(image_path){
    //TODO: The last argument is kLoadAllChannels that we set 0 for now. figure out how should we do it for the calss or should we leave it as it is
    image_data_ = stbi_load(image_path.c_str(), &cols_, &rows_, &channels_, 0);
}

pixelator::Size pixelator::StbImageDataView::size()const{
    return pixelator::Size{rows_, cols_, channels_};
}

bool pixelator::StbImageDataView::empty()const{
    return (image_data_ == nullptr) ? true:false;
}