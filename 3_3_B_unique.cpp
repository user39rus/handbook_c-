

template <typename Iter> Iter Unique(Iter first, Iter last) {
  if (first == last)
    return last;
  Iter result = first;
  ++first;
  while (first != last) {
    if (*result != *first) {
      ++result;
      *result = *first;
    }
    ++first;
  }
  return ++result;
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v = {5, 5, 3, 2, 2, 5, 9, 1};
  auto iter = Unique(v.begin(), v.end());

  v.erase(iter, v.end());
  for (auto i : v) {
    cout << i;
  }
}