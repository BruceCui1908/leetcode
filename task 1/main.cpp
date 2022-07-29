#include <iostream>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

#include "AreaVisitor.hpp"

int main() {
  Shape *shapes[] = {new Circle{12}, new Rectangle{14, 17},
                     new Triangle{20, 18}};

  AreaVisitor visitor;

  for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i++) {
    auto area = shapes[i]->Calc(&visitor);
    std::cout << area << std::endl;
    delete shapes[i];
  }
}