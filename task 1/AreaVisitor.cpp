#include "AreaVisitor.hpp"

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

double AreaVisitor::Calc(Circle *circle) {
  return circle->radius() * circle->radius() * pi;
}

double AreaVisitor::Calc(Rectangle *rect) {
  return rect->width() * rect->height();
}

double AreaVisitor::Calc(Triangle *tri) {
  return tri->width() * tri->height() / 2;
}