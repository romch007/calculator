#include <calculator/Context.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2) throw std::runtime_error("no file provided");
  calculator::Context context;
  std::ifstream file(argv[1]);

  std::string line;
  while (std::getline(file, line)) {
    context.Execute(line);
  }

  return 0;
}
