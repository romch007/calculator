#include <calculator/Ast/Assignment.hpp>

namespace calculator::Ast {
  Assignment::Assignment(std::string_view variableName, ExpressionPtr content,
                         AssignmentType assignmentType)
      : variableName(variableName),
        content(std::move(content)),
        assignmentType(assignmentType) {}

  void Assignment::Execute(Context& context) const {
    auto contentValue = content->Compute(context);
    context.SetVariable(std::string(variableName), contentValue,
                        assignmentType);
  }

  std::vector<std::string> Assignment::PrintDebug() const {
    std::vector<std::string> lines;
    lines.emplace_back("Assignment(");
    lines.push_back("  " + std::string(variableName));
    lines.emplace_back("assigned to");
    for (const auto& line : content->PrintDebug()) {
      lines.push_back("  " + line);
    }
    return lines;
  };
}  // namespace calculator::Ast
