#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string input = "1";
  vector<string> text;
  while (true) {
    getline(cin, input);
    if (input == "")
      break;
    text.push_back(input);
  }
  string temp;
  auto ite2 = text.begin();
  while (getline(cin, input)) {
    if (input == "Down" && ite2 != text.end()) {
      ++ite2;
    }
    if (input == "Up" && ite2 != text.begin()) {
      --ite2;
    }
    if (input == "Ctrl+X" && ite2 != text.end()) {
      temp = *ite2;
      ite2 = text.erase(ite2);
    }
    if (input == "Ctrl+V" && !temp.empty()) {
      ite2 = text.insert(ite2, temp);
      ++ite2;
    }
  }
  for (const auto &i : text) {
    cout << i << endl;
  }
}
