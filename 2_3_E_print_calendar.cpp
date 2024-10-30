#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  for (int i = 0; i < (a - 1)*3-1; ++i)
    std::cout << " ";
  for (int i = 0; i < b; ++i) {
    if ((a + i) % 7 ==1)
    std::cout.width(2);
    else std::cout.width(3);
    std::cout << i + 1;
    if ((a + i) % 7 == 0)
      std::cout << "\n";
  }
  std::cout << "\n";
}