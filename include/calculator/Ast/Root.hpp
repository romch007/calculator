#pragma once

#ifndef CALCULATOR_ROOT_HPP
#define CALCULATOR_ROOT_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Ast/Node.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>
#include <vector>

namespace calculator::Ast {

  class Root;

  using RootPtr = std::unique_ptr<Root>;

  class Root : public Node {
   public:
    Root() = default;
    Root(const Root&) = delete;
    Root(Root&&) noexcept = default;
    ~Root() = default;

    Root& operator=(const Root&) = delete;
    Root& operator=(Root&&) noexcept = default;

    void Execute(Context& context) const override;

    std::vector<NodePtr> statements;
  };
}  // namespace calculator::Ast

#endif
