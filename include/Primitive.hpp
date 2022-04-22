#ifndef CALCULATOR_PRIMITVE_HPP
#define CALCULATOR_PRIMITVE_HPP

#include <Expression.hpp>

namespace calculator {

  class Primitive : virtual public Expression {
  public:
    using PrimitivePtr = std::shared_ptr<Primitive>;
  };

  using PrimitivePtr = Primitive::PrimitivePtr;

}

#endif
