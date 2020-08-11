#ifndef SHAPE_H
#define SHAPE_H

#include "constant.h"
#include <iostream>

namespace robot
{

struct Point
{
  double x;
  double y;
  void set(const double &x_, const double &y_);
  void set(const Point &p);
};

struct Rectangle
{
  Point p0;
  Point p1;
  Point p2;
  Point p3;
  Point center_;
  double width_;
  double hight_;
  uint8_t size_;
  void getCenter(Point *p);
  void getWidth(double *width);
  void getHight(double *hight);
  uint8_t getSize();
};

struct Polygon
{
  Point vertices[POLYGON_MAX_VERTICE_SIZE];
  uint8_t size_;
  void set(const Polygon &p);
};

struct ConvexPolygon
{
  Point vertices[POLYGON_MAX_VERTICE_SIZE];
  uint8_t size_;
};
} // namespace robot

#endif
