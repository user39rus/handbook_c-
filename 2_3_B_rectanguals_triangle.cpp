#include <iostream>

int main() {
  int a, b, c;
  bool rectangular = false, triangle_exist = false;
  std::cin >> a >> b >> c;
  if (a + b > c && b + c > a && a + c > b)
    triangle_exist = true;
  a *= a;
  b *= b;
  c *= c;
  if (a + b == c || a + c == b || b + c == a)
    rectangular = true;
  if (triangle_exist)
    if (rectangular)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  else
    std::cout << "UNDEFINED\n";
}