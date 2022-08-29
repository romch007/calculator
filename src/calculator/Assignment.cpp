#include <calculator/Ast/Assignment.hpp>

#include "calculator/Context.hpp"

namespace calculator::Ast {
  Assignment::Assignment(std::string_view variableName, ExpressionPtr content,
                         bool constant)
      : variableName(variableName),
        content(std::move(content)),
        constant(constant) {}

  double Assignment::Compute(Context& context) const {
    auto contentValue = content->Compute(context);
    context.AddVariable(std::string(variableName), contentValue, constant);
    return contentValue;
  }
}  // namespace calculator::Ast