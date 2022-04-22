#include <iostream>
#include <Scalar.hpp>
#include <Addition.hpp>
#include <Multiplication.hpp>

int main(int argc, char** argv) {
  auto s1 = std::make_shared<calculator::Scalar>(7);
  auto s2 = std::make_shared<calculator::Scalar>(9);
  auto ad_sub = std::make_shared<calculator::Addition>(s1, s2, true);
  auto mul = calculator::Multiplication(s1, ad_sub);
  std::cout << mul << std::endl;
  std::cout << *(mul.evaluate()) << std::endl;
  return 0;
}
