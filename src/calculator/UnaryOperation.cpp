#include <calculator/Ast/UnaryOperation.hpp>
#include <cmath>

#include "calculator/Context.hpp"

namespace calculator::Ast {
  UnaryOperation::UnaryOperation(UnaryOpType op, Ast::ExpressionPtr operand)
      : operationType(op), operand(std::move(operand)) {
  }

  std::string UnaryOperation::GetOpSymbol() const {
    switch (operationType) {
      case UnaryOpType::Negate:
        return "-";
    }
  }

  double UnaryOperation::Compute(Context& context) const {
    auto operandValue = operand->Compute(context);
    switch (operationType) {
      case UnaryOpType::Negate:
        return -operandValue;
    }
  }
}  // namespace calculator::Ast
