#pragma once

#ifndef CALCULATOR_PARSER_HPP
#define CALCULATOR_PARSER_HPP

#include <calculator/Ast/Assignment.hpp>
#include <calculator/Ast/Expression.hpp>
#include <calculator/Ast/FunctionCall.hpp>
#include <calculator/Ast/Node.hpp>
#include <calculator/Ast/Number.hpp>
#include <calculator/Ast/Output.hpp>
#include <calculator/Ast/Root.hpp>
#include <calculator/Enums.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Prerequisites.hpp>

namespace calculator {
  class Parser {
   public:
    Parser() = default;
    ~Parser() = default;

    /**
     * Transform a list of tokens into an abstract syntax tree
     * @param tokens The list of tokens
     * @return The abstract syntax tree
     */
    Ast::RootPtr Parse(const std::vector<Token>& tokens);

   private:
    /**
     * Consume and return the next token
     * @return The next token
     */
    const Token& Advance();

    /**
     * Consume the next count
     * @param count How far to consume
     */
    void Consume(std::size_t count = 1);

    /**
     * Peek the next token without consuming it
     * @param advance How fare to peek
     * @return The next token
     */
    const Token& Peek(std::size_t advance = 0);

    /**
     * Expect a certain type of token
     * @param token The token to check
     * @param tokenType The expected token type
     * @return The token to check
     */
    const Token& Expect(const Token& token, TokenType tokenType);
    const Token& Expect(TokenType tokenType);

    /**
     * Parse an assignment
     * @return The assignment
     */
    Ast::AssignmentPtr ParseAssignment();

    /**
     * Parse an output
     * @return The output
     */
    Ast::OutputPtr ParseOutput();

    /**
     * Parse a function call
     * @param identifierText The function name
     * @return The function call
     */
    Ast::FunctionCallPtr ParseFunctionCall(std::string_view identifierText);

    /**
     * Parse an expression
     * @return The expression
     */
    Ast::ExpressionPtr ParseExpression();

    /**
     * Parse a term
     * @return The term
     */
    Ast::ExpressionPtr ParseTerm();

    /**
     * Parse a factor
     * @return The factor
     */
    Ast::ExpressionPtr ParseFactor();

    /**
     * Parse an exponent
     * @return The exponent
     */
    Ast::ExpressionPtr ParseExponent();

    /**
     * Parse a number
     * @return The number
     */
    Ast::NumberPtr ParseNumber();

    /**
     * Match a function name against a function type
     * @param identifier The function name
     * @return The function type
     */
    [[nodiscard]] static Ast::FunctionType MatchFunctionType(
        std::string_view identifier);

    /**
     * Parsing state
     */
    struct ParserContext {
      std::size_t tokenCount;
      std::size_t tokenIndex = 0;
      const Token* tokens;
    };

    ParserContext* m_context;
  };
}  // namespace calculator

#endif