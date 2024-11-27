#include <iostream>
#include <string>
#include <string_view>

using namespace std;

bool NextToken(string_view &sv, char delimetr, string_view &token) {
  bool result = true;
  size_t pos = sv.find(delimetr);
  if (pos != string_view::npos) {
    token = sv.substr(0, pos);
    sv.remove_prefix(pos + 1);
  } else if (!sv.empty()) {
    token = sv;
    sv.remove_prefix(sv.size());
  } else
    result = false;
  return result;
}

int main() {
  std::string_view sv = "Hello world and good bye";
  const char delimiter = ' ';
  std::string_view token;
  while (NextToken(sv, delimiter, token)) {
    std::cout << token << "\n";
  }
}