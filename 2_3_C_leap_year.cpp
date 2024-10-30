#include <iostream>

int main() {
  int year;
  bool leap = false;
  std::cin >> year;
  if (year % 400 == 0)
    leap = true;
  else if (year % 4 == 0 && year % 100 != 0)
    leap = true;
  if (leap)
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}