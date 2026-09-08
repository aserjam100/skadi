#include "skadi/vector_math.h"
#include <cmath>
#include <stdexcept>

namespace skadi {
float dot_product(const std::vector<float> &a, const std::vector<float> &b) {
  if (a.size() != b.size()) {
    throw std::invalid_argument("Vectors must have the same dimensions");
  }
  float result = 0.0F;

  for (std::size_t i = 0; i < a.size(); ++i) {
    result += a[i] * b[i];
  }
  return result;
}

float euclidean_distance(const std::vector<float> &a,
                         const std::vector<float> &b) {
  if (a.size() != b.size()) {
    throw std::invalid_argument("Vectors must have the same dimensions");
  }
  float result = 0.0F;
  for (std::size_t i = 0; i < a.size(); ++i) {
    result += (a[i] - b[i]) * (a[i] - b[i]);
  }
  return std::sqrt(result);
}

} // namespace skadi
