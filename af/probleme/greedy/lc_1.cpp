#include <iostream>
#include <unordered_map>

void debug_map(std::unordered_map<int, int> letmap) {
    for(auto item : letmap) {
        std::cout << item.first << ' ' << item.second << '\n';
    }
    std::cout << "elem count: " << letmap.size() << '\n';
}

int solve(std::string s) {
    if (s.length() == 1) {
        return 1;
    }

    std::unordered_map<int, int> letmap;
    for (int i = 0; i < s.length(); i++) {
        letmap[s[i]]++;
    }

    // if we only have one kind of letter, return its count
    if(letmap.size() == 1) {
        return letmap.begin()->second;
    }

    int suma = 0;
    for(auto item: letmap) {
        if(item.second % 2 == 0) {
            suma += item.second;
            continue;
        }
    
        if(item.second % 2 != 0) {
            suma += item.second - 1;
        }
    }

    return suma;
}

int main() {
    std::string s;
    std::cin >> s;

    std::cout << solve(s) << '\n';
    return 0;
}
