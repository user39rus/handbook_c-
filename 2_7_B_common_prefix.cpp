#include <iostream>
#include <string>
#include <vector>

std::string CommonPrefix(const std::vector<std::string> &words);

std::string CommonPrefix(const std::vector<std::string> &words) {
  std::string prefix;
  if (words.empty())
    prefix = "";
  else
    prefix = words[0];
  for (size_t i = 1; i < words.size(); ++i) {
    size_t j;
    for (j = 0;
         j < words[i].size() && j < prefix.size() && words[i][j] == prefix[j];
         ++j)
      ;
    prefix = prefix.substr(0, j);
  }
  return prefix;
}

int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::string> words(n);
  std::cin.ignore();
  for (size_t i = 0; i < n; ++i) {
    std::cout << i << "-i\n";
    std::getline(std::cin, words[i]);
    std::cout << words[i] << "\n";
  }
  std::cout << CommonPrefix(words);
}