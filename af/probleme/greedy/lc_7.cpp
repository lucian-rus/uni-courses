// greedy - lemonade change 100

#include <iostream>
#include <unordered_map>
#include <vector>

// 5 5 10 10 20
// 5 5 5 10 20
bool lemonadeChange(std::vector<int> &bills) {
    int sum     = 0;
    int cnt[21] = {0};

    for (int i = 0; i < bills.size(); i++) {
        std::cout << "bill: " << bills[i] << " 5: " << cnt[5] << " 10: " << cnt[10] << '\n';
        cnt[bills[i]]++;

        if (bills[i] == 10 && cnt[5] == 0) {
            return false;
        }
        else if (bills[i] == 10) {
            cnt[5]--;
        }

        if (bills[i] == 20 && cnt[5] == 0) {
            return false;
        }
        else if (bills[i] == 20) {
            if (cnt[10] != 0) {
                cnt[10]--;
                cnt[5]--;
            }
            else {
                cnt[5] -= 3;
            }

            if (cnt[5] < 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<int> v = {5, 5, 10, 10, 20};
    std::cout << lemonadeChange(v) << '\n';

    return 0;
}
