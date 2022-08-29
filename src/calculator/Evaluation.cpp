#include <calculator/Evaluation.hpp>
#include <calculator/Lexer.hpp>
#include <calculator/Parser.hpp>

namespace calculator {
    double Evaluate(const std::string& input) {
        auto tokens = Tokenise(input);
        Parser parser{};
        auto ast = parser.Parse(tokens);
        return ast->Compute();
    }
}