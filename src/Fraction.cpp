#include <Fraction.hpp>
#include <Scalar.hpp>

namespace calculator {

  Fraction::Fraction(ExpressionPtr num, ExpressionPtr den) : Operation(num, den) {}

  std::string Fraction::op_sign() const {
    return "/";
  }

  ExpressionPtr Fraction::num() const {
    return m_first;
  }

  ExpressionPtr Fraction::den() const {
    return m_second;
  }

  FractionPtr Fraction::compute(FractionPtr first, FractionPtr second) const {
    auto first_num = dynamic_cast<Scalar*>(first->num().get())->value();
    auto first_den = dynamic_cast<Scalar*>(first->den().get())->value();
    auto second_num = dynamic_cast<Scalar*>(second->num().get())->value();
    auto second_den = dynamic_cast<Scalar*>(second->den().get())->value();

    return std::make_shared<Fraction>(
      std::make_shared<Scalar>(first_num * second_num),
      std::make_shared<Scalar>(first_den * second_den)
    );
  }
}
