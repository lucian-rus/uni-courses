#include <iostream>
#include <unordered_map>
#include <vector>

int majorityElement(std::vector<int> &nums) {
    int num = -1;

    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;

        if (map[nums[i]] > nums.size() / 2) {
            return nums[i];
        }
    }

    return num;
}

int main() {
    std::vector<int> nums = {3, 2, 3};

    std::cout << majorityElement(nums) << '\n';

    return 0;
}
