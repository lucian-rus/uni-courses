#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

int singleNumber(std::vector<int> &nums) {
    int sum = 0;
    // use map
    // sum all elements -> add all elements
    // if present in map - decrease
    // return sum

    bool present[30000] = {false};
    for (auto &num : nums) {
        if (present[num + 10000] == true) {
            sum -= num;
            continue;
        }
        present[num + 10000] = true;
        sum += num;
    }

    return sum;
}

int main() {
    std::vector<int> nums = {2, 2, 1};

    std::cout << singleNumber(nums) << '\n';

    return 0;
}
