#pragma once

#ifndef CALCULATOR_UNARYOPERATION_HPP
#define CALCULATOR_UNARYOPERATION_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>

namespace calculator::Ast {

class UnaryOperation;

using UnaryOperationPtr = std::unique_ptr<UnaryOperation>;

class UnaryOperation : public Expression {
 public:
  enum class UnaryOpType {
    Negate,
  };

  UnaryOperation(UnaryOpType op, Ast::ExpressionPtr operand);

  UnaryOperation(const UnaryOperation &) = delete;

  UnaryOperation(UnaryOperation &&) noexcept = default;

  ~UnaryOperation() = default;

  UnaryOperation &operator=(const UnaryOperation &) = delete;

  UnaryOperation &operator=(UnaryOperation &&) noexcept = default;

  [[nodiscard]] inline ExpressionType GetType() const override;

  [[nodiscard]] std::string ToString() const override;

  [[nodiscard]] double Compute() const override;

  UnaryOpType operationType;

  ExpressionPtr operand;

 private:
  [[nodiscard]] std::string GetOpSymbol() const;
};

inline ExpressionType UnaryOperation::GetType() const {
  return ExpressionType::Operation;
}
}  // namespace calculator::Ast

#endif
