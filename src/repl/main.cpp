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
      c.Execute(line);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    prefix();
  }
}
