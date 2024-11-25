#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t n, k;
  cin >> n >> k;
  vector<int> vect1(n);
  vector<int> vect2(k);
  for (size_t i = 0; i < n; ++i) {
    cin >> vect1[i];
  }
  for (size_t i = 0; i < k; ++i) {
    cin >> vect2[i];
  }
  for (auto i : vect2) {
    auto low = lower_bound(vect1.begin(), vect1.end(), i);
    if (low == vect1.end())
      low--;
    if (low != vect1.begin()) {
      if (*low - i < i - *(low - 1))
        cout << *low << endl;
      else
        cout << *(low - 1) << endl;
    } else
      cout << *low << endl;
  }
}