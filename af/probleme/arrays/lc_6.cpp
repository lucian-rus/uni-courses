#include <iostream>
#include <unordered_map>
#include <vector>

int mostFrequentEven(std::vector<int> &nums) {
    int num = -1;

    int cnt[5001] = {0};
    for (int i = 0; i < nums.size(); i++) {
        if (!(nums[i] & 1)) {
            cnt[nums[i/2]++];
        }
    }

    std::vector<int> v;
    int max = -1;
    for(int i = 0; i < 5001; i++) {
        
    }
    return num;
}

int main() {
    std::vector<int> nums = {3, 2, 3};

    std::cout << mostFrequentEven(nums) << '\n';

    return 0;
}
