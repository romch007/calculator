#include <Operation.hpp>
#include <Scalar.hpp>

namespace calculator {

  Operation::Operation(ExpressionPtr first, ExpressionPtr second) :
    m_first(first),
    m_second(second) {}

  Operation::~Operation() {}

  void Operation::print(std::ostream& os) const {
    os << "(" << *m_first << op_sign() << *m_second << ")";
  }

  std::shared_ptr<Fraction> Operation::cast_to_fraction(PrimitivePtr primitive) const {
    auto scalar_form = dynamic_cast<Scalar*>(primitive.get());
    if (scalar_form != nullptr) {
      return scalar_form->to_fraction();
    }
    auto fraction_form = dynamic_cast<Fraction*>(primitive.get());
    if (fraction_form != nullptr) {
      return std::make_shared<Fraction>(fraction_form->m_first, fraction_form->m_second);
    }
    return nullptr;
  }

  PrimitivePtr Operation::evaluate() const {
    auto first_operand = cast_to_fraction(m_first->evaluate());
    auto second_operand = cast_to_fraction(m_second->evaluate());
    auto result = compute(first_operand, second_operand);
    auto num = dynamic_cast<Scalar*>(result->num().get())->value();
    auto den = dynamic_cast<Scalar*>(result->den().get())->value();
    if (den == 1) {
      return std::make_shared<Scalar>(num);
    }
    return result;
  }

}
