#include <calculator/Ast/Variable.hpp>

namespace calculator::Ast {
  double Variable::Compute(Context& context) const {
    return context.GetVariable(std::string(variableName));
  }

  std::vector<std::string> Variable::PrintDebug() const {
    return {"Variable(" + std::string(variableName) + ")"};
  }
}  // namespace calculator::Ast
