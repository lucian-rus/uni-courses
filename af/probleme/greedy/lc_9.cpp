#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> maxKDistinct(std::vector<int> &nums, int k) {
    std::vector<int> res;
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    for (int i = 0; i < nums.size() && k > 0; i++) {
        while (nums[i] == nums[i + 1]) {
            i++;
            continue;
        }

        res.push_back(nums[i]);
        k--;
    }

    return res;
}

int main() {
    std::vector<int> v = {1,1,1,2,2,2};
    
    std::vector<int> a = maxKDistinct(v, 6);
    for(auto i: a) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
