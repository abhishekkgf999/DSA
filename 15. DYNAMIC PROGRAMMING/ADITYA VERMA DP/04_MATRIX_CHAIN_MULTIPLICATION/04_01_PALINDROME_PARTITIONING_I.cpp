/*
#PALINDROME PARTITIONING - I

LINK :- https://leetcode.com/problems/palindrome-partitioning/

*/

#include<bits/stdc++.h>
using namespace std;

/*

### 🔹 Short Note

This solution generates all palindromic partitions of a given string using a combination of dynamic programming and backtracking:

* A 2D DP table is used to precompute which substrings s[i..j] are palindromes.
* Then, a recursive function (solve) builds partitions by checking each substring and exploring further only when it's a palindrome.
* The final result contains all combinations where each substring in the partition is a palindrome.
* Time complexity: Exponential in the worst case due to recursion, but optimized with DP palindrome checks.

Let me know if you'd like the dry run or visual tree explanation for better clarity.

*/

//TIME COMPLEXITY :- BACKTRACKING (2^N) + 2 LOOPS FOR GENERATING DP TABLE (N^2)
//SPACE COMPLEXTY :- FOR STORING STATE OF PALINDROMIC SUBSTRING O(N^2)
class Solution {
public:
    // Recursive backtracking function to generate all palindromic partitions
    void solve(string& s, int i, vector<string>& temp, vector<vector<bool>>& dp, vector<vector<string>>& ans) {
        // If we reached the end of the string, add the current partition to the answer
        if (i == s.length()) {
            ans.push_back(temp);
            return;
        }

        // Try all possible substrings starting from index i
        for (int j = i; j < s.length(); j++) {
            // If substring s[i..j] is a palindrome
            if (dp[i][j] == true) {
                temp.push_back(s.substr(i, j - i + 1)); // Choose the substring
                solve(s, j + 1, temp, dp, ans);         // Explore further
                temp.pop_back();                        // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        // Precompute palindrome information using dynamic programming
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // Fill dp[i][j] = true if s[i..j] is a palindrome
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                // If end characters match and middle substring is palindrome (or L == 2)
                if (s[i] == s[j]) {
                    if (L == 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<vector<string>> ans;  // Stores all valid partitions
        vector<string> temp;         // Temporary list to store current partition

        // Start recursive partitioning from index 0
        solve(s, 0, temp, dp, ans);

        return ans;
    }
};


int main() {
    Solution obj;
    string s = "aab";

    vector<vector<string>> ans = obj.partition(s);

    for (auto i : ans) {
        for (auto j : i) {
            cout << j << ", ";
        }cout << endl;
    }

    return 0;
}