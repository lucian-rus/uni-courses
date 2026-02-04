#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int left  = 0;
    int right = left + 1;

    while (right < nums.size()) {
        if (right - left > k) {
            left++;
        }

        if (nums[left] == nums[right]) {
            return true;
        }
        else {
            right++;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {1,2,3,1,2,3};
    std::cout << containsNearbyDuplicate(nums, 2) << '\n';

    return 0;
}
