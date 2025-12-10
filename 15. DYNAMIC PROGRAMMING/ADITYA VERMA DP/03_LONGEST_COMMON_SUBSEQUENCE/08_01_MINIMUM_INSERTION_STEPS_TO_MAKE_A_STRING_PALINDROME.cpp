/*
#Minimum Insertion Steps to Make a String Palindrome

LINK:- https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

*/

/*
# Minimum Insertion Steps to Make a String Palindrome

GOAL:
- Given a string `s`, return the minimum number of insertions required to make it a palindrome.

KEY OBSERVATION:
- The minimum insertions = total length of the string - length of the Longest Palindromic Subsequence (LPS).
- The longer the palindromic subsequence already present, the fewer insertions are needed.

WHY THIS WORKS:
- A palindrome reads the same forwards and backwards.
- The Longest Palindromic Subsequence (LPS) in `s` is the maximum part that is already palindromic.
- We only need to insert characters to fill the gaps to make the entire string a palindrome.

HOW TO FIND LPS:
- Let `s1 = s`, and `s2 = reverse(s1)`.
- Compute the Longest Common Subsequence (LCS) of `s1` and `s2`:
  - LCS(s1, s2) gives the longest subsequence that is the same in both original and reversed strings => i.e., LPS.

EXAMPLE:
Let s = "bbbab";
Reverse(s) = "babbb";

LCS("bbbab", "babbb") = "bbbb" => length = 4
Minimum insertions = length of s - LPS = 5 - 4 = 1

APPROACH:
1. Set s1 = s, s2 = reverse(s)
2. Compute LCS(s1, s2) using:
   - Recursion + Memoization OR
   - Tabulation (preferred for bottom-up DP)
3. Result = s.length() - LCS(s1, s2)

TIME COMPLEXITY:
- Time: O(n²)
- Space: O(n²), can be optimized to O(n) using 1D DP for LCS

RELATED CONCEPTS:
- Longest Palindromic Subsequence (LPS): Use LCS(s, reverse(s))
- Minimum Deletions to Make a Palindrome: Also equals s.length() - LPS
- Longest Palindromic Substring: Different from LPS (deals with contiguous substrings)
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s1) {
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

        return  (s1.size() - dp[n][m]);
    }
};

int main() {
    string text1 = "bbbab";
    Solution obj;
    cout << obj.minInsertions(text1);
    return 0;
}