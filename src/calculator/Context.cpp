#include <calculator/Context.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Parser.hpp>
#include <stdexcept>
#include <numbers>

namespace calculator {
  void Evaluate(const std::string& input, std::ostream& outputStream) {
    Context c(outputStream);
    c.Execute(input);
  }

  Context::Context(std::ostream& outputStream) : m_outputStream(outputStream) {
    m_variables.insert({"PI", std::numbers::pi});
    m_variables.insert({"E", std::numbers::e});
  }

  void Context::Execute(const std::string& input) {
    auto tokens = Tokenise(input);
    if (tokens.size() <= 1) throw std::runtime_error("no token");
    Parser parser{};
    auto ast = parser.Parse(tokens);
    if (ast) ast->Execute(*this);
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

  std::ostream& Context::GetOutputStream() const {
    return m_outputStream;
  }
}  // namespace calculator