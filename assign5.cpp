//Question--1

#include <vector>
#include <iostream>

std::vector<std::vector<int>> convertTo2DArray(std::vector<int>& original, int m, int n) {
    int size = original.size();
    if (size != m * n) {
    
        return {};
    }
    
    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
    for (int i = 0; i < size; ++i) {
        int row = i / n;
        int col = i % n;
        result[row][col] = original[i];
    }
    
    return result;
}


int main() {
    std::vector<int> original = {1, 2, 3, 4}; 
    int m = 2; 
    int n = 2;  
    
    std::vector<std::vector<int>> result = convertTo2DArray(original, m, n);
    
    if (result.empty()) {
        std::cout << "Unable to construct a valid 2D array." << std::endl;
    } else {
        std::cout << "Constructed 2D array:" << std::endl;
        for (const auto& row : result) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}


//Question--2

#include <iostream>
int numberOfCompleteRows(int n) {
    int k = 1;
    while (k * (k + 1) / 2 <= n) {
        k++;
    }
    return k - 1;
}



int main() {
    int n = 10;  // Number of coins
    
    int completeRows = numberOfCompleteRows(n);
    
    std::cout << "Number of complete rows: " << completeRows << std::endl;
    
    return 0;
}



//Question--3


#include <vector>
#include <iostream>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n);
    int left = 0;
    int right = n - 1;
    int i = n - 1;
    
    while (left <= right) {
        int squareLeft = nums[left] * nums[left];
        int squareRight = nums[right] * nums[right];
        
        if (squareLeft > squareRight) {
            result[i] = squareLeft;
            left++;
        } else {
            result[i] = squareRight;
            right--;
        }
        
        i--;
    }
    
    return result;
}



int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    
    std::vector<int> result = sortedSquares(nums);
    
    std::cout << "Sorted squares: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}




//Question--4


#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> distinctIntegers(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    
    std::vector<int> distinctInNums1;
    std::vector<int> distinctInNums2;
    
    for (int num : set1) {
        if (set2.find(num) == set2.end()) {
            distinctInNums1.push_back(num);
        }
    }
    
    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
            distinctInNums2.push_back(num);
        }
    }
    
    return {distinctInNums1, distinctInNums2};
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};
    
    std::vector<std::vector<int>> result = distinctIntegers(nums1, nums2);
    
    std::cout << "Distinct integers in nums1 not present in nums2: ";
    for (int num : result[0]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Distinct integers in nums2 not present in nums1: ";
    for (int num : result[1]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}




//Question--5


#include <vector>
#include <cmath>

int distanceValue(const std::vector<int>& arr1, const std::vector<int>& arr2, int d) {
    int count = 0;
    for (int num1 : arr1) {
        bool found = false;
        for (int num2 : arr2) {
            if (std::abs(num1 - num2) <= d) {
                found = true;
                break;
            }
        }
        if (!found) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> arr1 = {4, 5, 8};
    std::vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    
    int distance = distanceValue(arr1, arr2, d);
    
    std::cout << "Distance value: " << distance << std::endl;
    
    return 0;
}



//Question--6


#include <vector>
#include <cmath>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;
    
    for (int num : nums) {
        int index = std::abs(num) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        } else {
            result.push_back(std::abs(num));
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    std::vector<int> duplicates = findDuplicates(nums);
    
    std::cout << "Integers that appear twice: ";
    for (int num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}



//Question--7


#include <vector>

int findMin(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
           
            left = mid + 1;
        } else {
          
            right = mid;
        }
    }
    
    return nums[left];
}

int main() {
    std::vector<int> nums = {3, 4, 5, 1, 2};
    
    int minimum = findMin(nums);
    
    std::cout << "Minimum element: " << minimum << std::endl;
    
    return 0;
}


//Question--8

#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    std::unordered_map<int, int> freqMap;
    std::vector<int> result;
    

    for (int num : changed) {
        freqMap[num]++;
    }
    
    
    for (int num : changed) {
        if (freqMap[num] == 0) {
          
            continue;
        }
        
        if (freqMap[2 * num] == 0) {
          
            return {};
        }
        
        
        result.push_back(num);
        
        
        freqMap[num]--;
        freqMap[2 * num]--;
    }
    
    return result;
}

int main() {
    std::vector<int> changed = {2, 2, 4, 4};
    
    std::vector<int> original = findOriginalArray(changed);
    
    std::cout << "Original array: ";
    for (int num : original) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


