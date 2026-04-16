#include <iostream>
#include <vector>

// O(n) time
// O(1) space
int main() {
    std::vector<int> nums = {0, 1, 1, 1, 2, 2, 3};

    if (nums.empty()) return 0;

    int left = 0;
    for (int right = 1; right < nums.size(); right++) {
        if (nums[left] != nums[right]) {
            left++;
            nums[left] = nums[right];
        }
    }

    for (int k = 0; k < left + 1; k++) {
        std::cout << nums[k] << " ";
    }

    return 0;
}