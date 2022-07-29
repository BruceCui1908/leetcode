#pragma once

class Circle;
class Rectangle;
class Triangle;

class Visitor {
public:
  Visitor() = default;
  virtual ~Visitor() = default;

  static constexpr double pi = 3.14;

  virtual double Calc(Circle *) = 0;

  virtual double Calc(Rectangle *) = 0;

  virtual double Calc(Triangle *) = 0;
};