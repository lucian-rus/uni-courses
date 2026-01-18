#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    int cnt = 0;
    int i   = 0;

    if (n == 0) {
        return true;
    }
 
    if(flowerbed.size() == 1) {
        return !(flowerbed[0] == 1);
    }

    if (flowerbed.size() > 1 && flowerbed[0] == 0 && flowerbed[1] == 0) {
        i            = 1;
        flowerbed[0] = 1;
        n--;
    }

    if (n == 0) {
        return true;
    }

    if (flowerbed.size() > 1 && flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0) {
        flowerbed[flowerbed.size() - 1] = 1;
        n--;
    }

    for (i; i < flowerbed.size(); i++) {
        if (n == 0) {
            break;
        }

        if (cnt == 3) {
            i -= 2;
            flowerbed[i] = 1;
            n--;
            cnt = 0;
            continue;
        }

        if (flowerbed[i] == 1) {
            cnt = 0;
            continue;
        }

        cnt++;
    }

    return (n == 0);
}

int main() {
    std::vector<int> v = {0,0,1,0,0};

    std::cout << canPlaceFlowers(v, 1) << '\n';
    for(auto item: v) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
    return 0;
}
