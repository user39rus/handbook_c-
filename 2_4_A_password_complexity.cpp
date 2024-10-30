#include <iostream>
#include <string>

int main() {
  std::string password;
  bool password_complexity = true;
  std::getline(std::cin, password);
  if (password.size() < 8 || password.size() > 14)
    password_complexity = false;
  if (password_complexity) {
    bool lowercase = false;
    bool uppercase = false;
    bool numbers = false;
    bool other = false;
    for (size_t i = 0; i != password.size() && password_complexity; ++i)
      if (password[i] < 33 || password[i] > 126)
        password_complexity = false;
      else if (password[i] >= 48 && password[i] <= 57)
        numbers = true;
      else if (password[i] >= 65 && password[i] <= 90)
        uppercase = true;
      else if (password[i] >= 97 && password[i] <= 122)
        lowercase = true;
      else
        other = true;
    if ((lowercase + uppercase + numbers + other) < 3)
      password_complexity = false;
  }
  if (password_complexity)
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}