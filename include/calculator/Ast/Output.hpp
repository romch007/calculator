#pragma once

#ifndef CALCULATOR_OUTPUT_HPP
#define CALCULATOR_OUTPUT_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Ast/Node.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>

namespace calculator::Ast {

  class Output;

  using OutputPtr = std::unique_ptr<Output>;

  class Output : public Node {
   public:
    explicit Output(ExpressionPtr content);
    Output(const Output&) = delete;
    Output(Output&&) noexcept = default;

    Output& operator=(const Output&) = delete;
    Output& operator=(Output&&) noexcept = default;

    void Execute(Context& context) const override;

    ExpressionPtr content;
  };
}  // namespace calculator::Ast

#endif
