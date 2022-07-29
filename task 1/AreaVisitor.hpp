#pragma once

#include "Visitor.hpp"

class AreaVisitor : public Visitor {
public:
  AreaVisitor() = default;
  ~AreaVisitor() = default;

  double Calc(Circle *) override;

  double Calc(Rectangle *) override;

  double Calc(Triangle *) override;
};