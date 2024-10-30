#include <iostream>
#include <string>
#include <vector>
// #include <algoritm>

using namespace std;
int main() {
  vector<string> words;
  string word;
  while (getline(cin, word))
    words.push_back(word);
  sort(rbegin(words), rend(words));
  for (string n : words)
    cout << n << "\n";
}