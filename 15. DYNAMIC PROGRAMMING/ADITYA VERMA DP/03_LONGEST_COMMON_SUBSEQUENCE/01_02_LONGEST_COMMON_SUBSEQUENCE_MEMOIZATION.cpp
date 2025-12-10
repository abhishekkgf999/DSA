/*
#LONGEST COMMON SUBSEQUENCE (MEMOIZATION)

LINK:- https://leetcode.com/problems/longest-common-subsequence/description/

*/

/*
INTUITION

- We aim to find the length of the Longest Common Subsequence (LCS) between two strings.
- A subsequence is a sequence that maintains the relative order of characters but does not require them to be contiguous.
- At each step, we compare characters from the end of both strings:
  1. If the characters match, we include it in the LCS and move both pointers back.
  2. If the characters don't match, we explore both options:
     - Skip the current character of the first string.
     - Skip the current character of the second string.
     - We take the maximum result from these two options.

APPROACH (Top-Down with Memoization)

1. DP Definition:
   - Let dp[i][j] represent the length of the LCS between the first i characters of text1 and the first j characters of text2.

2. Initialization:
   - Create a 2D dp array initialized to -1 to indicate uncomputed subproblems.
   - Base case: If either i or j becomes 0, return 0 (empty string has no common subsequence).

3. DP Transition:
   - If text1[i - 1] == text2[j - 1], include the character and move both pointers:
     dp[i][j] = 1 + dp[i-1][j-1].
   - Else, try both options (skip one character from either string):
     dp[i][j] = max(dp[i-1][j], dp[i][j-1]).

4. Final Answer:
   - The answer is stored in dp[n][m], where n and m are the lengths of text1 and text2 respectively.

COMPLEXITY

- Time: O(n * m), where n and m are lengths of the two strings.
- Space: O(n * m) for the dp table and O(n + m) for the recursion stack.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string text1, int n, string text2, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) return 0;

        if (dp[n][m] != -1) return dp[n][m];

        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] = 1 + solve(text1, n - 1, text2, m - 1, dp);
        }

        return dp[n][m] = max(solve(text1, n - 1, text2, m, dp), solve(text1, n, text2, m - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(text1, n, text2, m, dp);
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution obj;
    cout << obj.longestCommonSubsequence(text1, text2);
    return 0;
}