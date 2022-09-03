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

  /**
   * A simple token produced by the lexer
   */
  struct Token {
    TokenType type;
    std::variant<double, std::string_view> data;
  };

  /**
   * Transform a string into tokens
   * @param str The input string
   * @return The tokens
   */
  std::vector<Token> Tokenise(std::string_view str);
  const char* ToString(TokenType tokenType);
}  // namespace calculator

#endif
