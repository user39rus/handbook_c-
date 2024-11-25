#include <iostream>
#include <queue>
#include <set>

using namespace std;
int main() {
  multiset<int> windows;
  queue<int> numbers;
  size_t n, k;
  cin >> n >> k;
  for (size_t i = 0; i < n; i++) {
    int x;
    cin >> x;
    windows.insert(x);
    numbers.push(x);
    if (windows.size() == k) {
      cout << *windows.begin() << endl;
      auto iter = windows.find(numbers.front());
      windows.erase(iter);
      numbers.pop();
    }
  }
}