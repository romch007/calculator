#pragma once

#ifndef CALCULATOR_ASSIGNMENT_HPP
#define CALCULATOR_ASSIGNMENT_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>

namespace calculator::Ast {

  class Assignment;

  using AssignmentPtr = std::unique_ptr<Assignment>;

  class Assignment : public Expression {
   public:
    Assignment(std::string_view variableName, ExpressionPtr content,
               bool constant);
    Assignment(const Assignment &) = delete;
    Assignment(Assignment &&) noexcept = default;
    ~Assignment() = default;

    Assignment &operator=(const Assignment &) = delete;
    Assignment &operator=(Assignment &&) noexcept = default;

    [[nodiscard]] inline ExpressionType GetType() const override;
    [[nodiscard]] double Compute(Context &context) const override;

    std::string_view variableName;
    ExpressionPtr content;
    bool constant;
  };

  inline ExpressionType Assignment::GetType() const {
    return ExpressionType::Operation;
  }
}  // namespace calculator::Ast

#endif
