#pragma once

#ifndef CALCULATOR_VARIABLE_HPP
#define CALCULATOR_VARIABLE_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Prerequisites.hpp>

namespace calculator::Ast {

  class Variable;

  using VariablePtr = std::unique_ptr<Variable>;

  class Variable : public Expression {
   public:
    Variable() = default;
    ~Variable() override = default;
    Variable(const Variable&) = delete;
    Variable(Variable&&) noexcept = default;

    Variable& operator=(const Variable&) = delete;
    Variable& operator=(Variable&&) noexcept = default;

    inline explicit Variable(std::string_view variableName);

    [[nodiscard]] double Compute(Context& context) const override;
    std::vector<std::string> PrintDebug() const override;

    std::string_view variableName;
  };

  inline Variable::Variable(std::string_view variableName)
      : variableName(variableName) {}
}  // namespace calculator::Ast

#endif
