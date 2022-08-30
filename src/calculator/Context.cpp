#include <calculator/Context.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Parser.hpp>
#include <stdexcept>

namespace calculator {
  void Evaluate(const std::string& input) {
    Context c;
    c.Execute(input);
  }

  void Context::Execute(const std::string& input) {
    auto tokens = Tokenise(input);
    if (tokens.size() <= 1) throw std::runtime_error("no token");
    Parser parser{};
    auto ast = parser.Parse(tokens);
    ast->Execute(*this);
  }

  void Context::SetVariable(std::string variableName, double value,
                            Ast::AssignmentType assignmentType) {
    if (assignmentType == Ast::AssignmentType::Constant &&
        m_variables.contains(variableName)) {
      throw std::runtime_error("attempting to mutate a constant variable");
    } else if (assignmentType == Ast::AssignmentType::Existing &&
               !m_variables.contains(variableName)) {
      throw std::runtime_error("variable '" + variableName + "' not found");
    }
    m_variables.insert_or_assign(std::move(variableName), value);
  }

  double Context::GetVariable(const std::string& variableName) const {
    if (!m_variables.contains(variableName))
      throw std::runtime_error("variable '" + variableName + "' not found");
    return m_variables.at(variableName);
  }
}  // namespace calculator