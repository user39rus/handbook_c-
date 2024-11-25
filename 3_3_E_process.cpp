#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter> void PrintResults(Iter begin, Iter end) {
  for (auto i = begin; i != end; ++i)
    std::cout << *i << std::endl;
}

template <typename T> void Process(const std::vector<T> &data) {
  std::vector<T> filtered;

  std::copy_if(data.begin(), data.end(), std::back_inserter(filtered),
               [](const T &x) { return x > 0; });

  PrintResults(filtered.begin(), filtered.end());
}

using namespace std;

int main() {
  vector<int> data = {1, -3, 5, 7, -7, 0};
  Process(data);
}