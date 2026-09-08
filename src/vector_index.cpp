#include "skadi/vector_index.h"
#include "skadi/vector_math.h"
#include <cstddef>
#include <limits>
#include <stdexcept>

namespace skadi {
VectorIndex::VectorIndex(std::size_t dim) : dimension_(dim) {}

std::size_t VectorIndex::dimension() const { return dimension_; }

void VectorIndex::add(const std::vector<float> &incoming) {
  if (incoming.size() != dimension()) {
    throw std::invalid_argument("Invalid dimension.\n");
  }

  vectors_.push_back(incoming);
}

std::size_t VectorIndex::size() const { return vectors_.size(); }

std::vector<float> VectorIndex::nearest(const std::vector<float> &query) const {
  if (query.size() != dimension()) {
    throw std::invalid_argument("Invalid dimensions.");
  }

  if (vectors_.empty()) {
    throw std::invalid_argument("Cannot search an empty index.");
  }

  float big_distance = std::numeric_limits<float>::max();
  std::vector<float> best_vector;

  for (const auto &vector : vectors_) {
    float distance = skadi::euclidean_distance(query, vector);

    if (distance < big_distance) {
      big_distance = distance;
      best_vector = vector;
    }
  }
  return best_vector;
}
} // namespace skadi
