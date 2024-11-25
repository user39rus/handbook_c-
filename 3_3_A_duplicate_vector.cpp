#include<iostream>
#include <vector>

using namespace std;


template <typename T>
void Duplicate(std::vector<T>& v) {
    vector<T> temp;
copy(v.begin(), v.end(), back_inserter(temp));
copy(temp.begin(), temp.end(), back_inserter(v));

}

int main() {
vector<int> data({1,3,5});
Duplicate(data);
for (auto i:data) {
    cout<<i;
}



}