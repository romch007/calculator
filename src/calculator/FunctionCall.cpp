#include <calculator/Ast/FunctionCall.hpp>
#include <cmath>

namespace calculator::Ast {
  FunctionCall::FunctionCall(FunctionType type, ExpressionPtr argument)
      : functionType(type), argument(std::move(argument)) {
  }

  double FunctionCall::Compute(Context& context) const {
    auto argumentValue = argument->Compute(context);
    switch (functionType) {
      case FunctionType::Sin:
        return std::sin(argumentValue);
      case FunctionType::Cos:
        return std::cos(argumentValue);
      case FunctionType::Tan:
        return std::tan(argumentValue);
    }
  }
}  // namespace calculator::Ast