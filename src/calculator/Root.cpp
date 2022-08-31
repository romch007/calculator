#include <calculator/Ast/Root.hpp>

namespace calculator::Ast {
  void Root::Execute(Context& context) const {
    for (const auto& statement : statements) {
      statement->Execute(context);
    }
  }
}  // namespace calculator::Ast