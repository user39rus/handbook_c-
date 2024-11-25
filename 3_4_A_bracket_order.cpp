#include <iostream>
#include <stack>

using namespace std;

int main() {
  bool result = true;
  stack<char> sequence;
  char bracket;
  while (cin >> bracket) {
    if (bracket == '(' || bracket == '{' || bracket == '[') {
      sequence.push(bracket);
    } else {
      if (sequence.empty()) {
        result = false;
        break;
      } else {
        if (sequence.top() == '{' && bracket == '}')
          sequence.pop();
        else if (sequence.top() == '[' && bracket == ']')
          sequence.pop();
        else if (sequence.top() == '(' && bracket == ')')
          sequence.pop();
      }
    }
  }
  if (!sequence.empty())
    result = false;
  cout << (result ? "YES" : "NO");
}