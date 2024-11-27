#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int main() {
  size_t k;
  string word;
  map<string, int> data;
  cin >> k;
  while (cin >> word) {
    ++data[word];
  }
  vector<pair<string, int>> words_sort(data.begin(), data.end());
  partial_sort(words_sort.begin(),
               words_sort.begin() + min(k, words_sort.size()), words_sort.end(),
               [](const auto &p1, const auto &p2) {
                 return tie(p2.second, p1.first) < tie(p1.second, p2.first);
               });
  for (size_t i = 0; i < min(k, words_sort.size()); ++i) {
    cout << words_sort[i].first << '\t' << words_sort[i].second << endl;
  }
}