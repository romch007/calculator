#pragma once

#ifndef CALCULATOR_LEXER_HPP
#define CALCULATOR_LEXER_HPP

#include <calculator/Prerequisites.hpp>
#include <optional>
#include <vector>
#include <string_view>

namespace calculator {

    enum class TokenType {
#define CALCULATOR_TOKEN(X) X,

#include <calculator/Lang/TokenList.hpp>
    };

    struct Token {
        TokenType type;
        std::optional<double> data;
    };

    std::vector<Token> Tokenise(std::string_view str);
}

#endif
