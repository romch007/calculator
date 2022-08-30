#pragma once

#ifndef CALCULATOR_BINARYOPERATION_HPP
#define CALCULATOR_BINARYOPERATION_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>

#include "calculator/Context.hpp"

namespace calculator::Ast {

  class BinaryOperation;

  using BinaryOperationPtr = std::unique_ptr<BinaryOperation>;

  class BinaryOperation : public Expression {
   public:
    explicit BinaryOperation(BinaryOpType op);
    BinaryOperation(const BinaryOperation&) = delete;
    BinaryOperation(BinaryOperation&&) noexcept = default;
    ~BinaryOperation() = default;

    BinaryOperation& operator=(const BinaryOperation&) = delete;
    BinaryOperation& operator=(BinaryOperation&&) noexcept = default;

    [[nodiscard]] double Compute(Context& context) const override;

    BinaryOpType operationType;
    ExpressionPtr rhs;
    ExpressionPtr lhs;

   private:
    [[nodiscard]] std::string GetOpSymbol() const;
  };
}  // namespace calculator::Ast

#endif
