// greedy - apple redistribution
#include <algorithm>
#include <iostream>
#include <vector>

int minimumBoxes(std::vector<int> &apple, std::vector<int> &capacity) {
    std::sort(capacity.begin(), capacity.end(), [](int a, int b) { return a > b; });

    int apple_sum = 0;
    int num       = 0;
    int cap_sum   = capacity[num++];

    for (int i = 0; i < apple.size(); i++) {
        apple_sum += apple[i];
        while (apple_sum > cap_sum) {
            cap_sum += capacity[num];
            num++;
        }
    }

    return num;
}

int main() {
    std::vector<int> apples     = {5, 5, 5};
    std::vector<int> capacities = {2, 4, 2, 7};

    std::cout << minimumBoxes(apples, capacities) << '\n';
    return 0;
}
