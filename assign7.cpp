//Question--1

#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> s_map;
    unordered_map<char, char> t_map;

    for (int i = 0; i < s.length(); i++) {
        char s_char = s[i];
        char t_char = t[i];

        if (s_map.find(s_char) == s_map.end()) {
            s_map[s_char] = t_char;
        }
        if (t_map.find(t_char) == t_map.end()) {
            t_map[t_char] = s_char;
        }

        if (s_map[s_char] != t_char || t_map[t_char] != s_char) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    cout << boolalpha << isIsomorphic(s, t) << endl;

    return 0;
}



//Question--2


#include <iostream>

using namespace std;

bool isStrobogrammatic(string num) {
    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        char leftChar = num[left];
        char rightChar = num[right];

        if ((leftChar == '0' && rightChar == '0') || (leftChar == '1' && rightChar == '1') || (leftChar == '8' && rightChar == '8') || (leftChar == '6' && rightChar == '9') || (leftChar == '9' && rightChar == '6')) {
            left++;
            right--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string num = "69";

    cout << boolalpha << isStrobogrammatic(num) << endl;

    return 0;
}




//Question--3


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    string result;
    int p1 = num1.length() - 1;
    int p2 = num2.length() - 1;
    int carry = 0;

    while (p1 >= 0 || p2 >= 0) {
        int digit1 = (p1 >= 0) ? num1[p1] - '0' : 0;
        int digit2 = (p2 >= 0) ? num2[p2] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');

        p1--;
        p2--;
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string num1 = "11";
    string num2 = "123";

    cout << addStrings(num1, num2) << endl;

    return 0;
}




//Question--4

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    vector<string> words;
    string word;

    // Split the input string into words
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse each word
    for (string& word : words) {
        reverse(word.begin(), word.end());
    }

    // Join the reversed words back into a string
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string s = "Let's take LeetCode contest";

    cout << reverseWords(s) << endl;

    return 0;
}




//Question--5


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseStr(string s, int k) {
    int n = s.length();
    char* arr = &s[0];

    for (int i = 0; i < n; i += 2 * k) {
        int left = i;
        int right = min(i + k - 1, n - 1);

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;

    cout << reverseStr(s, k) << endl;

    return 0;
}



//Question--6


#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    string concatenated = s + s;

    return concatenated.find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";

    cout << boolalpha << rotateString(s, goal) << endl;

    return 0;
}



//Question--7


#include <iostream>
#include <stack>
#include <string>

using namespace std;

string buildString(const string& str) {
    stack<char> st;

    for (char c : str) {
        if (c != '#') {
            st.push(c);
        } else if (!st.empty()) {
            st.pop();
        }
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}

bool backspaceCompare(string s, string t) {
    return buildString(s) == buildString(t);
}

int main() {
    string s = "ab#c";
    string t = "ad#c";

    cout << boolalpha << backspaceCompare(s, t) << endl;

    return 0;
}



//Question--8


#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n <= 2) {
        return true;
    }

    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];

    double slope = static_cast<double>(y2 - y1) / (x2 - x1);

    for (int i = 2; i < n; i++) {
        int xi = coordinates[i][0];
        int yi = coordinates[i][1];
        double currSlope = static_cast<double>(yi - y1) / (xi - x1);

        if (currSlope != slope) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};

    cout << boolalpha << checkStraightLine(coordinates) << endl;

    return 0;
}
