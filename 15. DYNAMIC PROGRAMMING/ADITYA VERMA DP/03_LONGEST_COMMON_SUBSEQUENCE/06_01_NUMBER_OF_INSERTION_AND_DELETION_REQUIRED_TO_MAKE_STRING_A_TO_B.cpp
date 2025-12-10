/*
#Delete Operation for Two Strings (MEMOIZATION)

LINK:- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};


/*
Since each dp[i][j] only depends on:
- dp[i-1][j] (previous row, same column)
- dp[i][j-1] (current row, previous column)
- dp[i-1][j-1] (previous row, previous column)

*/

class Solution2 {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> previous(m + 1, 0), current(m + 1, 0);

        // Initialize base case: converting "" to s2[0..j]
        for (int j = 0; j <= m; j++) {
            previous[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            current[0] = i; // base case: converting s1[0..i] to ""
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    current[j] = previous[j - 1];
                }
                else {
                    current[j] = 1 + min(previous[j], current[j - 1]);
                }
            }
            previous = current;
        }

        return previous[m];
    }
};

//ANOTHER METHOD
/*
STRING A = "HEAP"
STRING B = "PEA"

LCS OF A AND B IS :- "EA"

NUMBER DELETION REQUIRED TO COVERT STRING A INTO LCS = LENGTH OF A - LENGTH OF LCS = 2
NUMBER INSERTION REQUIRED TO COVERT LCS INTO STRING B = LENGTH OF B - LENGTH OF LCS = 1

TOTAL INSERTION AND DELETION STEP REQUIRED  = 2 + 1 = 3

*/
class Solution_NEW {
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

        return (n - dp[n][m]) + (m - dp[n][m]);
    }
};

int main() {
    string text1 = "heap";
    string text2 = "pea";
    Solution_NEW obj;
    cout << obj.longestCommonSubsequence(text1, text2);
    return 0;
}