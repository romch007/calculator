#include <calculator/Ast/FunctionCall.hpp>
#include <cmath>

namespace calculator::Ast {
  FunctionCall::FunctionCall(FunctionCall::FunctionType type,
                             ExpressionPtr argument) : functionType(type), argument(std::move(argument)) {}

  std::string FunctionCall::ToString() const { return "not implemented"; }

  double FunctionCall::Compute() const {
    auto argumentValue = argument->Compute();
    switch (functionType) {
      case FunctionType::Sin:
        return std::sin(argumentValue);
    }
  }
}