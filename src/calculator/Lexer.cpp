#include <fast_float/fast_float.h>

#include <calculator/Lexer.hpp>
#include <cctype>
#include <charconv>
#include <optional>
#include <stdexcept>
#include <string_view>

namespace calculator {
  std::vector<Token> Tokenise(std::string_view str) {
    std::size_t currentPos = 0;

    auto Peek = [&](std::size_t advance = 1) -> char {
      if (currentPos + advance < str.size() &&
          str[currentPos + advance] != '\0')
        return str[currentPos + advance];
      else
        return '\0';
    };

    std::size_t lineStartPos = 0;
    std::vector<Token> tokens;

    for (;;) {
      char c = Peek(0);

      Token token;
      if (c == '\0') {
        token.type = TokenType::EndOfStream;
        tokens.push_back(token);
        break;
      }

      std::optional<TokenType> tokenType;
      switch (c) {
        case ' ':
        case '\t':
        case '\r':
          break;  // Ignore blanks
        case '\n':
          tokenType = TokenType::Newline;
          break;
        case '+':
          tokenType = TokenType::Add;
          break;
        case '-': {
          tokenType = TokenType::Substract;
          break;
        }
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
        case '=':
          tokenType = TokenType::Equal;
          break;
        case '#': {
          char next;
          do {
            currentPos++;
            next = Peek();
          } while (next != -1 && next != '\n');
          break;
        }
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
          bool floatingPoint = false;

          std::size_t start = currentPos;
          char next = Peek();

          for (;;) {
            next = Peek();

            if (!isdigit(next)) {
              if (next != '.') break;

              if (floatingPoint) break;

              floatingPoint = true;
            }

            currentPos++;
          }

          const char* first = &str[start];
          const char* last = first + (currentPos - start + 1);

          tokenType = TokenType::Number;
          double value;
          fast_float::from_chars_result r =
              fast_float::from_chars(first, last, value);
          if (r.ptr == last && r.ec == std::errc{})
            token.data = value;
          else if (r.ec == std::errc::result_out_of_range)
            throw std::runtime_error("number out of range");
          else
            throw std::runtime_error("bad number");
          break;
        }
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y': {
          std::size_t fnNameStart = currentPos;

          while (isalpha(Peek())) currentPos++;

          std::string_view name =
              str.substr(fnNameStart, currentPos - fnNameStart + 1);
          if (name == "const") {
            tokenType = TokenType::Const;
          } else if (name == "let") {
            tokenType = TokenType::Let;
          } else {
            tokenType = TokenType::Identifier;
            token.data = name;
          }
          break;
        }
        default:
          break;
      }

      if (tokenType) {
        token.type = *tokenType;
        tokens.push_back(token);
      }

      currentPos++;
    }

    return tokens;
  }

  const char* ToString(TokenType tokenType) {
    switch (tokenType) {
#define CALCULATOR_TOKEN(X) \
  case TokenType::X:        \
    return #X;

#include <calculator/Lang/TokenList.hpp>
    }

    return "<Error>";
  }
}  // namespace calculator
