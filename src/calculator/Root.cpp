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

  std::vector<std::string> Root::PrintDebug() const {
    std::vector<std::string> lines;
    for (const auto& child : m_statements) {
      for (const auto& line : child->PrintDebug()) {
        lines.push_back(line);
      }
    }
    return lines;
  }
}  // namespace calculator::Ast
