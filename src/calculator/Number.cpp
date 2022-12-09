#include <calculator/Ast/Number.hpp>

namespace calculator::Ast {
  double Number::Compute(Context& context) const {
    return value;
  }

  std::vector<std::string> Number::PrintDebug() const {
    return {std::to_string(value)};
  };
}  // namespace calculator::Ast
