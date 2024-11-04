#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string word;
    unordered_set<char> common_letters;
    bool first_word = true;
    while (getline(cin, word)) {
        unordered_set<char> current_word_letters(word.begin(), word.end());
        if (first_word) {
            common_letters = current_word_letters;
            first_word = false;
        } else {
            unordered_set<char> temp;
            for (char c : current_word_letters) {
                if (common_letters.count(c)) {
                    temp.insert(c);
                }
            }
            common_letters = temp;
        }
    }
    vector<char> result(common_letters.begin(), common_letters.end());
    sort(result.begin(), result.end());
    for (char c : result) {
        cout << c;
    }
    cout << endl;
    return 0;
}
