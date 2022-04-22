#include <Addition.hpp>
#include <Scalar.hpp>

namespace calculator {

  Addition::Addition(ExpressionPtr first, ExpressionPtr second, bool difference) :
    Operation(first, second),
    m_difference(difference) {}

  std::string Addition::op_sign() const {
    return m_difference ? "-" : "+";
  }

  FractionPtr Addition::compute(FractionPtr first, FractionPtr second) const {
    auto first_num = dynamic_cast<Scalar*>(first->num().get())->value();
    auto first_den = dynamic_cast<Scalar*>(first->den().get())->value();
    auto second_num = dynamic_cast<Scalar*>(second->num().get())->value();
    auto second_den = dynamic_cast<Scalar*>(second->den().get())->value();

    auto new_num = m_difference ? first_num * second_den - first_den * second_num : first_num * second_den + first_den * second_num;

    return std::make_shared<Fraction>(
      std::make_shared<Scalar>(new_num),
      std::make_shared<Scalar>(first_den * second_den)
    );
  }
}
