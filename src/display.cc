#include "../include/display.h"

namespace robot
{
void image_init(Image_handle *img, char *win_name, uint32_t hight,
                uint32_t width)
{
    img->hight = hight;
    img->width = width;
    strncpy(img->windows_name, win_name, robot::MAX_WINDOWS_NAME_SIZE - 1);
    img->background_color = cv::Scalar(255, 255, 255);
    img->img = cv::Mat(hight, width, CV_8UC3, img->background_color);
}

void windows_init(char *win_name)
{
    cvNamedWindow(win_name, CV_WINDOW_AUTOSIZE);
}

void image_clear(Image_handle *img)
{
    img->img = cv::Mat(img->hight, img->width, CV_8UC3, img->background_color);
}

void draw_polygon(Image_handle *img, robot::Polygon *poly,
                  cv::Scalar color)
{

    CvPoint p1, p2;
    int i = 0;
    for (int j = 0; j < poly->size_; ++j)
    {
        p1.x = poly->vertices[j].x;
        p1.y = poly->vertices[j].y;
        i = j + 1;
        if (i == poly->size_)
        {
            i = 0;
        }

        p2.x = poly->vertices[i].x;
        p2.y = poly->vertices[i].y;
        cv::line(img->img, p1, p2, color, 2);
    }
    cv::imshow(img->windows_name, img->img);
    cv::waitKey(1);
}

void draw_polygon_array(Image_handle *img,
                        robot::Polygon *poly_array,
                        uint64_t size,
                        cv::Scalar color_)

{
    for (size_t i = 0; i < size; ++i)
    {
        draw_polygon(img, &poly_array[i], color_);
    }
}
} // namespace robot