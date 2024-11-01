#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  size_t number_of_students;
  cin >> number_of_students;
  deque<string> surnames;
  for (size_t i = 0; i < number_of_students; ++i) {
    string surname, position;
    cin >> surname >> position;
    if (position == "top")
      surnames.push_front(surname);
    if (position == "bottom")
      surnames.push_back(surname);
  }
  size_t number_of_surnames;
  cin >> number_of_surnames;
  for (size_t i = 0; i < number_of_surnames; ++i) {
    size_t surname_number;
    cin >> surname_number;
    cout << surnames[surname_number-1] << endl;
  }
}