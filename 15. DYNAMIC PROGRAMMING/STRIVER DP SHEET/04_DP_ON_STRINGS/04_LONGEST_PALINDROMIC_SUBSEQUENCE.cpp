/*
#LONGEST PALINDROMIC SUBSEQUENCE

LINK :- https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
✅ Core Insight:
A palindromic subsequence reads the same forwards and backwards.

So, if a string s has a palindromic subsequence, then:

That subsequence also appears in reverse order in the reversed string.

This means:

The Longest Palindromic Subsequence of s is the Longest Common Subsequence (LCS) of s and reverse(s).


🧠 Intuition:
A palindrome is symmetric.

So its sequence of characters must appear in both s and its reverse.

Hence, LCS between s and reverse(s) finds the maximum length subsequence that meets the palindrome condition.

*/

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
    string s = "bbbab";
    Solution obj;
    cout << obj.longestPalindromeSubseq(s);
    return 0;
}