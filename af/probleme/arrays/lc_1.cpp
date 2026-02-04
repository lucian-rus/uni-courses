#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strs) {
    std::string aux = strs[0];
    
    for (auto s: strs) { 
        if(s[0] != aux[0]) {
            return "";
        }

        std::cout << aux << '\n';
        int cnt = 0;
        for(int idx = 0; idx < aux.length() && idx < s.length(); idx++) {            
            if(s[idx] != aux[idx]) {
                break;
            }
            cnt++;
        }
        aux = aux.substr(0, cnt);
    }

    return aux;
}

int main() {
    std::vector<std::string> vec = {"dog","racecar","car"};

    std::cout << longestCommonPrefix(vec) << '\n';
}
