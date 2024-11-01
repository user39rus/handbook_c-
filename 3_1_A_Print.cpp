#include <iostream>
#include <string>
#include <vector>

template <typename T> void Print(const T &data, const std::string &delimetr) {
  bool print_delimeter = false;
  for (const auto& i : data) {
    if (print_delimeter)
      std::cout << delimetr;
    print_delimeter = true;
    std::cout << i;
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> data = {1, 2, 3, 4};
  Print(data, ", "); // 1, 2, 3, 4
}