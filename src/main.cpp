#include <iostream>
#include <vector>

#include "skadi/vector_math.h"

int main() {
  std::vector<float> a{1.0F, 2.0F, 3.0F};
  std::vector<float> b{4.0F, 5.0F, 6.0F};

  std::cout << skadi::dot_product(a, b) << "\n";
  std::cout << skadi::euclidean_distance(a, b) << "\n";

  return 0;
}
