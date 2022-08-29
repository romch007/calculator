#include <calculator/Ast/BinaryOperation.hpp>
#include <calculator/Ast/UnaryOperation.hpp>
#include <calculator/Parser.hpp>
#include <stdexcept>

namespace calculator {
const Token &Parser::Advance() {
  const Token &token = Peek();
  m_context->tokenIndex++;
  return token;
}

void Parser::Consume(std::size_t count) { m_context->tokenIndex += count; }

const Token &Parser::Peek(std::size_t advance) {
  return m_context->tokens[m_context->tokenIndex + advance];
}

Ast::ExpressionPtr Parser::Parse(const std::vector<Token> &tokens) {
  Context context;
  context.tokenCount = tokens.size();
  context.tokens = tokens.data();

  m_context = &context;

  auto expression = ParseExpression();

  const Token &nextToken = Peek();
  if (nextToken.type != TokenType::EOL)
    throw std::runtime_error("extra inputs at end of line");

  return expression;
}

Ast::ExpressionPtr Parser::ParseExpression() {
  auto expression = ParseTerm();
  for (;;) {
    const Token &token = Peek();
    Ast::BinaryOperation::BinaryOpType opType;

    bool invalid = false;
    switch (token.type) {
      case TokenType::Add:
        opType = Ast::BinaryOperation::BinaryOpType::Add;
        break;
      case TokenType::Substract:
        opType = Ast::BinaryOperation::BinaryOpType::Substract;
        break;
      default:
        invalid = true;
        break;
    }
    if (invalid) break;

    Consume();
    auto term = std::make_unique<Ast::BinaryOperation>(opType);
    term->lhs = std::move(expression);
    term->rhs = ParseTerm();
    expression = std::move(term);
  }
  return expression;
}

Ast::NumberPtr Parser::ParseNumber() {
  const Token &nextToken = Advance();
  return std::make_unique<Ast::Number>(*nextToken.data);
}

Ast::ExpressionPtr Parser::ParseTerm() {
  auto term = ParseFactor();

  for (;;) {
    const Token &token = Peek();
    Ast::BinaryOperation::BinaryOpType opType;

    bool invalid = false;
    switch (token.type) {
      case TokenType::Multiply:
        opType = Ast::BinaryOperation::BinaryOpType::Multiply;
        break;
      case TokenType::Divide:
        opType = Ast::BinaryOperation::BinaryOpType::Divide;
        break;
      default:
        invalid = true;
        break;
    }
    if (invalid) break;

    Consume();
    auto factor = std::make_unique<Ast::BinaryOperation>(opType);
    factor->lhs = std::move(term);
    factor->rhs = ParseFactor();
    term = std::move(factor);
  }

  return term;
}

Ast::ExpressionPtr Parser::ParseFactor() {
  auto factor = ParseExponent();
  const Token &token = Peek();

  if (token.type == TokenType::Exponent) {
    Consume();
    auto exponent = std::make_unique<Ast::BinaryOperation>(
        Ast::BinaryOperation::BinaryOpType::Exponent);
    exponent->lhs = std::move(factor);
    exponent->rhs = ParseFactor();
    factor = std::move(exponent);
  }

  return factor;
}

Ast::ExpressionPtr Parser::ParseExponent() {
  Ast::ExpressionPtr exponent;
  const Token &token = Peek();

  switch (token.type) {
    case TokenType::Number:
      exponent = ParseNumber();
      break;
    case TokenType::OpenParenthesis:
      Consume();
      exponent = ParseExpression();
      if (Advance().type != TokenType::CloseParenthesis)
        throw std::runtime_error("expected ')'");
      break;
    case TokenType::Substract:
      Consume();
      exponent = std::make_unique<Ast::UnaryOperation>(
          Ast::UnaryOperation::UnaryOpType::Negate, ParseExponent());
      break;
    default:
      throw std::runtime_error("invalid token");
  }

  return exponent;
}

}  // namespace calculator