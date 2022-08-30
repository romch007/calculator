#include <calculator/Ast/Assignment.hpp>

namespace calculator::Ast {
  Assignment::Assignment(std::string_view variableName, ExpressionPtr content,
                         AssignmentType assignmentType)
      : variableName(variableName),
        content(std::move(content)),
        assignmentType(assignmentType) {
  }

  void Assignment::Execute(Context& context) const {
    auto contentValue = content->Compute(context);
    context.SetVariable(std::string(variableName), contentValue,
                        assignmentType);
  }
}  // namespace calculator::Ast