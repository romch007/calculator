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
    Number(const Number&) = delete;
    Number(Number&&) noexcept = default;

    Number& operator=(const Number&) = delete;
    Number& operator=(Number&&) noexcept = default;

    inline explicit Number(double initialValue);

    [[nodiscard]] double Compute(Context& context) const override;

    std::vector<std::string> PrintDebug() const override;

    double value{0.0};
  };

  inline Number::Number(double initialValue) : value(initialValue) {}
}  // namespace calculator::Ast

#endif
