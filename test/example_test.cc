#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "../include/constant.h"
#include "../include/display.h"
#include "../include/shape.h"
using namespace cv;
using namespace std;
using namespace robot;

void testCV()
{
    cv::namedWindow("robotics", CV_WINDOW_AUTOSIZE);
    // cv::namedWindow("robotics", cv::WINDOW_NORMAL);

    //配置点数 默认4个
    const int pointnum = 100;

    double a[pointnum];
    double b[pointnum];
    a[0] = 10.0;
    b[0] = 10.0;
    for (size_t i = 1; i < pointnum; i++)
    {
        a[i] = a[i - 1] + 5;
        b[i] = b[i - 1] + 5;
    }

    //颜色集合
    int scalar_cur = 0;
    cv::Scalar color[3] = {cv::Scalar(255, 0, 0), cv::Scalar(0, 255, 0),
            cv::Scalar(0, 0, 255)};

    //画线
    for (int i = 0; i < pointnum - 1; i++)
    {
        cv::Mat img(700, 1300, CV_8UC3, cv::Scalar(255, 255, 255));
        cv::RotatedRect box(cv::Point(a[i], b[i]), cv::Size(100, 50), 30);
        cv::Point2f pts[4];
        box.points(pts);
        for (int j = 0; j < 4; ++j)
        {
            cv::line(img, pts[j], pts[(j + 1) % 4], Scalar(0, 0, 255), 2);
        }

        //三种颜色循环使用
        scalar_cur = (scalar_cur + 1) % 3;
        // cv::imwrite("./csp.png", img);
        cv::imshow("robotics", img);
        cv::waitKey(100);
    }
    cv::waitKey(0);
}

int main(int argc, char **argv)
{
    // testCV();
    Image_handle img;
    char win_name[] = "robot_test";
    image_init(&img, win_name, 800, 1000);
    windows_init(win_name);
    robot::Polygon poly;
    poly.size_ = 4;
    Color color_;

    robot::Point ps[] = {{20, 20}, {100, 20}, {100, 100}, {20, 100}};
    for (size_t i = 0; i < poly.size_; i++)
    {
        poly.vertices[i].x = ps[i].x;
        poly.vertices[i].y = ps[i].y;
    }
    for (size_t i = 0; i < 100; i++)
    {
        printf("i %d \n", int(i));
        for (size_t j = 0; j < poly.size_; j++)
        {
            poly.vertices[j].x += 1.0;
            poly.vertices[j].y += 1.5;
        }
        draw_polygon(&img, &poly, color_.green);

        image_clear(&img);
    }

    Polygon poly_array[100];
    poly_array[0].size_ = poly.size_;
    for (size_t j = 0; j < poly.size_; j++)
    {
        poly_array[0].vertices[j].x = poly.vertices[j].x + 800;
        poly_array[0].vertices[j].y = poly.vertices[j].y + 800;
    }
    for (size_t i = 1; i < 100; i++)
    {
        poly_array[i].size_ = poly.size_;
        for (size_t j = 0; j < poly.size_; j++)
        {
            poly_array[i].vertices[j].x = poly_array[i - 1].vertices[j].x - 10;
            poly_array[i].vertices[j].y = poly_array[i - 1].vertices[j].y - 10;
        }
    }

    draw_polygon_array(&img, poly_array, 100, color_.blue);

    cv::waitKey(0);
}
