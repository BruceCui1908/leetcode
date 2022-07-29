#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
public:
  Rectangle() = delete;
  constexpr Rectangle(double width, double height)
      : width_{width}, height_{height} {}

  constexpr double width() const { return width_; }
  constexpr double height() const { return height_; }

  double Calc(Visitor *visitor) override { return visitor->Calc(this); }

private:
  double width_;
  double height_;
};