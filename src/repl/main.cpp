#include <iostream>
#include <calculator/Evaluation.hpp>

void prefix() {
    std::cout << "> ";
}

int main() {
    prefix();
    for (std::string line; std::getline(std::cin, line);) {
        try {
            std::cout << calculator::Evaluate(line) << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        prefix();
    }
}
