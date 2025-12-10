/*
#WILDCARD MATCHING

LINK :- https://leetcode.com/problems/wildcard-matching/
*/

#include<bits/stdc++.h>
using namespace std;

/*

You need to match a string s against a pattern p which can include:

* '?' – matches exactly one character
* '*' – matches zero or more characters

Return true if the whole string matches the whole pattern.

---

### Matching Rules:

1. If characters match (s[i] == p[j]) or p[j] == '?'
   → move both pointers left: match(i-1, j-1)

2. If p[j] == '*'
   → try two options:

   * Treat * as empty: match(i, j-1)
   * Treat * as matching one or more: match(i-1, j)

   Final: match(i, j) = match(i-1, j) || match(i, j-1)

3. If characters don't match and no wildcard
   → return false

---

### Base Cases:

* If both s and p are empty → return true
* If p is empty but s is not → return false
* If s is empty:

  * return true only if all characters in remaining p are *
*/

//RECURSION TIME COMPLEXITY :- O(2^(n+m))
class Solution_RECURSION {
public:
    bool solve(string s, int n, string p, int m) {
        if (n == 0 && m == 0)
            return true;

        if (m == 0 && n != 0)
            return false;

        if (n == 0) {
            // s is empty, check if all remaining pattern chars are '*'
            for (int i = 0; i < m; ++i) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }

        if (s[n - 1] == p[m - 1] || p[m - 1] == '?') {
            return solve(s, n - 1, p, m - 1);
        }
        else if (p[m - 1] == '*') {
            return solve(s, n - 1, p, m) || solve(s, n, p, m - 1);
        }
        else {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return solve(s, n, p, m);
    }
};

//TIME AND SPACE COMPLEXITY :- O(N*M)
class Solution_memoization {
public:
    bool solve(string& s, int n, string& p, int m, vector<vector<int>>& dp) {
        if (n == 0 && m == 0)
            return true;

        if (m == 0 && n != 0)
            return false;

        if (n == 0) {
            for (int i = 0; i < m; ++i) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }

        if (dp[n][m] != -1) return dp[n][m];

        if (s[n - 1] == p[m - 1] || p[m - 1] == '?') {
            return dp[n][m] = solve(s, n - 1, p, m - 1, dp);
        }
        else if (p[m - 1] == '*') {
            return dp[n][m] = solve(s, n - 1, p, m, dp) || solve(s, n, p, m - 1, dp);
        }
        else {
            return dp[n][m] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, n, p, m, dp);
    }
};


class Solution_tabulation {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = true;

        for (int j = 0; j < m; j++) {
            if (p[j] == '*') {
                dp[0][j + 1] = true;
            }
            else break;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};


class Solution_tabulation_with_space_optimization {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> prev(m + 1, false);
        vector<int> curr(m + 1, false);

        prev[0] = true;

        for (int j = 0; j < m; j++) {
            if (p[j] == '*') {
                prev[j + 1] = true;
            }
            else break;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};




int main() {
    string s1 = "aa";
    string s2 = "*";
    Solution_memoization obj;
    cout << obj.isMatch(s1, s2);
    return 0;
}