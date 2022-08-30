#pragma once

#ifndef CALCULATOR_PARSER_HPP
#define CALCULATOR_PARSER_HPP

#include <calculator/Ast/Assignment.hpp>
#include <calculator/Ast/Expression.hpp>
#include <calculator/Ast/FunctionCall.hpp>
#include <calculator/Ast/Number.hpp>
#include <calculator/Enums.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Prerequisites.hpp>

namespace calculator {
  class Parser {
   public:
    Parser() = default;
    ~Parser() = default;

    Ast::ExpressionPtr Parse(const std::vector<Token>& tokens);

   private:
    const Token& Advance();
    void Consume(std::size_t count = 1);
    const Token& Peek(std::size_t advance = 0);
    const Token& Expect(const Token& token, TokenType tokenType);
    const Token& Expect(TokenType tokenType);

    Ast::AssignmentPtr ParseAssignment();
    Ast::FunctionCallPtr ParseFunctionCall(std::string_view identifierText);
    Ast::ExpressionPtr ParseExpression();
    Ast::ExpressionPtr ParseTerm();
    Ast::ExpressionPtr ParseFactor();
    Ast::ExpressionPtr ParseExponent();
    Ast::NumberPtr ParseNumber();
    [[nodiscard]] static Ast::FunctionType MatchFunctionType(
        std::string_view identifier);

    struct ParserContext {
      std::size_t tokenCount;
      std::size_t tokenIndex = 0;
      const Token* tokens;
    };

    ParserContext* m_context;
  };
}  // namespace calculator

#endif