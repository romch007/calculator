#pragma once

#ifndef CALCULATOR_NUMBER_HPP
#define CALCULATOR_NUMBER_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Prerequisites.hpp>

namespace calculator::Ast {

class Number;

using NumberPtr = std::unique_ptr<Number>;

class Number : public Expression {
 public:
  Number() = default;
  ~Number() override = default;
  Number(const Number &) = delete;
  Number(Number &&) noexcept = default;

  Number &operator=(const Number &) = delete;
  Number &operator=(Number &&) noexcept = default;

  inline explicit Number(double initial_value);

  [[nodiscard]] inline ExpressionType GetType() const override;
  [[nodiscard]] std::string ToString() const override;
  [[nodiscard]] double Compute() const override;

  double value{0.0};
};

inline ExpressionType Number::GetType() const { return ExpressionType::Number; }

inline Number::Number(double initial_value) : value(initial_value) {}
}  // namespace calculator::Ast

#endif