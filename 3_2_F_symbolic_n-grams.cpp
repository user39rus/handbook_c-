#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  size_t word_count;
  size_t number_count;
  map<string, size_t> freqs;
  cin >> word_count >> number_count;
  for (size_t i = 0; i < word_count; i++) {
    string word;
    cin >> word;
    size_t start_grams = 0;
    size_t end_grams = number_count;
    while (end_grams <= word.length()) {
      string n_grams = word.substr(start_grams, number_count);
      ++freqs[n_grams];
      ++start_grams;
      ++end_grams;
    }
  }
  vector<pair<string, int>> sortedByFreq(freqs.begin(), freqs.end());
  sort(sortedByFreq.begin(), sortedByFreq.end(),
       [](const auto &p1, const auto &p2) {
         return tie(p2.second, p1.first) < tie(p1.second, p2.first);
       });
  for (const auto &[word, freq] : sortedByFreq) {
    std::cout << word << " - " << freq << "\n";
  }
}