#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;

void testCV() {
  cv::namedWindow("robotics", CV_WINDOW_AUTOSIZE);
  // cv::namedWindow("robotics", cv::WINDOW_NORMAL);

  //配置点数 默认4个
  const int pointnum = 100;

  double a[pointnum];
  double b[pointnum];
  a[0] = 10.0;
  b[0] = 10.0;
  for (size_t i = 1; i < pointnum; i++) {
    a[i] = a[i - 1] + 5;
    b[i] = b[i - 1] + 5;
  }

  //颜色集合
  int scalar_cur = 0;
  cv::Scalar color[3] = {cv::Scalar(255, 0, 0), cv::Scalar(0, 255, 0),
                         cv::Scalar(0, 0, 255)};

  //画线
  for (int i = 0; i < pointnum - 1; i++) {
    cv::Mat img(700, 1300, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::RotatedRect box(cv::Point(a[i], b[i]), cv::Size(100, 50), 30);
    cv::Point2f pts[4];
    box.points(pts);
    for (int j = 0; j < 4; ++j) {
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

int main(int argc, char **argv) { testCV(); }
