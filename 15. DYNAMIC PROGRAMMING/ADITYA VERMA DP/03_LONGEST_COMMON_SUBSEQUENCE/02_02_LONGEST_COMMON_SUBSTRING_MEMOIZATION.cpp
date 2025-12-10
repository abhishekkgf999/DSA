/*
#LONGEST COMMON SUBSTRING (MEMOIZATION)

LINK:- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

*/


/*
INTUITION

=> The function explores all combinations of suffixes of s1 and s2 starting at index n and m (1-based indexing).

=> If characters match, we extend the current matching substring by adding 1 to the result of the subproblem (n-1, m-1).

=> If they don't, the substring is broken, and we reset dp[n][m] to 0.

=> In both cases, we continue exploring the rest of the string combinations to ensure we don’t miss any valid substrings.

=> max_length keeps track of the longest matching substring found so far.

APPROACH (Recursive with Memoization)

1. Function Definition:
   - The recursive function `solve(n, m)` returns the length of the common substring ending at s1[n-1] and s2[m-1].

2. Base Case:
   - If either n or m reaches 0, return 0 (no characters left to match).

3. Memoization:
   - Store results in a 2D dp table to avoid recomputation.
   - dp[n][m] holds the length of the common substring ending at s1[n-1] and s2[m-1].

4. Recursive Steps:
   - If s1[n-1] == s2[m-1], then:
     - dp[n][m] = 1 + solve(n-1, m-1)
     - Update max_length with dp[n][m]
   - If not equal:
     - dp[n][m] = 0 (since a common substring ends here)
   - Recursively call for solve(n-1, m) and solve(n, m-1) to explore other substring combinations (but don't use their return values).

5. Final Answer:
   - max_length stores the length of the longest common substring across all recursive paths.

COMPLEXITY

- Time: O(n × m), since each (n, m) state is computed once.
- Space: O(n × m) for the dp table + O(n + m) for recursion stack.
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
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


int main() {
    string text1 = "ABCDGH";
    string text2 = "ACDGHR";
    Solution obj;
    cout << obj.longestCommonSubstr(text1, text2);
    return 0;
}