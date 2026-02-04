#include <iostream>
#include <vector>

int searchInsert(std::vector<int> &nums, int target) {
    int left  = 0;
    int right = nums.size() - 1;
    while (left != right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    std::vector<int> v = {1, 3, 4, 5, 6, 8, 9, 12, 14};
    std::cout << searchInsert(v, 2) << '\n';
    return 0;
}
