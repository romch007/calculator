#ifndef CALCULATOR_ADDITION_HPP
#define CALCULATOR_ADDITION_HPP

#include <Operation.hpp>

namespace calculator {

  class Addition : public Operation {
  public:
    Addition(ExpressionPtr first, ExpressionPtr second, bool difference = false);
  protected:
    std::string op_sign() const override;
    FractionPtr compute(FractionPtr first, FractionPtr second) const override;
  private:
    bool m_difference { false };
  };

}

#endif
