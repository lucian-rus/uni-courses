#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>

std::vector<int> majorityElement(std::vector<int> &nums) {
    std::vector<int> res;

    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if(map[nums[i]] < 0) {
            continue;
        }
        
        map[nums[i]]++;
        if (map[nums[i]] > (int)(nums.size() / 3)) {
            res.push_back(nums[i]);
            map[nums[i]] = INT_MIN;
        }
    }

    return res;
}

int main() {
    std::vector<int> nums = {2, 2};

    std::vector<int> res = majorityElement(nums);
    for(auto &e : res) {
        std::cout << e << ' ';
    }

    std::cout << '\n';

    return 0;
}
