#include <iostream>
#include <utility>
#include <vector>

std::pair<size_t, size_t>
MatrixArgMax(const std::vector<std::vector<int>> &matrix);

std::pair<size_t, size_t>
MatrixArgMax(const std::vector<std::vector<int>> &matrix) {
  int max = matrix[0][0];
  std::pair<size_t, size_t> coordinates;
  for (size_t i = 0; i < matrix.size(); ++i)
    for (size_t j = 0; j < matrix[i].size(); ++j) {
      if (matrix[i][j] > max) {
        coordinates.first = i;
        coordinates.second = j;
        max = matrix[i][j];
      }
    }
  return coordinates;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; j++)
      std::cin >> matrix[i][j];
  std::cout << MatrixArgMax(matrix).first << "\n";
  std::cout << MatrixArgMax(matrix).second << "\n";
}