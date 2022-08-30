#include <calculator/Ast/Output.hpp>
#include <iostream>

namespace calculator::Ast {
  Output::Output(ExpressionPtr content) : content(std::move(content)) {
  }

  void Output::Execute(Context& context) const {
    auto computedValue = content->Compute(context);
    std::cout << computedValue << std::endl;
  }
}  // namespace calculator::Ast