//Question--1

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(int nums[], int length) {
    std::sort(nums, nums + length); 
    int n = length;
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += nums[i];
    }
    return sum;
}

int main() {
    int nums[] = {1, 4, 3, 2};
    int length = sizeof(nums) / sizeof(nums[0]);
    int max_sum = arrayPairSum(nums, length);
    std::cout << max_sum << std::endl;  

    return 0;
}



//Question--2

#include <iostream>
#include <unordered_set>

int maxCandies(int candyType[], int length) {
    std::unordered_set<int> uniqueCandies;
    for (int i = 0; i < length; i++) {
        uniqueCandies.insert(candyType[i]);
    }
    
    int maxEatLimit = length / 2;
    int uniqueCandyCount = uniqueCandies.size();
    
    return std::min(uniqueCandyCount, maxEatLimit);
}

int main() {
    int candyType[] = {1, 1, 2, 2, 3, 3};
    int length = sizeof(candyType) / sizeof(candyType[0]);
    int maxDifferentTypes = maxCandies(candyType, length);
    std::cout << maxDifferentTypes << std::endl;  

    return 0;
}



//Question--3

#include <iostream>
#include <unordered_map>
#include <vector>

int findLHS(std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;
    

    for (int num : nums) {
        countMap[num]++;
    }
    
    int maxLength = 0;
    

    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        int num = it->first;
        int count = it->second;
        
        if (countMap.count(num + 1) > 0) {
            int complementCount = countMap[num + 1];
            
    
            int subsequenceLength = count + complementCount;
            

            maxLength = std::max(maxLength, subsequenceLength);
        }
    }
    
    return maxLength;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int longestSubsequenceLength = findLHS(nums);
    std::cout << longestSubsequenceLength << std::endl; 

    return 0;
}



//Question--4

#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    int count = n;
    int length = flowerbed.size();

    for (int i = 0; i < length && count > 0; i++) {
        if (flowerbed[i] == 0 &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i == length - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            count--;
        }
    }

    return count == 0;
}

int main() {
    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool canPlant = canPlaceFlowers(flowerbed, n);
    std::cout << std::boolalpha << canPlant << std::endl;  

    return 0;
}


//Question--5

#include <iostream>
#include <vector>
#include <algorithm>

int maximumProduct(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int length = nums.size();
    
    int product1 = nums[length - 1] * nums[length - 2] * nums[length - 3];
    int product2 = nums[0] * nums[1] * nums[length - 1];
    
    return std::max(product1, product2);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    int maxProduct = maximumProduct(nums);
    std::cout << maxProduct << std::endl;  

    return 0;
}


//Question--6

#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
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

    return -1;
}

int main() {
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int index = search(nums, target);
    std::cout << index << std::endl;  

    return 0;
}


//Question--7


#include <iostream>
#include <vector>

bool isMonotonic(const std::vector<int>& nums) {
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            isDecreasing = false;
        }
        if (nums[i] < nums[i - 1]) {
            isIncreasing = false;
        }
        if (!isIncreasing && !isDecreasing) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 3};
    bool isMonotonicArray = isMonotonic(nums);
    std::cout << std::boolalpha << isMonotonicArray << std::endl; 

    return 0;
}


//Question--8

#include <iostream>
#include <vector>

int minimumScore(std::vector<int>& nums, int k) {
    int minNum = nums[0];
    int maxNum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        minNum = std::min(minNum, nums[i] - k);
        maxNum = std::max(maxNum, nums[i] + k);
    }

    return maxNum - minNum;
}

int main() {
    std::vector<int> nums = {1};
    int k = 0;
    int minScore = minimumScore(nums, k);
    std::cout << minScore << std::endl; 

    return 0;
}
