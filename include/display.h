#pragma once
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "constant.h"
#include "shape.h"

namespace robot
{
struct Image_handle
{
    char windows_name[robot::MAX_WINDOWS_NAME_SIZE];
    uint32_t hight;
    uint32_t width;

    cv::Scalar background_color;

    cv::Mat img;
};

struct Color
{
    cv::Scalar black;
    cv::Scalar red;
    cv::Scalar blue;
    cv::Scalar green;
    cv::Scalar gray;
    cv::Scalar purple;
    cv::Scalar orange;
    Color() : black(cv::Scalar(0, 0, 0)),
              red(cv::Scalar(0, 0, 255)),
              blue(cv::Scalar(255, 0, 0)),
              green(cv::Scalar(0, 255, 0)),
              gray(cv::Scalar(192, 192, 192)),
              purple(cv::Scalar(240, 32, 160)),
              orange(cv::Scalar(0, 97, 255)){};
};

void image_init(Image_handle *img, char *win_name, uint32_t hight,
                uint32_t width);

void windows_init(char *win_name);

void image_clear(Image_handle *img);

void draw_polygon(Image_handle *img, robot::Polygon *poly,
                  cv::Scalar color);

void draw_polygon_array(Image_handle *img,
                        robot::Polygon *poly_array,
                        uint64_t size,
                        cv::Scalar color_);
} // namespace robot