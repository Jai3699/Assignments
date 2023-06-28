// Question--1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = std::abs(sum - target);

            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closestSum;
}

int main() {
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int sum = threeSumClosest(nums, target);
    std::cout << sum << std::endl;  // Output: 2

    return 0;
}




//Question--2
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector<std::vector<int>> result = fourSum(nums, target);

    for (const auto& quadruplet : result) {
        for (int num : quadruplet) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}




//Question--3

#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        
        std::reverse(nums.begin(), nums.end());
        return;
    }

    
    int next = pivot + 1;
    for (int i = pivot + 1; i < n; i++) {
        if (nums[i] > nums[pivot] && nums[i] <= nums[next]) {
            next = i;
        }
    }

    
    std::swap(nums[pivot], nums[next]);


    std::reverse(nums.begin() + pivot + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    nextPermutation(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


//Question--4

#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = searchInsert(nums, target);

    std::cout << "Index: " << index << std::endl;

    return 0;
}


//Question--5

#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        } else {
            digits[i] = 0;
        }
    }


    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> result = plusOne(digits);

    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}


//Question--6

#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num;
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 1, 4};
    int single = singleNumber(nums);

    std::cout << "Single number: " << single << std::endl;  //output-->4

    return 0;
}



//Question--7


#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::string> result;
    long long start = lower;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > start) {
            result.push_back(getRange(start, nums[i] - 1));
        }
        start = static_cast<long long>(nums[i]) + 1;
    }

    if (start <= upper) {
        result.push_back(getRange(start, upper));
    }

    return result;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    std::vector<std::string> result = findMissingRanges(nums, lower, upper);

    for (const std::string& range : result) {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    return 0;
}



//Question--8

#include <iostream>
#include <vector>
#include <algorithm>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    bool result = canAttendMeetings(intervals);

    std::cout << std::boolalpha << result << std::endl;

    return 0;
}


