#include "skadi/vector_index.h"
#include <cassert>
#include <cstddef>
#include <iostream>

int main() {
  skadi::VectorIndex victor(3);
  victor.add({1, 2, 3});
  victor.add({5, 5, 5});
  victor.add({9, 9, 9});

  std::vector<float> query = {4.9, 5.1, 5.0};
  std::vector<float> result = victor.nearest(query);
  for (const auto num : result) {
    std::cout << num << "\n";
  }
  assert(result.size() == 3);
  assert(result[0] == 5);
  assert(result[1] == 5);
  assert(result[2] == 5);

  std::cout << "All tests passed.\n";
  return 0;
}
