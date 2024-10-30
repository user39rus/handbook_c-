#include <iostream>

int main() {
  int x, y, x1, y1;
  bool otvet = false;
  std::cin >> x >> y >> x1 >> y1;
  if (x == x1 || y == y1)
    otvet = true;
  if (abs(x - x1) == abs(y - y1))
    otvet = true;
  if (otvet)
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}