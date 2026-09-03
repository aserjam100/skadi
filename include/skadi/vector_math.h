#pragma once

#include <vector>

namespace skadi {
float dot_product(const std::vector<float> &a, const std::vector<float> &b);
float euclidean_distance(const std::vector<float> &a,
                         const std::vector<float> &b);
} // namespace skadi
