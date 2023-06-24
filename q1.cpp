#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

    
    return {};
}

int main() {
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.empty()) {
        std::cout << "No solution found." << std::endl;
    } else {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    }

    return 0;
}
