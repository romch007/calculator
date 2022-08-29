#include <calculator/Context.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Parser.hpp>

namespace calculator {
  double Evaluate(const std::string &input) {
    Context c;
    return c.Evaluate(input);
  }

  double Context::Evaluate(const std::string &input) {
    auto tokens = Tokenise(input);
    Parser parser{};
    auto ast = parser.Parse(tokens);
    return ast->Compute(*this);
  }

  void Context::AddVariable(std::string_view variableName, double value) {
    m_variables.insert({variableName, value});
  }

  double Context::GetVariable(std::string_view variableName) {
    if (!m_variables.contains(variableName))
      throw std::runtime_error("variable '" + std::string(variableName) +
                               "' not found");
    return m_variables[variableName];
  }
}  // namespace calculator