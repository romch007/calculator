#include <calculator/Ast/UnaryOperation.hpp>
#include <cmath>

namespace calculator::Ast {
  UnaryOperation::UnaryOperation(UnaryOpType op, Ast::ExpressionPtr operand)
      : operationType(op), operand(std::move(operand)) {}

  std::string UnaryOperation::GetOpSymbol() const {
    switch (operationType) {
      case UnaryOpType::Negate:
        return "Negate";
    }
  }

  double UnaryOperation::Compute(Context& context) const {
    auto operandValue = operand->Compute(context);
    switch (operationType) {
      case UnaryOpType::Negate:
        return -operandValue;
    }
  }

  std::vector<std::string> UnaryOperation::PrintDebug() const {
    std::vector<std::string> lines;
    lines.emplace_back("UnaryOperation(");
    lines.push_back(GetOpSymbol());
    for (const auto& line : operand->PrintDebug()) {
      lines.push_back(line);
    }
    return lines;
  }
}  // namespace calculator::Ast
