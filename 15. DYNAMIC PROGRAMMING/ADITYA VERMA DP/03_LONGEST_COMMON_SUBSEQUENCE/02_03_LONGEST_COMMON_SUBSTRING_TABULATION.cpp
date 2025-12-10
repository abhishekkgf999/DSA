/*
#LONGEST COMMON SUBSTRING (TABULATION)

LINK:- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

*/


/*
INTUITION

=> We want to find the length of the longest substring that appears in both strings **contiguously**.

=> A 2D DP table is used where dp[i][j] stores the length of the longest common substring ending at s1[i-1] and s2[j-1].

=> If characters match, we extend the common substring by adding 1 to dp[i-1][j-1].

=> If they don't match, the common substring breaks at this point, so we reset dp[i][j] to 0.

=> Throughout the iteration, we track the maximum value in dp[i][j] to find the length of the longest common substring.

APPROACH (Tabulation - Bottom-Up DP)

1. DP Definition:
   - dp[i][j] represents the length of the longest common substring ending at s1[i-1] and s2[j-1].

2. Initialization:
   - dp[0][j] = 0 and dp[i][0] = 0 for all i, j, as any substring compared with an empty string has length 0.

3. Transition:
   - For each i in [1, n] and j in [1, m]:
     - If s1[i-1] == s2[j-1], then:
       dp[i][j] = 1 + dp[i-1][j-1]
       Update max_length with dp[i][j]
     - Else:
       dp[i][j] = 0 (since the substring breaks here)

4. Final Answer:
   - max_length holds the length of the longest common substring found.

COMPLEXITY

- Time: O(n × m), for filling the DP table.
- Space: O(n × m), for the 2D DP table.
- (Can be optimized to O(m) using two rolling rows.)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
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

//SPACE OPTIMIZATION :- O(2m)
class Solution2 {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<int> previous(m + 1, 0), current(m + 1, 0);
        int max_length = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    current[j] = 1 + previous[j - 1];
                    // dp[i][j] = 1 + dp[i - 1][j - 1];
                    max_length = max(max_length, current[j]);
                }
                else {
                    current[j] = 0;
                }

            }
            previous = current;
        }

        return max_length;
    }
};


int main() {
    string text1 = "ABCDGH";
    string text2 = "ACDGHR";
    Solution obj;
    Solution2 obj2;
    cout << obj.longestCommonSubstr(text1, text2) << endl;
    cout << obj2.longestCommonSubstr(text1, text2);
    return 0;
}