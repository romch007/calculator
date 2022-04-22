#ifndef CALCULATOR_OPERATION_HPP
#define CALCULATOR_OPERATION_HPP

#include <Expression.hpp>

namespace calculator {

  class Fraction;
  using FractionPtr = std::shared_ptr<Fraction>;

  class Operation : virtual public Expression {
  public:
    Operation(ExpressionPtr first, ExpressionPtr second);
    virtual ~Operation();
    PrimitivePtr evaluate() const override;
  protected:
    ExpressionPtr m_first;
    ExpressionPtr m_second;

    void print(std::ostream& os) const override;
    virtual std::string op_sign() const = 0;
    virtual FractionPtr compute(FractionPtr first, FractionPtr second) const = 0;
  private:
    std::shared_ptr<Fraction> cast_to_fraction(PrimitivePtr primitive) const;
  };

}

#endif
