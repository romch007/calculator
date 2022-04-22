#ifndef CALCULATOR_EXPRESSION_HPP
#define CALCULATOR_EXPRESSION_HPP

#include <iostream>
#include <memory>

namespace calculator {

  class Primitive;
  using PrimitivePtr = std::shared_ptr<Primitive>;


  class Expression {
  public:
    using ExpressionPtr = std::shared_ptr<Expression>;

    virtual ~Expression();

    virtual PrimitivePtr evaluate() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Expression& expr);
  protected:
    virtual void print(std::ostream& os) const = 0;
  };

  using ExpressionPtr = Expression::ExpressionPtr;

}

#endif
