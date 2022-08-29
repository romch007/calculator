#pragma once

#ifndef CALCULATOR_FUNCTION_CALL_HPP
#define CALCULATOR_FUNCTION_CALL_HPP

#include <calculator/Prerequisites.hpp>
#include <calculator/Ast/Expression.hpp>

namespace calculator::Ast {
  class FunctionCall;

  using FunctionCallPtr = std::unique_ptr<FunctionCall>;

  class FunctionCall : public Expression {
   public:
    enum class FunctionType {
      Sin,
      Cos,
      Tan
    };

    FunctionCall(FunctionType type, ExpressionPtr argument);
    FunctionCall(const FunctionCall&) = delete;
    FunctionCall(FunctionCall&&) noexcept = default;

    FunctionCall &operator=(const FunctionCall &) = delete;
    FunctionCall &operator=(FunctionCall &&) noexcept = default;

    [[nodiscard]] inline ExpressionType GetType() const override;
    [[nodiscard]] std::string ToString() const override;
    [[nodiscard]] double Compute() const override;

    FunctionType functionType;
    ExpressionPtr argument;
  };

  inline ExpressionType FunctionCall::GetType() const {
    return ExpressionType::Operation;
  }
}

#endif