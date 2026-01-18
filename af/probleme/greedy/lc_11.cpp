#include <iostream>
#include <string>
#include <vector>

int balancedStringSplit(std::string s) {
    int r_count = 0;
    int l_count = 0;

    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L') {
            l_count++;
        }
        if (s[i] == 'R') {
            r_count++;
        }
        if ((r_count != 0 && l_count != 0) && r_count == l_count) {
            sum++;
            r_count = 0;
            l_count = 0;
        }
    }

    return sum;
}

int main() {

    std::cout << balancedStringSplit("RLRRLLRLRL") << '\n';
    std::cout << balancedStringSplit("RLRRRLLRLL") << '\n';
    std::cout << balancedStringSplit("LLLLRRRR") << '\n';
    return 0;
}
