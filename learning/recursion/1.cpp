#include <iostream>

int recurse_sum(const int &n) {
    if (n == 0) {
        return 0;
    }

    return (n + recurse_sum(n - 1));
}

int factorial(const int &n) {
    if (n == 1) {
        return 1;
    }

    return (n * factorial(n - 1));
}

int main(void) {
    int n;
    std::cin >> n;

    std::cout << recurse_sum(n) << '\n';
    std::cout << factorial(n) << '\n';
    return 0;
}