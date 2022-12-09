#pragma once

#ifndef CALCULATOR_DEBUG_HPP
#define CALCULATOR_DEBUG_HPP

#include <string>
#include <vector>

namespace calculator::Ast {
  class Debug {
   public:
    [[nodiscard]] virtual std::vector<std::string> PrintDebug() const = 0;

   protected:
    inline static std::string spacing(unsigned int level = 1);
  };

  std::string Debug::spacing(unsigned int level) {
    std::string result;
    for (int i = 0; i < level; i++) {
      result += "  ";
    }
    return result;
  }
}  // namespace calculator::Ast

#endif
