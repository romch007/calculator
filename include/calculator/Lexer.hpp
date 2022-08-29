#pragma once

#ifndef CALCULATOR_LEXER_HPP
#define CALCULATOR_LEXER_HPP

#include <calculator/Prerequisites.hpp>
#include <optional>
#include <string_view>
#include <vector>

namespace calculator {

  enum class TokenType {
#define CALCULATOR_TOKEN(X) X,

#include <calculator/Lang/TokenList.hpp>
  };

  struct Token {
    TokenType type;
    std::optional<double> data;
  };

  std::vector<Token> Tokenise(std::string_view str);
}  // namespace calculator

#endif
