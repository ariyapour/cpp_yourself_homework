#pragma once
#include<filesystem>
#include <string>

namespace pixelator{
    struct Size{
        int row;
        int col;
        int channels;
    };
    
    class StbImageDataView
    {
    private:
        std::filesystem::path image_path_;
        int cols_{};
        int rows_{};
        int channels_{};
        unsigned char *image_data_{};
    public:
        Size size()const;
        bool empty()const;
        StbImageDataView(const std::string& image_path);
        // ~StbImageDataView();
    };
    
};