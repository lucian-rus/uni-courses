// greedy - Maximum Odd Binary Number

#include <iostream>
#include <vector>

// 10110100
std::string maximumOddBinaryNumber(std::string s) {
    int cnt = 0;
    char a[110] = {0};

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            cnt++;
        }

        a[i] = '0';
    }

    int i = 0;
    while(cnt > 1) {
        a[i++] = '1';
        cnt--;
    }

    a[s.length() - 1] = '1';

    return std::string(a);
}

int main() {
    std::string num;
    std::cin >> num;
    std::cout << maximumOddBinaryNumber(num) << '\n';

    return 0;
}
