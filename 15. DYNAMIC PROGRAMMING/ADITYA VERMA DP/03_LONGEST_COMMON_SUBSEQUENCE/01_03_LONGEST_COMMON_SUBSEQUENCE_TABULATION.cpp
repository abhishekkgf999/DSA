/*
#LONGEST COMMON SUBSEQUENCE (TABULATION)

LINK:- https://leetcode.com/problems/longest-common-subsequence/description/

*/

/*
INTUITION

- We aim to find the length of the Longest Common Subsequence (LCS) between two strings.
- A subsequence maintains the relative order of characters but does not require contiguity.
- We compare characters from both strings:
  1. If the characters match, we include it in the LCS and move diagonally in the DP table.
  2. If the characters don't match, we consider the maximum LCS by:
     - Skipping the current character from the first string.
     - Skipping the current character from the second string.

APPROACH (Tabulation - Bottom-Up DP)

1. DP Definition:
   - Let dp[i][j] represent the length of the LCS between the first i characters of s1 and the first j characters of s2.

2. Initialization:
   - dp[0][j] = 0 and dp[i][0] = 0 for all i and j, since LCS with an empty string is 0.

3. DP Transition:
   - For i = 1 to n and j = 1 to m:
     - If s1[i - 1] == s2[j - 1], then:
       dp[i][j] = 1 + dp[i - 1][j - 1]
     - Else:
       dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

4. Final Answer:
   - The length of the LCS is stored in dp[n][m], where n and m are the lengths of s1 and s2.

COMPLEXITY

- Time: O(n * m), where n and m are the lengths of the two strings.
- Space: O(n * m), for the 2D DP table.
- (Can be optimized to O(m) using 2 rolling rows.)
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }
};

class Solution2 {
public:
    int longestCommonSubsequence(const string& s1, const string& s2) {
        int n = s1.size(), m = s2.size();

        // Using two 1D arrays to optimize space from O(n*m) to O(m)
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }

        return prev[m];
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution obj;
    cout << obj.longestCommonSubsequence(text1, text2);
    return 0;
}