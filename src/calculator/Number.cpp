#include <calculator/Ast/Number.hpp>

namespace calculator::Ast {
  double Number::Compute(Context& context) const { return value; }
}  // namespace calculator::Ast