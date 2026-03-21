#include <iostream>

int main() {
    int a = 3;
    int *p = &a;
    int *q = p;

    *q = 4;
    std::cout << a << ' ' << p << ' ' << q << ' ' << *q << ' ' << *p << '\n';

    return 0;
}