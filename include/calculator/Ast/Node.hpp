#pragma once

#ifndef CALCULATOR_NODE_HPP
#define CALCULATOR_NODE_HPP

#include <calculator/Context.hpp>
#include <calculator/Enums.hpp>
#include <calculator/Prerequisites.hpp>
#include <memory>
#include <string>

namespace calculator::Ast {

  class Node;

  using NodePtr = std::unique_ptr<Node>;

  /**
   * A generic Node in the AST
   */
  class Node {
   public:
    Node() = default;
    Node(const Node&) = delete;
    Node(Node&&) noexcept = default;
    virtual ~Node() = default;

    Node& operator=(const Node&) = delete;
    Node& operator=(Node&&) noexcept = default;

    /**
     * Execute the node
     * @param context The execution context
     */
    virtual void Execute(Context& context) const = 0;
  };
}  // namespace calculator::Ast

#endif
