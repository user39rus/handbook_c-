#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  priority_queue<int> data;
  string input;
  while (cin >> input) {
    if (input == "CLEAR")
      data = {};
    if (input == "ADD") {
      int x;
      cin >> x;
      data.push(x);
    }
    if (input == "EXTRACT") {
      if (data.empty())
        cout << "CANNOT" << endl;
      else {
        cout << data.top() << endl;
        data.pop();
      }
    }
  }
}