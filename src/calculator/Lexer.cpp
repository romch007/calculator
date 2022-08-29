#include <calculator/Lexer.hpp>
#include <string_view>
#include <cctype>
#include <charconv>
#include <stdexcept>
#include <fast_float/fast_float.h>

namespace calculator {
    std::vector<Token> Tokenise(std::string_view str) {
        std::size_t currentPos = 0;

        auto Peek = [&](std::size_t advance = 1) -> char {
            if (currentPos + advance < str.size() && str[currentPos + advance] != '\0')
                return str[currentPos + advance];
            else
                return '\0';
        };

        std::size_t lineStartPos = 0;
        std::vector<Token> tokens;

        for (;;) {
            char c = Peek(0);

            Token token;
            if (c == '\0')
                break;

            std::optional<TokenType> tokenType;
            switch (c) {
                case ' ':
                case '\t':
                case '\r':
                    break; // Ignore blanks
                case '+':
                    tokenType = TokenType::Add;
                    break;
                case '-':
                    tokenType = TokenType::Substract;
                    break;
                case '*':
                    tokenType = TokenType::Multiply;
                    break;
                case '/':
                    tokenType = TokenType::Divide;
                    break;
                case '^':
                    tokenType = TokenType::Exponent;
                    break;
                case '(':
                    tokenType = TokenType::OpenParenthesis;
                    break;
                case ')':
                    tokenType = TokenType::CloseParenthesis;
                    break;
                case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
                {
                    bool floatingPoint = false;

                    std::size_t start = currentPos;
                    char next = Peek();

                    for (;;) {
                        next = Peek();

                        if (!isdigit(next))  {
                            if (next != '.')
                                break;

                            if (floatingPoint)
                                break;

                            floatingPoint = true;
                        }

                        currentPos++;
                    }

                    const char* first = &str[start];
                    const char* last = first + (currentPos - start + 1);

                    tokenType = TokenType::Number;
                    double value;
                    fast_float::from_chars_result r = fast_float::from_chars(first, last, value);
                    if (r.ptr == last && r.ec == std::errc{})
                        token.data = value;
                    else if (r.ec == std::errc::result_out_of_range)
                        throw std::runtime_error("number out of range");
                    else
                        throw std::runtime_error("bad number");

                }
                default: break;
            }

            if (tokenType) {
                token.type = *tokenType;
                tokens.push_back(token);
            }

            currentPos++;
        }

        Token eol;
        eol.type = TokenType::EOL;

        tokens.push_back(eol);
        return tokens;
    }
}
