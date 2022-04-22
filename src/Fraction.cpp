#include <Fraction.hpp>
#include <Scalar.hpp>
#include <utils.hpp>

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

    auto new_num = first_num * second_den;
    auto new_den = first_den * second_num;

    auto div = calculator::gcd(new_num, new_den);

    new_num /= div;
    new_den /= div;

    return std::make_shared<Fraction>(
      std::make_shared<Scalar>(new_num),
      std::make_shared<Scalar>(new_den)
    );
  }
}
