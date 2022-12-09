#pragma once

#ifndef CALCULATOR_ASSIGNMENT_HPP
#define CALCULATOR_ASSIGNMENT_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Ast/Node.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>

namespace calculator::Ast {

  class Assignment;

  using AssignmentPtr = std::unique_ptr<Assignment>;

  class Assignment : public Node {
   public:
    Assignment(std::string_view variableName, ExpressionPtr content,
               AssignmentType assignmentType);
    Assignment(const Assignment&) = delete;
    Assignment(Assignment&&) noexcept = default;

    Assignment& operator=(const Assignment&) = delete;
    Assignment& operator=(Assignment&&) noexcept = default;

    void Execute(Context& context) const override;

    [[nodiscard]] std::vector<std::string> PrintDebug() const override;

    std::string_view variableName;
    ExpressionPtr content;
    AssignmentType assignmentType;
  };
}  // namespace calculator::Ast

#endif
