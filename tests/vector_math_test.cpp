#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "skadi/vector_math.h"

int main() {
  std::vector<float> a{1.0F, 2.0F, 3.0F};
  std::vector<float> b{4.0F, 5.0F, 6.0F};
  std::vector<float> bad{4.0F, 5.0F};

  // Test 1: Dot product
  float result = skadi::dot_product(a, b);
  assert(result == 32.0F);

  // Test 2: Euclidean distance
  float result2 = skadi::euclidean_distance(a, b);
  assert(std::abs(result2 - 5.19615F) < 0.00001F);

  // Test 3: Mismatched dimensions should throw
  bool exception_thrown = false;

  try {
    skadi::dot_product(a, bad);
  } catch (const std::invalid_argument &e) {
    exception_thrown = true;
  }

  assert(exception_thrown);

  std::cout << "All tests passed.\n";

  return 0;
}
