#include <calculator/Ast/Number.hpp>

namespace calculator::Ast {
    std::string Number::ToString() const {
        return "Number(" + std::to_string(value) + ")";
    }

    double Number::Compute() const {
        return value;
    }
}