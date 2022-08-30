#pragma once

#ifndef CALCULATOR_EXPRESSION_HPP
#define CALCULATOR_EXPRESSION_HPP

#include <calculator/Context.hpp>
#include <calculator/Enums.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>
#include <string>

namespace calculator::Ast {

  class Expression;

  using ExpressionPtr = std::unique_ptr<Expression>;

  class Expression {
   public:
    Expression() = default;
    Expression(const Expression&) = delete;
    Expression(Expression&&) noexcept = default;
    virtual ~Expression() = default;

    Expression& operator=(const Expression&) = delete;
    Expression& operator=(Expression&&) noexcept = default;

    [[nodiscard]] virtual double Compute(Context& context) const = 0;
  };
}  // namespace calculator::Ast

#endif