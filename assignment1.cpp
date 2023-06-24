//Question--1
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








//Question--2
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int k = 0; 

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    std::vector<int> nums = { 3, 2, 2, 3 };
    int val = 3;

    int k = removeElement(nums, val);

    std::cout << "k = " << k << std::endl;
    std::cout << "nums = ";
    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}








//Question--3
#include <iostream>

int searchInsert(int* nums, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 5;

    int index = searchInsert(nums, size, target);

    std::cout << "Target index: " << index << std::endl;

    return 0;
}









//Question--4
#include <iostream>

int* plusOne(int* digits, int size, int& newSize) {
    bool carry = true;

    
    for (int i = size - 1; i >= 0; i--) {
        if (carry) {
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                carry = false;
            }
        }
    }

    if (carry) {
        newSize = size + 1;
        int* newDigits = new int[newSize];
        newDigits[0] = 1;
        for (int i = 1; i < newSize; i++) {
            newDigits[i] = 0;
        }
        return newDigits;
    } else {
        newSize = size;
        return digits;
    }
}

int main() {
    int digits[] = {1, 2, 9};
    int size = sizeof(digits) / sizeof(digits[0]);

    int newSize = 0;
    int* result = plusOne(digits, size, newSize);

    std::cout << "Result: ";
    for (int i = 0; i < newSize; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}












//Question--5
#include <iostream>

void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1; 
    int j = n - 1; 
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

   
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int nums1[6] = {1, 3, 5, 0, 0, 0};
    int m = 3;
    int nums2[3] = {2, 4, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    std::cout << "Merged Array: ";
    for (int i = 0; i < m + n; i++) {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}












//Question--6
#include <iostream>

bool containsDuplicate(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    bool hasDuplicates = containsDuplicate(nums, size);

    if (hasDuplicates) {
        std::cout << "The array contains duplicates." << std::endl;
    } else {
        std::cout << "The array does not contain duplicates." << std::endl;
    }

    return 0;
}








//Question--7
#include <iostream>

void moveZeroes(int* nums, int size) {
    int j = 0;  


    for (int i = 0; i < size; i++) {
        
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    // Fill the remaining positions from j to the end of the array with zeros
    while (j < size) {
        nums[j] = 0;
        j++;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, size);

    std::cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}











//Question--8
#include <iostream>
#include <cmath>

int* findErrorNums(int* nums, int size) {
    int* result = new int[2];
    int duplicate = -1;
    int missing = -1;

    
    for (int i = 0; i < size; i++) {
        int index = abs(nums[i]);
        

        if (nums[index - 1] < 0) {
            duplicate = index;
        } else {
            nums[index - 1] = -nums[index - 1];
        }
    }


    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    result[0] = duplicate;
    result[1] = missing;
    return result;
}

int main() {
    int nums[] = {1, 2, 2, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int* result = findErrorNums(nums, size);

    std::cout << "Duplicate: " << result[0] << std::endl;
    std::cout << "Missing: " << result[1] << std::endl;

    delete[] result;

    return 0;
}
