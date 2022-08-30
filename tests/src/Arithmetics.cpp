#include <calculator/Context.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using calculator::Evaluate;
using Catch::Approx;

TEST_CASE("Arithmetics") {
  // CHECK(Evaluate("-> 3+3") == Approx(6));
  // CHECK(Evaluate("-> 5+3") == Approx(8));
  // CHECK(Evaluate("-> 3*3*3") == Approx(27));
  // CHECK(Evaluate("-> 1/5") == Approx(0.2));
  // CHECK(Evaluate("-> 2-2") == Approx(0));
  // CHECK(Evaluate("-> (3+3)*2") == Approx(12));
  // CHECK(Evaluate("-> 2^(5+1)") == Approx(64));
}