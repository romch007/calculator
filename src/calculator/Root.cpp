#include <calculator/Ast/Root.hpp>

namespace calculator::Ast {
  void Root::AddStatement(NodePtr statement) {
    m_statements.push_back(std::move(statement));
  }

  void Root::Execute(Context& context) const {
    for (const auto& statement : m_statements) {
      statement->Execute(context);
    }
  }
}  // namespace calculator::Ast