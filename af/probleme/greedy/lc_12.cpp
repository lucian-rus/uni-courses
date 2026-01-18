#include <iostream>
#include <string>
#include <vector>

bool validPalindrome(std::string s) {
    int diff = 0;
    for(int i = 0; i < s.length() / 2; i++) {
        if(s[i] != s[s.length() - 1 - i]) {
            diff++;
            std::cout << s[i] << ' ' << s[s.length() - 1 - i] << " diff: " << diff << '\n';
        }
    }
    if(s.length() <= 3 && diff != 0) {
        return false;
    } 

    return (diff < 2);
}

int main() {
    std::cout << validPalindrome("abc") << '\n';

    return 0;
}
