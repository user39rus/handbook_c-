#include <iostream>

int main() {
  int year, month;
  bool leap = false;
  std::cin >> month >> year;
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12)
    std::cout << "31\n";
  else if (month == 2) {
    if (year % 400 == 0)
      leap = true;
    else if (year % 4 == 0 && year % 100 != 0)
      leap = true;
    if (leap)
      std::cout << "29\n";
    else
      std::cout << "28\n";
  } else
    std::cout << "30\n";
}