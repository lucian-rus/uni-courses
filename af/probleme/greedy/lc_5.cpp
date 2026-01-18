// greedy - DI String Match

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> diStringMatch(std::string s) {
    std::vector<int> v;

    int left  = 0;
    int right = s.length();

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            v.push_back(left++);
            continue;
        }

        if (s[i] == 'D') {
            v.push_back(right--);
        }
    }

    v.push_back(right--);

    return v;
}

int main() {
    std::string s = "DDI";

    std::vector<int> v = diStringMatch(s);
    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
