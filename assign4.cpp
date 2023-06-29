//Question--1

#include <iostream>
#include <vector>

std::vector<int> find_common_elements(const std::vector<int>& arr1, const std::vector<int>& arr2, const std::vector<int>& arr3) {
    int p1 = 0, p2 = 0, p3 = 0;
    std::vector<int> result;

    while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) {
        if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) {
            result.push_back(arr1[p1]);
            p1++;
            p2++;
            p3++;
        }
        else if (arr1[p1] < arr2[p2]) {
            p1++;
        }
        else if (arr2[p2] < arr3[p3]) {
            p2++;
        }
        else {
            p3++;
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {1, 2, 5, 7, 9};
    std::vector<int> arr3 = {1, 3, 4, 5, 8};

    std::vector<int> result = find_common_elements(arr1, arr2, arr3);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


//Question--2

#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> find_disjoint_nums(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    std::vector<int> distinct_nums1;
    std::vector<int> distinct_nums2;

    for (int num : set1) {
        if (set2.find(num) == set2.end()) {
            distinct_nums1.push_back(num);
        }
    }

    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
            distinct_nums2.push_back(num);
        }
    }

    return {distinct_nums1, distinct_nums2};
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    std::vector<std::vector<int>> result = find_disjoint_nums(nums1, nums2);

    for (const auto& nums : result) {
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



//Question--3

#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose_matrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::vector<std::vector<int>> result = transpose_matrix(matrix);

    for (const std::vector<int>& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


//Question--4

#include <iostream>
#include <vector>
#include <algorithm>

int array_pair_sum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());  // Sort the array in ascending order
    int n = nums.size();
    int result = 0;

    // Pair the elements in consecutive order and sum up the minimum values
    for (int i = 0; i < n; i += 2) {
        result += nums[i];
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 4, 3, 2};

    int result = array_pair_sum(nums);
    std::cout << result << std::endl;

    return 0;
}



//Question---5

#include <iostream>

int countCompleteRows(int n) {
    int k = 1;
    while ((k * (k + 1) / 2) <= n) {
        k++;
    }
    return k - 1;
}

int main() {
    int n = 5;
    int completeRows = countCompleteRows(n);
    std::cout << "Number of complete rows: " << completeRows << std::endl;
    return 0;
}



//Question--6

#include <iostream>
#include <vector>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n);

    int left = 0;
    int right = n - 1;
    int idx = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[idx] = leftSquare;
            left++;
        } else {
            result[idx] = rightSquare;
            right--;
        }
        idx--;
    }

    return result;
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    std::vector<int> result = sortedSquares(nums);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}




//Question--8

#include <iostream>
#include <vector>

std::vector<int> rearrangeArray(std::vector<int>& nums) {
    int n = nums.size() / 2;
    std::vector<int> result;

    for (int i = 0; i < n; i++) {
        result.push_back(nums[i]);
        result.push_back(nums[i + n]);
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    std::vector<int> rearranged = rearrangeArray(nums);

    std::cout << "Rearranged array: [";
    for (int i = 0; i < rearranged.size(); i++) {
        std::cout << rearranged[i];
        if (i != rearranged.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}


