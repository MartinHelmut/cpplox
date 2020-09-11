#include "doctest/doctest.h"

int Factorial(int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("testing the factorial function") {
  CHECK(Factorial(1) == 1);
  CHECK(Factorial(2) == 2);
  CHECK(Factorial(3) == 6);
  CHECK(Factorial(10) == 3628800);
}
