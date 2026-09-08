#include <iostream>
#include <stdexcept>
#include <vector>

#include "skadi/vector_math.h"

int main() {
  std::vector<float> a{1.0F, 2.0F, 3.0F};
  std::vector<float> b{4.0F, 5.0F};

  try {
    std::cout << skadi::dot_product(a, b) << "\n";
    std::cout << skadi::euclidean_distance(a, b) << "\n";
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
