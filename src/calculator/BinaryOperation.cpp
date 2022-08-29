#include <calculator/Ast/BinaryOperation.hpp>
#include <cmath>

namespace calculator::Ast {
  BinaryOperation::BinaryOperation(BinaryOpType op) : operationType(op) {}

  std::string BinaryOperation::GetOpSymbol() const {
    switch (operationType) {
      case BinaryOpType::Add:
        return "+";
      case BinaryOpType::Substract:
        return "-";
      case BinaryOpType::Multiply:
        return "*";
      case BinaryOpType::Divide:
        return "/";
      case BinaryOpType::Exponent:
        return "^";
    }
  }

  double BinaryOperation::Compute(Context& context) const {
    auto leftValue = lhs->Compute(context);
    auto rightValue = rhs->Compute(context);
    switch (operationType) {
      case BinaryOpType::Add:
        return leftValue + rightValue;
      case BinaryOpType::Substract:
        return leftValue - rightValue;
      case BinaryOpType::Multiply:
        return leftValue * rightValue;
      case BinaryOpType::Divide:
        return leftValue / rightValue;
      case BinaryOpType::Exponent:
        return std::pow(leftValue, rightValue);
    }
  }
}  // namespace calculator::Ast
