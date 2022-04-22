#include <Scalar.hpp>

namespace calculator {

  Scalar::Scalar(int value) : m_value(value) {}

  void Scalar::print(std::ostream& os) const {
    os << m_value;
  }

  PrimitivePtr Scalar::evaluate() const {
    return std::make_shared<Scalar>(m_value);
  }

  FractionPtr Scalar::to_fraction() const {
    auto num = std::make_shared<Scalar>(m_value);
    auto den = std::make_shared<Scalar>(1);
    return std::make_shared<Fraction>(num, den);
  }

  int Scalar::value() const {
    return m_value;
  }
}
