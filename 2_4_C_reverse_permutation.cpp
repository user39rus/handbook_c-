#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> permutation, reverse_permutation;
  std::cin >> n;
  for (int i = 0; i != n; ++i) {
    int temp;
    std::cin >> temp;
    permutation.push_back(temp);
  }
  int number = 1;
  reverse_permutation.resize(n);
  for (int elem : permutation) {
    reverse_permutation[elem-1] = number;
    ++number;
  }

  for (int elem : reverse_permutation)
    std::cout << elem << " ";
}