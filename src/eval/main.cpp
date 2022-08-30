#include <calculator/Context.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2) throw std::runtime_error("no file provided");
  calculator::Context context;
  std::ifstream file(argv[1]);

  std::string line;
  double result;
  while (std::getline(file, line)) {
    result = context.Evaluate(line);
  }
  std::cout << result << std::endl;

  return 0;
}
