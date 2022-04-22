#ifndef CALCULATOR_MULTIPLICATION_HPP
#define CALCULATOR_MULTIPLICATION_HPP

#include <Operation.hpp>
#include <Primitive.hpp>

namespace calculator {

  class Multiplication : public Operation {
  public:
    Multiplication(ExpressionPtr first, ExpressionPtr second);
  protected:
    FractionPtr compute(FractionPtr first, FractionPtr second) const override;
  protected:
    std::string op_sign() const override;
  };

}

#endif
