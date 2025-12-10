/*
#PRINTING LONGEST COMMON SUBSEQUENCE (TABULATION)

LINK:- https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the DP table
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

        string ans = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans.push_back(s1[i - 1]);
                i--; j--;
            }
            else if (dp[i][j - 1] > dp[i - 1][j]) {
                j--;
            }
            else {
                i--;
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution obj;
    obj.longestCommonSubsequence(text1, text2);
    return 0;
}