#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

static bool compare(const std::tuple<int, int, int> &a,
                    const std::tuple<int, int, int> &b) {
  return (std::get<2>(a) < std::get<2>(b));
}

int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::tuple<int, int, int>> points(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> std::get<0>(points[i]);
    std::cin >> std::get<1>(points[i]);
    std::get<2>(points[i]) = std::get<0>(points[i]) * std::get<0>(points[i]) +
                             std::get<1>(points[i]) * std::get<1>(points[i]);
  }
  std::sort(points.begin(), points.end(), compare);
  for (std::tuple i : points)
    std::cout << std::get<0>(i) << " " << std::get<1>(i) << std::endl;
}