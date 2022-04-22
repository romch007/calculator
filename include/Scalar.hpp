#ifndef CALCULATOR_SCALAR_HPP
#define CALCULATOR_SCALAR_HPP

#include <Primitive.hpp>
#include <Fraction.hpp>

namespace calculator {

  class Scalar : public Primitive {
  public:
    Scalar(int value);

    FractionPtr to_fraction() const;
    PrimitivePtr evaluate() const override;

    int value() const;
  protected:
    void print(std::ostream& os) const override;
  private:
    int m_value { 0 };
  };

}

#endif
