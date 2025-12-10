/*
#Delete Operation for Two Strings (MEMOIZATION)

LINK:- https://leetcode.com/problems/delete-operation-for-two-strings/description/

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s1, int n, string s2, int m, vector<vector<int>>& dp) {
        if (n == 0 && m == 0) return 0;

        if (n == 0) return m;
        if (m == 0) return n;

        if (dp[n][m] != -1) return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = solve(s1, n - 1, s2, m - 1, dp);
        }
        else {
            return dp[n][m] = min(1 + solve(s1, n - 1, s2, m, dp), 1 + solve(s1, n, s2, m - 1, dp));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return solve(word1, word1.size(), word2, word2.size(), dp);
    }
};

int main() {
    string text1 = "heap";
    string text2 = "pea";
    Solution obj;
    cout << obj.minDistance(text1, text2);
    return 0;
}