#include <iostream>
#include <list>

using namespace std;

int main() {
    size_t n;
    size_t max = 0;
    size_t temp;
    list<int> massiv;
    
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > max)
            max = temp;
        massiv.push_back(temp);
    }

    for (size_t i = 0; i < max; ++i) {
        for (auto j = massiv.begin(); j != massiv.end(); ) {
            cout << *j << ' ';
            if (*j == 1) {
                j = massiv.erase(j);
            } else {
                --(*j);
                ++j;
            }
    }
}
}
