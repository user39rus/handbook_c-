#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
  size_t n;
  cin >> n;
  map<int, set<string>> index;
  for (size_t i = 0; i < n; i++) {
    int page;
    string word;
    cin >> word >> page;
    index[page].insert(word);
  }

  for (auto [page, words] : index) {
    cout << page;
    for (auto j : words) {
      cout << ' ' << j;
    }
    cout << endl;
  }
}
