template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2,
                      InIter2 last2, OutIter out) {
  while (first1 != last1 && first2 != last2) {
    if (*first1 < *first2) {
      *out = *first1;
      ++out;
      first1++;
    } else if (*first1 > *first2) {
      first2++;
    } else {
      ++first1;
      ++first2;
    }
  }
  while (first1 != last1) {
    *out = *first1;
    ++out;
    ++first1;
  }
  return out;
}

#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

int main() {
  vector<int> in1 = {1, 3, 5, 5, 7};
  list<int> in2 = {1, 1, 2, 3};
  deque<int> out;

  SetDifference(in1.begin(), in1.end(), in2.begin(), in2.end(),
                back_inserter(out));
  for (auto i : out) {
    cout << i;
  }
}
