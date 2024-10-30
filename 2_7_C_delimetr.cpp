#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string &str, char delimiter);

std::vector<std::string> Split(const std::string &str, char delimiter) {
  std::vector<std::string> vector_words = {};
  if (str.empty())
    vector_words.push_back("");
  else {
    size_t i = 0, j = 0;
    while (j < str.size()) {
      while (j < str.size() && str[j] != delimiter)
        ++j;
      vector_words.push_back(str.substr(i, j - i));
      ++j;
      i = j;
      // std::cout << j << ' ' << str.size() << std::endl;
      if (j == str.size() && str[j - 1] == delimiter)
        vector_words.push_back("");
    }
  }
  return vector_words;
}

int main() {
  std::string str;
  char delimiter;
  std::getline(std::cin, str);
  std::cin >> delimiter;
  for (std::string word : Split(str, delimiter))
    std::cout << word << "\n";
}