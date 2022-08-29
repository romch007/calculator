#pragma once

#ifndef CALCULATOR_EXPRESSION_HPP
#define CALCULATOR_EXPRESSION_HPP

#include <calculator/Prerequisites.hpp>
#include <memory>
#include <string>

namespace calculator::Ast {

    class Expression;

    using ExpressionPtr = std::unique_ptr<Expression>;

    enum class ExpressionType {
        Operation,
        Number
    };

    class Expression {
    public:
        Expression() = default;
        Expression(const Expression&) = delete;
        Expression(Expression&&) noexcept = default;
        virtual ~Expression() = default;

        Expression& operator=(const Expression&) = delete;
        Expression& operator=(Expression&&) noexcept = default;

        [[nodiscard]] virtual ExpressionType GetType() const = 0;
        [[nodiscard]] virtual std::string ToString() const = 0;
        [[nodiscard]] virtual double Compute() const = 0;
    };
}

#endif