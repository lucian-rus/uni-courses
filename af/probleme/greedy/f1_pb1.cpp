#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> vec;
    int bancnote[8] = {1, 5, 10, 20, 50, 100, 200, 500};
    int cnt_banc = 7;
    
    while(n != 0) {
        while((n - bancnote[cnt_banc]) >= 0) {
            vec.push_back(bancnote[cnt_banc]);
            n = n - bancnote[cnt_banc];
            std::cout << n << '\n';
        } 

        cnt_banc--;
    }

    for(auto val: vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
