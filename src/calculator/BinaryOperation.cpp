#include <calculator/Ast/BinaryOperation.hpp>
#include <cmath>

namespace calculator::Ast {
  BinaryOperation::BinaryOperation(BinaryOpType op) : operationType(op) {}

  std::string BinaryOperation::GetOpSymbol() const {
    switch (operationType) {
      case BinaryOpType::Add:
        return "Add";
      case BinaryOpType::Substract:
        return "Sub";
      case BinaryOpType::Multiply:
        return "Mult";
      case BinaryOpType::Divide:
        return "Div";
      case BinaryOpType::Exponent:
        return "Power";
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

  std::vector<std::string> BinaryOperation::PrintDebug() const {
    std::vector<std::string> lines;
    lines.emplace_back("BinaryOperation(");
    for (const auto& line : lhs->PrintDebug()) {
      lines.push_back("  " + line);
    }
    lines.push_back(GetOpSymbol());
    for (const auto& line : rhs->PrintDebug()) {
      lines.push_back("  " + line);
    }
    lines.emplace_back(")");
    return lines;
  }
}  // namespace calculator::Ast
