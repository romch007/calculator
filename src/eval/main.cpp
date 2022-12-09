#include <calculator/Context.hpp>
#include <cxxopts.hpp>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  cxxopts::Options options("eval", "eval for the calculator");

  options.add_options()("d,debug", "Print debug informations")(
      "f,file", "The file to execute", cxxopts::value<std::string>())(
      "h,help", "Print help");

  options.parse_positional({"file"});

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  if (!result.count("file")) {
    std::cout << "no file provided" << std::endl;
    return 1;
  }

  auto filename = result["file"].as<std::string>();

  calculator::Context context(std::cout, result.count("debug"));
  std::ifstream file(filename);

  if (file.bad()) {
    std::cout << "file not found" << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  context.Execute(buffer.str());

  return 0;
}
