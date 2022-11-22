#include <calculator/Ast/FunctionCall.hpp>
#include <cmath>

namespace calculator::Ast {
  FunctionCall::FunctionCall(FunctionType type,
                             std::vector<ExpressionPtr> arguments)
      : functionType(type), arguments(std::move(arguments)) {}

  double FunctionCall::Compute(Context& context) const {
    std::vector<double> argumentsValue;
    argumentsValue.reserve(arguments.size());
    for (const auto& argument : arguments) {
      argumentsValue.push_back(argument->Compute(context));
    }
    switch (functionType) {
      case FunctionType::Sin:
        return std::sin(argumentsValue.at(0));
      case FunctionType::Cos:
        return std::cos(argumentsValue.at(0));
      case FunctionType::Tan:
        return std::tan(argumentsValue.at(0));
      case FunctionType::Abs:
        return std::abs(argumentsValue.at(0));
    }
  }
}  // namespace calculator::Ast