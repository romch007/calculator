#pragma once

#ifndef CALCULATOR_DEBUG_HPP
#define CALCULATOR_DEBUG_HPP

#include <string>
#include <vector>

namespace calculator::Ast {
  class Debug {
   public:
    virtual std::vector<std::string> PrintDebug() const = 0;
  };
}  // namespace calculator::Ast

#endif
