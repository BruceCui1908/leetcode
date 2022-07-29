#pragma once

#include "Shape.hpp"

class Circle : public Shape {
public:
  Circle() = delete;

  constexpr explicit Circle(double radius) : radius_{radius} {}

  constexpr double radius() const { return radius_; }

  double Calc(Visitor *visitor) override { return visitor->Calc(this); }

private:
  double radius_;
};