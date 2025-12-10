/*
#SHORTEST COMMON SUPERSEQUENCE

LINK :- https://leetcode.com/problems/shortest-common-supersequence/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
🔑 Key Idea:
If we just concatenate str1 + str2, it may have duplicates in common characters.
To minimize length, we include the LCS only once.

str1 = "abac"
str2 = "cab"

LCS = "ab" (or "ba")

So:
SCS length = 4 (len1) + 3 (len2) − 2 (lcs) = 5

One SCS: "cabac"

✨Actual String Construction:
To construct the actual SCS:

Use a DP table to compute the LCS.

Backtrack through the table:

If characters match, add once.

If they differ, add both (from either string) in the right order.
*/

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = n, j = m;
        string result = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result += s1[i - 1];
                i--; j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += s1[i - 1];
                i--;
            }
            else {
                result += s2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            result += s1[i - 1];
            i--;
        }
        while (j > 0) {
            result += s2[j - 1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    string s1 = "abac";
    string s2 = "cab";
    Solution obj;
    cout << obj.shortestCommonSupersequence(s1, s2);
    return 0;
}