#include <iostream>
#include <vector>

std::vector<std::vector<int>>
Transpose(const std::vector<std::vector<int>> &matrix);

std::vector<std::vector<int>>
Transpose(const std::vector<std::vector<int>> &matrix) {
  std::vector<std::vector<int>> transpose_matrix(
      matrix[0].size(), std::vector<int>(matrix.size()));
  for (size_t i = 0; i < matrix.size(); ++i)
    for (size_t j = 0; j < matrix[0].size(); ++j)
      transpose_matrix[j][i] = matrix[i][j];
  return transpose_matrix;
}

void print_matrix(const std::vector<std::vector<int>> &matrix) {
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      std::cout.width(2);
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::vector<std::vector<int>> matrix{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  print_matrix(matrix);
  print_matrix(Transpose(matrix));
}
