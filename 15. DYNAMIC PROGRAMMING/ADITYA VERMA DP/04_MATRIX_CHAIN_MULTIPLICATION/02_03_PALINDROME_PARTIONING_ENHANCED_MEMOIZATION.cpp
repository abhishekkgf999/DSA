/*
#PALINDROME PARTIONING (ENHANCED MEMOIZATION)

LINK:- https://leetcode.com/problems/palindrome-partitioning/description/

LINK2:- https://leetcode.com/problems/palindrome-partitioning-ii/description/
*/


#include<bits/stdc++.h>
using namespace std;

/*
| Aspect    | Complexity |
| --------- | ---------- |
| **Time**  | O(n³)      |
| **Space** | O(n²)      |

*/

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (isPalindrome(s, i, j)) return 0;

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {
            int left = (dp[i][k] != -1) ? dp[i][k] : solve(s, i, k, dp);
            int right = (dp[k + 1][j] != -1) ? dp[k + 1][j] : solve(s, k + 1, j, dp);

            int temp_ans = left + right + 1;

            ans = min(ans, temp_ans);
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, s.size() - 1, dp);
    }
};

int main() {
    string s = "aab";
    Solution obj;

    cout << obj.minCut(s);
    return 0;
}