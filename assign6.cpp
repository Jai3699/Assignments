//Question1

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> reconstructPermutation(const std::string& s) {
    int n = s.length();
    std::vector<int> perm(n + 1);

  
    for (int i = 0; i <= n; i++) {
        perm[i] = i;
    }


    int start = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
           
            std::reverse(perm.begin() + start, perm.begin() + i + 2);
            start = i + 1;
        }
    }

    return perm;
}

int main() {
    std::string s;
    std::cout << "Enter the string representation of the permutation: ";
    std::cin >> s;

    std::vector<int> perm = reconstructPermutation(s);

    std::cout << "Reconstructed permutation: ";
    for (int num : perm) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}








//Question--2


#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target) {
            return true;
        }
        else if (matrix[row][col] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    bool result = searchMatrix(matrix, target);

    std::cout << "Target " << target << " is " << (result ? "found" : "not found") << " in the matrix." << std::endl;

    return 0;
}



//Question--3

#include <iostream>
#include <vector>

bool validMountainArray(const std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return false;
    }

    int left = 0;
    int right = n - 1;

    while (left < n - 1 && arr[left] < arr[left + 1]) {
        left++;
    }

    while (right > 0 && arr[right] < arr[right - 1]) {
        right--;
    }

    return (left > 0 && right < n - 1 && left == right);
}

int main() {
    std::vector<int> arr = {2, 1};
    
    bool result = validMountainArray(arr);
    
    std::cout << "The array is " << (result ? "a valid mountain array." : "not a valid mountain array.") << std::endl;

    return 0;
}



//Question--4

#include <iostream>
#include <vector>
#include <unordered_map>

int findMaxLength(const std::vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    int sum = 0;
    std::unordered_map<int, int> count;

    count[0] = -1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            sum -= 1;
        } else {
            sum += 1;
        }

        if (count.find(sum) != count.end()) {
            int len = i - count[sum];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            count[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    std::vector<int> nums = {0, 1};

    int result = findMaxLength(nums);

    std::cout << "The maximum length of a contiguous subarray with an equal number of 0s and 1s is: " << result << std::endl;

    return 0;
}


//Question--5

#include <iostream>
#include <vector>
#include <algorithm>

int minProductSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n = nums1.size();
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end(), std::greater<int>());

    int minProductSum = 0;
    for (int i = 0; i < n; i++) {
        minProductSum += nums1[i] * nums2[i];
    }

    return minProductSum;
}

int main() {
    std::vector<int> nums1 = {5, 3, 4, 2};
    std::vector<int> nums2 = {4, 2, 2, 5};

    int result = minProductSum(nums1, nums2);

    std::cout << "The minimum product sum is: " << result << std::endl;

    return 0;
}



//Question--6

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    int n = changed.size();
    std::vector<int> original;

    if (n % 2 != 0) {
        return {}; 
    }

    std::vector<int> sortedChanged = changed;
    std::sort(sortedChanged.begin(), sortedChanged.end());

    for (int i = 0; i < n; i++) {
        if (!original.empty() && original.back() == sortedChanged[i] / 2) {
            original.pop_back();
        } else {
            original.push_back(sortedChanged[i]);
        }
    }

    return original.empty() ? original : std::vector<int>();
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};

    std::vector<int> original = findOriginalArray(changed);

    std::cout << "Original array: ";
    if (!original.empty()) {
        for (int num : original) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "Empty array";
    }
    std::cout << std::endl;

    return 0;
}



//Question--7

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (num <= n * n) {
        for (int c = colStart; c <= colEnd; c++) {
            matrix[rowStart][c] = num++;
        }
        rowStart++;

        for (int r = rowStart; r <= rowEnd; r++) {
            matrix[r][colEnd] = num++;
        }
        colEnd--;

        if (rowStart > rowEnd) {
            break;
        }

        for (int c = colEnd; c >= colStart; c--) {
            matrix[rowEnd][c] = num++;
        }
        rowEnd--;

        for (int r = rowEnd; r >= rowStart; r--) {
            matrix[r][colStart] = num++;
        }
        colStart++;
    }

    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 3;

    std::vector<std::vector<int>> matrix = generateMatrix(n);

    std::cout << "Generated matrix:" << std::endl;
    printMatrix(matrix);

    return 0;
}




//Question--8

#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                result[i][j] += mat1[i][p] * mat2[p][j];
            }
        }
    }

    return result;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    std::vector<std::vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    std::vector<std::vector<int>> result = multiply(mat1, mat2);

    std::cout << "Result matrix:" << std::endl;
    printMatrix(result);

    return 0;
}
