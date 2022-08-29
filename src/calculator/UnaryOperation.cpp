#include <calculator/Ast/UnaryOperation.hpp>
#include <cmath>

namespace calculator::Ast {
  UnaryOperation::UnaryOperation(UnaryOpType op, Ast::ExpressionPtr operand)
      : operationType(op), operand(std::move(operand)) {}

  std::string UnaryOperation::ToString() const {
    std::string result = "Operation(op: " + GetOpSymbol() + ",\n";
    result += operand->ToString() + "\n";
    result += ")";
    return result;
  }

  std::string UnaryOperation::GetOpSymbol() const {
    switch (operationType) {
      case UnaryOpType::Negate:
        return "-";
    }
  }

  double UnaryOperation::Compute() const {
    auto operandValue = operand->Compute();
    switch (operationType) {
      case UnaryOpType::Negate:
        return -operandValue;
    }
  }
}  // namespace calculator::Ast
