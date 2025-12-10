/*
#LONGEST COMMONE SUBSTRING

link :- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_recursion {
public:
    int max_length = 0;

    int solve(string& s1, int n, string& s2, int m) {
        if (n == 0 || m == 0) return 0;

        int current = 0;
        if (s1[n - 1] == s2[m - 1]) {
            current = 1 + solve(s1, n - 1, s2, m - 1);
            max_length = max(max_length, current);
        }
        else {
            solve(s1, n, s2, m - 1);
            solve(s1, n - 1, s2, m);
        }

        return current;
    }

    int longestCommonSubstr(string& s1, string& s2) {
        max_length = 0;
        solve(s1, s1.size(), s2, s2.size());
        return max_length;
    }
};

class Solution_memoization {
public:
    int max_length = 0;

    int solve(string& s1, int n, string& s2, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) return 0;

        if (dp[n][m] != -1) return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            dp[n][m] = 1 + solve(s1, n - 1, s2, m - 1, dp);
            max_length = max(max_length, dp[n][m]);
        }
        else {
            dp[n][m] = 0; // mismatch ends the substring
        }

        // Always explore both directions to cover all substrings
        solve(s1, n - 1, s2, m, dp);
        solve(s1, n, s2, m - 1, dp);

        return dp[n][m];
    }

    int longestCommonSubstr(string& s1, string& s2) {
        max_length = 0;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        solve(s1, n, s2, m, dp);
        return max_length;
    }
};


class Solution_tabulation {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int max_length = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    max_length = max(max_length, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return max_length;
    }
};



int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";
    Solution_memoization obj;
    cout << obj.longestCommonSubstr(s1, s2);
    return 0;
}