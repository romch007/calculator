#include <iostream>
#include <Scalar.hpp>
#include <Addition.hpp>
#include <Multiplication.hpp>

int main(int argc, char** argv) {
  auto s1 = std::make_shared<calculator::Scalar>(2);
  auto s2 = std::make_shared<calculator::Scalar>(5);
  auto s3 = std::make_shared<calculator::Scalar>(2);
  auto ad_sub = std::make_shared<calculator::Fraction>(s2, s3);
  auto mul = calculator::Fraction(s1, ad_sub);
  std::cout << mul << std::endl;
  std::cout << *(mul.evaluate()) << std::endl;
  return 0;
}
