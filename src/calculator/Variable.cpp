#include <calculator/Ast/Variable.hpp>

namespace calculator::Ast {
  double Variable::Compute(Context &context) const {
    return context.GetVariable(std::string(variableName));
  }
}  // namespace calculator::Ast