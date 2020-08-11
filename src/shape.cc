#include "../include/shape.h"
namespace robot
{

void Point::set(const double &x_, const double &y_)
{
  x = x_;
  y = y_;
};
void Point::set(const Point &p)
{
  x = p.x;
  y = p.y;
};

void Polygon::set(const Polygon &p)
{
  size_ = p.size_;
  for (size_t i = 0; i < size_; ++i)
  {
    vertices[i].set(p.vertices[i]);
  }
}

void Rectangle::getCenter(Point *p)
{
  p->x = center_.x;
  p->y = center_.y;
};
void Rectangle::getWidth(double *width) { *width = width_; };
void Rectangle::getHight(double *hight) { *hight = hight_; };
uint8_t Rectangle::getSize() { return size_; };
} // namespace robot