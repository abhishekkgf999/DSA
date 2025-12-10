/*
#SHORTEST COMMON SUPERSEQUENCE (TABULATION)

LINK:- https://leetcode.com/problems/shortest-common-supersequence/

*/

/*
INTUITION

- The goal is to construct the shortest string that contains both s1 and s2 as subsequences.
- The key idea is to build the Longest Common Subsequence (LCS) first.
- Since SCS includes both strings and LCS is the common part, we can merge both strings while avoiding duplicate inclusion of common characters.

APPROACH (Tabulation)

1. Step 1: Compute LCS Table
   - Create a 2D DP table where dp[i][j] stores the length of LCS between s1[0..i-1] and s2[0..j-1].
   - If characters match: dp[i][j] = 1 + dp[i-1][j-1]
   - If not: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

2. Step 2: Reconstruct the Shortest Common Supersequence
   - Start from the bottom-right corner of the table and move backwards.
   - If characters match, include it once and move diagonally up-left.
   - If not, move in the direction of the larger value (either up or left) and include the character from the respective string.
   - Once one string is exhausted, add all remaining characters from the other string.

3. Final Answer:
   - The result string is built in reverse order, so reverse it at the end.

COMPLEXITY

- Time: O(n × m), where n = s1.length() and m = s2.length(), for both filling the table and reconstructing the SCS.
- Space: O(n × m) for the DP table (can be optimized to O(min(n, m)) if only LCS length is needed).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // Step 1: Build the LCS DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Reconstruct the SCS from the DP table
        int i = n, j = m;
        string result = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result += s1[i - 1];
                i--; j--;
            }
            /*
            - If characters differ, we check which direction gave us the longer LCS:
            - If dp[i-1][j] > dp[i][j-1], it means the LCS came from moving up → so we include s1[i-1].
            - Otherwise, it came from moving left → so we include s2[j-1].
            🧠 This ensures we include all characters from both strings, while still preserving the LCS in order.
            */
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += s1[i - 1];
                i--;
            }
            else {
                result += s2[j - 1];
                j--;
            }
        }

        // Add remaining characters from s1 or s2
        while (i > 0) {
            result += s1[i - 1];
            i--;
        }
        while (j > 0) {
            result += s2[j - 1];
            j--;
        }

        // Since we built the result backwards, reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    string text1 = "abac";
    string text2 = "cab";
    Solution obj;
    cout << obj.shortestCommonSupersequence(text1, text2);
    return 0;
}