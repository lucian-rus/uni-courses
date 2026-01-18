// 

#include <algorithm>
#include <iostream>
#include <vector>

int arrayPairSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    int suma = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        suma += nums[i + 1];
    }
    return suma;
}

int main() {
    std::vector<int> nums = {6, 2, 6, 5, 1, 2};
    std::cout << arrayPairSum(nums) << '\n';
    return 0;
}
