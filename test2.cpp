#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidParentheses(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string s;
    cin >> s;

    string doubled = s + s;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        string substring = doubled.substr(i, n);
        if (isValidParentheses(substring)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}