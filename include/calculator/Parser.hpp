#pragma once

#ifndef CALCULATOR_PARSER_HPP
#define CALCULATOR_PARSER_HPP

#include <calculator/Ast/Expression.hpp>
#include <calculator/Ast/Number.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Prerequisites.hpp>

namespace calculator {
class Parser {
 public:
  Parser() = default;
  ~Parser() = default;

  Ast::ExpressionPtr Parse(const std::vector<Token> &tokens);

 private:
  const Token &Advance();
  void Consume(std::size_t count = 1);
  const Token &Peek(std::size_t advance = 0);

  Ast::ExpressionPtr ParseExpression();
  Ast::ExpressionPtr ParseTerm();
  Ast::ExpressionPtr ParseFactor();
  Ast::ExpressionPtr ParseExponent();
  Ast::NumberPtr ParseNumber();

  struct Context {
    std::size_t tokenCount;
    std::size_t tokenIndex = 0;
    const Token *tokens;
  };

  Context *m_context;
};
}  // namespace calculator

#endif