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

  void Context::AddVariable(std::string variableName, double value,
                            bool constant) {
    if (constant && m_variables.contains(variableName)) {
      throw std::runtime_error("attempting to mutate a constant variable");
    }
    m_variables.insert({std::move(variableName), value});
  }

  double Context::GetVariable(const std::string &variableName) const {
    if (!m_variables.contains(variableName))
      throw std::runtime_error("variable '" + variableName + "' not found");
    return m_variables.at(variableName);
  }
}  // namespace calculator