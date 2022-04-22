#ifndef CALCULATOR_FRACTION_HPP
#define CALCULATOR_FRACTION_HPP

#include <Operation.hpp>
#include <Primitive.hpp>

namespace calculator {

  class Fraction : public Operation, public Primitive {
  public:
    using FractionPtr = std::shared_ptr<Fraction>;
    Fraction(ExpressionPtr num, ExpressionPtr den);

    ExpressionPtr num() const;
    ExpressionPtr den() const;
  protected:
    FractionPtr compute(FractionPtr first, FractionPtr second) const override;
    std::string op_sign() const override;
  };

  using FractionPtr = Fraction::FractionPtr;

}

#endif
