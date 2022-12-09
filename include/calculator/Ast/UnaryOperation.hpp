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
    UnaryOperation(UnaryOpType op, ExpressionPtr operand);
    UnaryOperation(const UnaryOperation&) = delete;
    UnaryOperation(UnaryOperation&&) noexcept = default;

    UnaryOperation& operator=(const UnaryOperation&) = delete;
    UnaryOperation& operator=(UnaryOperation&&) noexcept = default;

    [[nodiscard]] double Compute(Context& context) const override;
    [[nodiscard]] std::vector<std::string> PrintDebug() const override;

    UnaryOpType operationType;
    ExpressionPtr operand;

   private:
    /**
     * Get the operation symbol
     * @return The operation symbol
     */
    [[nodiscard]] std::string GetOpSymbol() const;
  };
}  // namespace calculator::Ast

#endif
