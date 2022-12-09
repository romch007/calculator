#include <calculator/Ast/Output.hpp>
#include <iostream>

namespace calculator::Ast {
  Output::Output(ExpressionPtr content) : content(std::move(content)) {}

  void Output::Execute(Context& context) const {
    auto computedValue = content->Compute(context);
    context.GetOutputStream() << computedValue << std::endl;
  }

  std::vector<std::string> Output::PrintDebug() const {
    std::vector<std::string> lines;
    lines.push_back("Output(");
    for (const auto& line : content->PrintDebug()) {
      lines.push_back("  " + line);
    }
    lines.push_back(")");
    return lines;
  }
}  // namespace calculator::Ast
