#pragma once

#ifndef CALCULATOR_BINARYOPERATION_HPP
#define CALCULATOR_BINARYOPERATION_HPP

#include <calculator/Prerequisites.hpp>
#include <calculator/Ast/Expression.hpp>
#include <memory>

namespace calculator::Ast {

    class BinaryOperation;

    using BinaryOperationPtr = std::unique_ptr<BinaryOperation>;

    class BinaryOperation : public Expression {
    public:
        enum class BinaryOpType {
            Add,
            Substract,
            Multiply,
            Divide,
            Exponent
        };

        explicit BinaryOperation(BinaryOpType op);
        BinaryOperation(const BinaryOperation&) = delete;
        BinaryOperation(BinaryOperation&&) noexcept = default;
        ~BinaryOperation() = default;

        BinaryOperation& operator=(const BinaryOperation&) = delete;
        BinaryOperation& operator=(BinaryOperation&&) noexcept = default;

        [[nodiscard]] inline ExpressionType GetType() const override;
        [[nodiscard]] std::string ToString() const override;
        [[nodiscard]] double Compute() const override;

        BinaryOpType operationType;

        ExpressionPtr rhs;
        ExpressionPtr lhs;
    private:
        [[nodiscard]] std::string GetOpSymbol() const;
    };

    inline ExpressionType BinaryOperation::GetType() const {
        return ExpressionType::Operation;
    }
}

#endif
