#include <calculator/Context.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "no file provided" << std::endl;
    return 1;
  }
  calculator::Context context;
  std::ifstream file(argv[1]);

  if (file.bad()) {
    std::cout << "file not found" << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  context.Execute(buffer.str());

  return 0;
}
