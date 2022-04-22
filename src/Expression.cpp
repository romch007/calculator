#include <Expression.hpp>

namespace calculator {

  Expression::~Expression() {}

  std::ostream& operator<<(std::ostream& os, const Expression& expr) {
    expr.print(os);
    return os;
  }

}
