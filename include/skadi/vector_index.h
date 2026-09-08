#pragma once

#include <vector>

namespace skadi {
class VectorIndex {
public:
  VectorIndex(std::size_t dim); // Constructor
  std::size_t dimension() const;
  void add(const std::vector<float> &incoming);
  std::size_t size() const;
  std::vector<float> nearest(const std::vector<float> &query) const;

private:
  std::size_t dimension_;
  std::vector<std::vector<float>> vectors_;
};
} // namespace skadi
