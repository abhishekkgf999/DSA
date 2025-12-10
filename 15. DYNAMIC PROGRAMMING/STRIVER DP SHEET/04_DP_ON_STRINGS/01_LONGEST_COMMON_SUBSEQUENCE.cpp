/*
#LONGEST COMMON SUBSEQUENCE

LINK :- https://leetcode.com/problems/longest-common-subsequence/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(2^(m+n))
class Solution_recursion {
public:
    int solve(string text1, int n, string text2, int m) {
        if (n == 0 || m == 0) return 0;

        if (text1[n - 1] == text2[m - 1]) {
            return 1 + solve(text1, n - 1, text2, m - 1);
        }

        return max(solve(text1, n - 1, text2, m), solve(text1, n, text2, m - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        return solve(text1, n, text2, m);
    }
};

class Solution_memoization {
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

class Solution_tabulation {
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


class Solution_tabulation_with_space_optimization {
public:
    int longestCommonSubsequence(const string& s1, const string& s2) {
        int n = s1.size(), m = s2.size();
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
    string s1 = "abcde";
    string s2 = "ace";
    Solution_tabulation obj;
    cout << obj.longestCommonSubsequence(s1, s2);
    return 0;
}