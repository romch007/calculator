#pragma once

#ifndef CALCULATOR_EXPRESSION_HPP
#define CALCULATOR_EXPRESSION_HPP

#include <calculator/Ast/Debug.hpp>
#include <calculator/Context.hpp>
#include <calculator/Enums.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>
#include <string>

namespace calculator::Ast {

  class Expression;

  using ExpressionPtr = std::unique_ptr<Expression>;

  /**
   * A generic computable expression
   */
  class Expression : public Debug {
   public:
    Expression() = default;
    Expression(const Expression&) = delete;
    Expression(Expression&&) noexcept = default;
    virtual ~Expression() = default;

    Expression& operator=(const Expression&) = delete;
    Expression& operator=(Expression&&) noexcept = default;

    /**
     * Compute the expression
     * @param context The execution context
     * @return The result
     */
    [[nodiscard]] virtual double Compute(Context& context) const = 0;
  };
}  // namespace calculator::Ast

#endif
