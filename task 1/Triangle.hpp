#pragma once

class Triangle : public Shape {
public:
  Triangle() = delete;
  constexpr Triangle(double width, double height)
      : width_{width}, height_{height} {}

  constexpr double width() const { return width_; }
  constexpr double height() const { return height_; }

  double Calc(Visitor *visitor) override { return visitor->Calc(this); }

private:
  double width_;
  double height_;
};