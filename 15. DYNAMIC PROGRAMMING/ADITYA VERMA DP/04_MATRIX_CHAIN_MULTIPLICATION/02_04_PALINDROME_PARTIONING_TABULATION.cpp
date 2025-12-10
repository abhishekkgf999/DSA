/*
#PALINDROME PARTIONING (TABULATION)

LINK:- https://leetcode.com/problems/palindrome-partitioning/description/

LINK2:- https://leetcode.com/problems/palindrome-partitioning-ii/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
This solution computes the minimum cuts needed to partition a string s into palindromic substrings.
It uses a 2D table to precompute all palindromic substrings (ps[i][j]), and then uses 1D DP (dp[i]) to calculate the minimum cuts up to each index i.

The idea is:

* If s[0..i] is a palindrome, dp[i] = 0
* Else, for every valid k < i, if s[k+1..i] is a palindrome, update dp[i] = min(dp[i], dp[k] + 1)

---

### ⏱️ Time and Space Complexity

| Aspect | Complexity |
| ------ | ---------- |
| Time   | O(n²)      |
| Space  | O(n²)      |

Explanation:

* Palindrome table ps[i][j] fills in O(n²)
* For each i, inner loop over k < i takes O(n) → total O(n²)
* Space: 2D table ps[n][n] + 1D table dp[n] → O(n²)
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // Step 1: Precompute all palindromic substrings
        vector<vector<bool>> ps(n, vector<bool>(n, false)); // ps[i][j] = true if s[i..j] is palindrome

        // All single characters are palindromes
        for (int i = 0; i < n; i++) {
            ps[i][i] = true;
        }

        // Fill palindromic table for substrings of length >= 2
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (s[i] == s[j]) {
                    if (L == 2) {
                        ps[i][j] = true; // two same characters side-by-side
                    }
                    else ps[i][j] = ps[i + 1][j - 1]; // check inner substring
                }
            }
        }

        // Step 2: DP to find minimum cuts
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            // If s[0..i] is a palindrome, no cut is needed
            if (ps[0][i]) dp[i] = 0;
            else {
                // Try all valid previous cuts
                for (int k = 0; k < i; k++) {
                    if (ps[k + 1][i]) {
                        dp[i] = min(dp[i], dp[k] + 1); // cut between k and k+1
                    }
                }
            }
        }

        return dp[n - 1]; // minimum cuts to partition s into palindromic substrings
    }
};


int main() {
    string s = "abcb";
    Solution obj;
    cout << obj.minCut(s);
    return 0;
}