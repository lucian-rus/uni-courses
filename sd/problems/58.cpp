#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    int count = 0;

    bool firstword = false;
    for (int i = s.length() - 1; i >= 0; i--) {
        while (s[i] == ' ' && firstword == false) {
            i--;
            continue;
        }

        if(s[i] == ' ') {
            break;
        }
        firstword = true;
        count++;
    }

    return count;
}

int main(void) {
    std::string s = "hello world ";
    std::cout << lengthOfLastWord(s);
    return 0;
}