#include <iostream>

int main() {
    int a, sign = 1;
    double b =0;
    std::cin >>a;
    for (int i=1; i<=a; ++i) {
        b +=sign*1.0/i;
        sign = -sign; 
    }
    std::cout << b;
}