/*
#Longest Palindromic Subsequence

LINK:- https://leetcode.com/problems/longest-palindromic-subsequence/description/

*/

/*
LONGEST PALINDROMIC SUBSEQUENCE (LPS)

GOAL:
- Find the length of the longest subsequence in a string that is also a palindrome.

KEY OBSERVATION:
- A palindrome reads the same forward and backward.
- If we reverse the original string and find the Longest Common Subsequence (LCS) between the original and the reversed string,
  the result will be the length of the Longest Palindromic Subsequence.

WHY THIS WORKS:
- A palindromic subsequence in the original string will appear in the same order in the reversed string.
- Hence, LCS(S, reverse(S)) gives the longest subsequence that is common to both — which will be palindromic by nature.

EXAMPLE:
Let s1 = "bbbab";
Let s2 = reverse(s1) = "babbb";

Now, compute LCS(s1, s2):
- LCS = "bbbb"
- Length = 4

So, the length of the longest palindromic subsequence is 4.

STEPS TO SOLVE:

1. Let s1 be the original string.
2. Let s2 = reverse(s1).
3. Compute the length of LCS(s1, s2) using either recursion + memoization or tabulation (DP).
4. Return the LCS length as the answer.

TIME COMPLEXITY:
- Using DP (Tabulation or Memoization): O(n^2)
- Space Complexity: O(n^2) for 2D DP, can be optimized to O(n) using space-optimized LCS.

NOTE:
- This method only finds the length of the LPS.
- If you want the actual LPS string, you'd need to backtrack through the LCS table.

RELATED VARIATIONS:
- Longest Palindromic Substring: Find the longest contiguous palindromic substring (solved via center expansion or dynamic programming).
- Minimum insertions to make a string palindrome: len(s) - LPS(s)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
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
int main() {
    string text1 = "bbbab";
    Solution obj;
    cout << obj.longestPalindromeSubseq(text1);
    return 0;
}