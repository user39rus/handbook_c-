#include <deque>
#include <iostream>
#include <string>

using namespace std;
void MakeTrain();

void MakeTrain() {
  deque<int> train;
  string side;
  while (cin >> side) {
    size_t number_van;
    cin >> number_van;
    if (side == "+left")
      train.push_front(number_van);
    if (side == "+right")
      train.push_back(number_van);
    if (side == "-left") {
      auto begin = train.begin();
      auto end = train.end();
      if (number_van < train.size())
        end = begin + number_van;
      train.erase(begin, end);
    }
    if (side == "-right") {
      auto begin = train.begin();
      auto end = train.end();
      if (number_van < train.size())
        begin = end - number_van;
      train.erase(begin, end);
    }
  }
  bool print_delimeter = false;
  for (auto i : train) {
    if (print_delimeter)
      cout << " ";
    cout << i;
    print_delimeter = true;
  }
  cout << endl;
}

int main() { MakeTrain(); }