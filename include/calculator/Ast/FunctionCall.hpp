#pragma once

#ifndef CALCULATOR_FUNCTION_CALL_HPP
#define CALCULATOR_FUNCTION_CALL_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Prerequisites.hpp>
#include <vector>

namespace calculator::Ast {
  class FunctionCall;

  using FunctionCallPtr = std::unique_ptr<FunctionCall>;

  class FunctionCall : public Expression {
   public:
    FunctionCall(FunctionType type, std::vector<ExpressionPtr> arguments);
    FunctionCall(const FunctionCall&) = delete;
    FunctionCall(FunctionCall&&) noexcept = default;

    FunctionCall& operator=(const FunctionCall&) = delete;
    FunctionCall& operator=(FunctionCall&&) noexcept = default;

    [[nodiscard]] double Compute(Context& context) const override;

    FunctionType functionType;
    std::vector<ExpressionPtr> arguments;
  };
}  // namespace calculator::Ast

#endif