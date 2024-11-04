#include <iostream>
#include <unordered_set>

using namespace std;
int main() {
  int n;
  unordered_set<int> numbers;
  while (cin >> n) {
    auto [iter, has_been_inserted] = numbers.insert(n);
    if (!has_been_inserted)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}