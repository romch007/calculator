#pragma once

#ifndef CALCULATOR_ENUMS_HPP
#define CALCULATOR_ENUMS_HPP

namespace calculator::Ast {
  enum class AssignmentType {
    Constant,
    Mutable
  };

  enum class BinaryOpType {
    Add,
    Substract,
    Multiply,
    Divide,
    Exponent
  };

  enum class FunctionType {
    Sin,
    Cos,
    Tan
  };

  enum class UnaryOpType {
    Negate,
  };
}  // namespace calculator::Ast

#endif