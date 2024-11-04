#include <iostream>
#include <set>
#include <string>

using namespace std;
int main() {
  set<string> paths;
  string input;
  while (getline(cin, input)) {
    int begin = 0;
    while (input.find('/', begin) != string::npos) {
      int end = input.find('/', begin);
      paths.insert(input.substr(0, end + 1));
      begin = end + 1;
    }
  }
  for (auto i : paths)
    cout << i << endl;
}