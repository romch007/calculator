#include <calculator/Context.hpp>
#include <iostream>

void prefix() {
  std::cout << "> ";
}

int main() {
  calculator::Context c;
  prefix();
  for (std::string line; std::getline(std::cin, line);) {
    try {
      std::cout << c.Evaluate(line) << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    prefix();
  }
}
