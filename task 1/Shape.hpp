#pragma once

#include "Visitor.hpp"

class Shape {
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual double Calc(Visitor *) = 0;
};