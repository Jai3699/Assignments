//Question--1


#include <iostream>
#include <vector>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    
    for (int i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j - 1] + s2[j - 1];

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "sea";
    string s2 = "eat";
    int result = minimumDeleteSum(s1, s2);
    cout << "Lowest ASCII sum of deleted characters: " << result << endl;
    return 0;
}



//Question--2



#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '*')
            st.push(c);
        else if (c == ')') {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else if (!st.empty() && st.top() == '*')
                st.pop();
            else
                return false;
        }
    }

    while (!st.empty()) {
        if (st.top() == '(')
            return false;
        st.pop();
    }

    return true;
}

int main() {
    string s = "()";
    bool isValidString = isValid(s);
    cout << (isValidString ? "true" : "false") << endl;
    return 0;
}




//Question--3



#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

   
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "sea";
    string word2 = "eat";
    int result = minDistance(word1, word2);
    cout << "Minimum number of steps required: " << result << endl;
    return 0;
}



//Question--4


#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(string s, int start, int end) {
    if (start > end)
        return NULL;

    int mid = s.find('(', start);
    int value = stoi(s.substr(start, mid - start));

    TreeNode* root = new TreeNode(value);

    int leftEnd = s.find(')', mid);
    root->left = buildTree(s, mid + 1, leftEnd - 1);
    root->right = buildTree(s, leftEnd + 2, end - 1);

    return root;
}


void printPreorder(TreeNode* root) {
    if (root == NULL)
        return;

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    string s = "4(2(3)(1))(6(5))";
    TreeNode* root = buildTree(s, 0, s.length() - 1);
    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    cout << endl;
    return 0;
}



//Question--5



#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int read = 0, write = 0, count = 1;

    for (int i = 1; i < n; i++) {
        if (chars[i] == chars[i - 1]) {
            count++;
        } else {
            chars[write++] = chars[i - 1];
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr)
                    chars[write++] = c;
            }
            count = 1;
        }
    }

    chars[write++] = chars[n - 1];
    if (count > 1) {
        string countStr = to_string(count);
        for (char c : countStr)
            chars[write++] = c;
    }

    return write;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int compressedLength = compress(chars);

    cout << "Compressed array: ";
    for (int i = 0; i < compressedLength; i++)
        cout << chars[i] << " ";
    cout << endl;

    return 0;
}





//Question--6


#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int sLen = s.length();
    int pLen = p.length();

    if (sLen < pLen)
        return result;

    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);

    for (char c : p)
        pCount[c - 'a']++;

    int left = 0, right = 0;
    while (right < sLen) {
        sCount[s[right] - 'a']++;

        if (right - left + 1 == pLen) {
            if (sCount == pCount)
                result.push_back(left);

            sCount[s[left] - 'a']--;
            left++;
        }

        right++;
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    cout << "Start indices of anagrams: ";
    for (int idx : result)
        cout << idx << " ";
    cout << endl;

    return 0;
}




//Question--7


#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<char> charStack;
    stack<int> countStack;

    string currentString = "";
    int currentCount = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currentCount = currentCount * 10 + (c - '0');
        } else if (c == '[') {
            countStack.push(currentCount);
            charStack.push('[');
            currentCount = 0;
        } else if (c == ']') {
            string repeatedString = "";
            while (charStack.top() != '[') {
                repeatedString = charStack.top() + repeatedString;
                charStack.pop();
            }

            charStack.pop();  // Pop the '['

            int repeatCount = countStack.top();
            countStack.pop();

            string combinedString = "";
            while (repeatCount > 0) {
                combinedString += repeatedString;
                repeatCount--;
            }

            for (char ch : combinedString)
                charStack.push(ch);
        } else {
            charStack.push(c);
        }
    }

    string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }

    return result;
}

int main() {
    string s = "3[a]2[bc]";
    string decodedString = decodeString(s);

    cout << "Decoded string: " << decodedString << endl;

    return 0;
}




//Question--8


#include <iostream>
#include <string>
using namespace std;

bool buddyStrings(string s, string goal) {
    if (s.length() != goal.length())
        return false;

    int n = s.length();
    int firstMismatch = -1, secondMismatch = -1;
    bool hasDuplicate = false;

    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            if (firstMismatch == -1) {
                firstMismatch = i;
            } else if (secondMismatch == -1) {
                secondMismatch = i;
            } else {
                return false;  
            }
        }

        if (!hasDuplicate && s.find(s[i], i + 1) != string::npos)
            hasDuplicate = true;
    }

    if (firstMismatch != -1 && secondMismatch != -1) {
        swap(s[firstMismatch], s[secondMismatch]);
        return s == goal;
    }

    return hasDuplicate;  
}

int main() {
    string s = "ab";
    string goal = "ba";
    bool result = buddyStrings(s, goal);

    cout << "Can swap two letters: " << (result ? "true" : "false") << endl;

    return 0;
}
