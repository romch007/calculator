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
    AddBuiltinConstant("PI", std::numbers::pi);
    AddBuiltinConstant("E", std::numbers::e);
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
    if (m_variables.contains(variableName) && m_variables.at(variableName).assignmentType == Ast::AssignmentType::Constant)
      throw std::runtime_error("trying to assign to constant variable");
    m_variables.insert_or_assign(std::move(variableName), Variable { value, assignmentType });
  }

  double Context::GetVariable(const std::string& variableName) const {
    if (!m_variables.contains(variableName))
      throw std::runtime_error("variable '" + variableName + "' not found");
    return m_variables.at(variableName).value;
  }

  std::ostream& Context::GetOutputStream() const {
    return m_outputStream;
  }
  
  void Context::AddBuiltinConstant(std::string constantName, double value) {
    SetVariable(std::move(constantName), value, Ast::AssignmentType::Constant);
  }
}  // namespace calculator