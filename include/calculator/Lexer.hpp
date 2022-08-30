#pragma once

#ifndef CALCULATOR_LEXER_HPP
#define CALCULATOR_LEXER_HPP

#include <calculator/Prerequisites.hpp>
#include <string_view>
#include <variant>
#include <vector>

namespace calculator {

  enum class TokenType {
#define CALCULATOR_TOKEN(X) X,

#include <calculator/Lang/TokenList.hpp>
  };

  struct Token {
    TokenType type;
    std::variant<double, std::string_view> data;
  };

  std::vector<Token> Tokenise(std::string_view str);
  const char* ToString(TokenType tokenType);
}  // namespace calculator

#endif
