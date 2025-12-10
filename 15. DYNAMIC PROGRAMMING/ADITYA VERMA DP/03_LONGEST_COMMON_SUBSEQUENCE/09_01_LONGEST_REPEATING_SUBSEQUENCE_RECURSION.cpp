/*
#Longest Repeating Subsequence (RECURSION)

LINK:- https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
*/

/*
Longest Repeating Subsequence

Intuition:
- This is a variation of the Longest Common Subsequence (LCS) problem.
- The twist is: you're given only one string, and you need to find the longest subsequence that appears at least twice in the string.
- These repeated subsequences must occur at different positions, meaning we cannot match a character with itself.

Why LCS works:
- Treat the same string as two separate strings: s1 and s2 (both equal to input string s).
- Apply LCS with a slight modification:
  Only match characters when s1[i-1] == s2[j-1] and i != j (to avoid matching the same index).

Example:
Input: s = "aabebcdd"
s1 = s2 = "aabebcdd"

Now apply modified LCS:
If s1[i-1] == s2[j-1] and i != j → it's part of the repeating subsequence

Longest Repeating Subsequence = "abd" or "abd" → length = 3

Approach:
1. Let n = s.length()
2. Create a 2D DP table of size (n+1) x (n+1)
3. Use the following DP logic:
   - If s1[i-1] == s2[j-1] and i != j:
       dp[i][j] = 1 + dp[i-1][j-1]
   - Else:
       dp[i][j] = max(dp[i-1][j], dp[i][j-1])
4. Final answer is dp[n][n]

Time and Space Complexity:
- Time: O(n^2)
- Space: O(n^2)
  (Space can be optimized to O(n) if we only need the length)
*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LongestRepeatingSubsequence(string& s1) {
        // Code here
        int n = s1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s1[j - 1] && i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][n];
    }
};

int main() {
    string text1 = "axxzxy";
    Solution obj;
    cout << obj.LongestRepeatingSubsequence(text1);
    return 0;
}