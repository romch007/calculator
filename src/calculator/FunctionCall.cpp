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

  std::vector<std::string> FunctionCall::PrintDebug() const {
    std::vector<std::string> lines;
    lines.emplace_back("FunctionCall(");
    // lines.push_back(std::string(functionType)); TODO
    lines.emplace_back(spacing() + "with arguments");
    for (const auto& argument : arguments) {
      for (const auto& line : argument->PrintDebug()) {
        lines.push_back(spacing(2) + line);
      }
    }
    lines.emplace_back(")");
    return lines;
  }
}  // namespace calculator::Ast
