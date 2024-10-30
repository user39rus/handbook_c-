#include <iostream>
#include <string>

using namespace std;

int main() {
  // char s = ' ';
  string cylinder;

  getline(cin, cylinder);
  string v;
  for (char c : cylinder)
    if (c != ' ')
      v += c;
  cylinder = v;
  bool result = true;
  for (size_t i = 0; i < (cylinder.size() / 2); ++i) {
    if (cylinder[i] != cylinder[cylinder.size() - i - 1])
      result = false;
  }
  if (result)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
}