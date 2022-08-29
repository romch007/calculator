#include <calculator/Ast/BinaryOperation.hpp>
#include <calculator/Ast/UnaryOperation.hpp>
#include <calculator/Ast/Variable.hpp>
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
    ParserContext context;
    context.tokenCount = tokens.size();
    context.tokens = tokens.data();

    m_context = &context;

    Ast::ExpressionPtr expression;

    // Use ternary?
    if (Peek().type == TokenType::Const || Peek().type == TokenType::Let)
      expression = ParseAssignment();
    else
      expression = ParseExpression();

    const Token &nextToken = Peek();
    if (nextToken.type != TokenType::EOL)
      throw std::runtime_error("extra inputs at end of line");

    return expression;
  }

  Ast::AssignmentPtr Parser::ParseAssignment() {
    const Token &keyword = Advance();
    Ast::AssignmentType assignmentType;
    switch (keyword.type) {
      case TokenType::Let:
        assignmentType = Ast::AssignmentType::Mutable;
        break;
      case TokenType::Const:
        assignmentType = Ast::AssignmentType::Constant;
        break;
    }
    const Token &identifier = Advance();
    if (identifier.type == TokenType::Identifier) {
      auto variableName = std::get<std::string_view>(identifier.data);
      if (Advance().type == TokenType::Equal) {
        auto content = ParseExpression();
        return std::make_unique<Ast::Assignment>(
            variableName, std::move(content), assignmentType);
      } else {
        throw std::runtime_error("expected equal sign");
      }
    } else {
      throw std::runtime_error("expected identifier");
    }
  }

  Ast::ExpressionPtr Parser::ParseExpression() {
    auto expression = ParseTerm();
    for (;;) {
      const Token &token = Peek();
      Ast::BinaryOpType opType;

      bool invalid = false;
      switch (token.type) {
        case TokenType::Add:
          opType = Ast::BinaryOpType::Add;
          break;
        case TokenType::Substract:
          opType = Ast::BinaryOpType::Substract;
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
    return std::make_unique<Ast::Number>(std::get<double>(nextToken.data));
  }

  Ast::ExpressionPtr Parser::ParseTerm() {
    auto term = ParseFactor();

    for (;;) {
      const Token &token = Peek();
      Ast::BinaryOpType opType;

      bool invalid = false;
      switch (token.type) {
        case TokenType::Multiply:
          opType = Ast::BinaryOpType::Multiply;
          break;
        case TokenType::Divide:
          opType = Ast::BinaryOpType::Divide;
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
      auto exponent =
          std::make_unique<Ast::BinaryOperation>(Ast::BinaryOpType::Exponent);
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
      case TokenType::Identifier: {
        auto identifierText = std::get<std::string_view>(token.data);
        Consume();
        if (Peek().type == TokenType::OpenParenthesis) {
          exponent = ParseFunctionCall(identifierText);
        } else {
          // Simple variable
          exponent = std::make_unique<Ast::Variable>(identifierText);
        }
        break;
      }
      case TokenType::OpenParenthesis:
        Consume();
        exponent = ParseExpression();
        if (Advance().type != TokenType::CloseParenthesis)
          throw std::runtime_error("expected ')'");
        break;
      case TokenType::Add:
        Consume();
        exponent = ParseExpression();
        break;
      case TokenType::Substract:
        Consume();
        exponent = std::make_unique<Ast::UnaryOperation>(
            Ast::UnaryOpType::Negate, ParseExponent());
        break;
      default:
        throw std::runtime_error("invalid token");
    }

    return exponent;
  }

  Ast::FunctionCallPtr Parser::ParseFunctionCall(
      std::string_view identifierText) {
    Consume();
    auto argument = ParseExpression();
    if (Advance().type != TokenType::CloseParenthesis)
      throw std::runtime_error("expected ')'");
    return std::make_unique<Ast::FunctionCall>(
        MatchFunctionType(identifierText), std::move(argument));
  }

  Ast::FunctionType Parser::MatchFunctionType(std::string_view identifier) {
    if (identifier == "sin") {
      return Ast::FunctionType::Sin;
    } else if (identifier == "cos") {
      return Ast::FunctionType::Cos;
    } else if (identifier == "tan") {
      return Ast::FunctionType::Tan;
    }
    throw std::runtime_error("unknown function '" + std::string(identifier) +
                             "'");
  }

}  // namespace calculator