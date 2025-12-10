/*
#DISTINCT SUBSEQUENCES

LINK:- https://leetcode.com/problems/distinct-subsequences/
*/

#include<bits/stdc++.h>
using namespace std;


//recursive algorithm time complexity :- O(2^n);

//memoization time complexity :- O(n*m);

/*
Logic is pretty simple, we will play same game as finding the longest common subsequence


but there is some catch, whenever we find same character, we will have two decisions, either include that character or not,

if include the character, then simply move both pointer to next element,
if not include, then move only first string pointer, because we have to find number of ways we can generate s2 subsequence through s1
so pointer of s1 will move, s2 pointer will stay there


if it doesnt match, then same as not include case

whenver our s2 pointer exhausted then simply we add 1 in our ans, and by this method we can count all distinct subsequences

-------------------------------------------------------------------------------------------------------------------------------------

✅ Core Idea:
Use recursion with two pointers (and memoization or tabulation for optimization):

Let i be the pointer for s1, and j for s2.

You want to **count all the ways you can form s2[j:] using s1[i:].

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

🔁 Recurrence Logic:

Case 1: When s1[i] == s2[j]

You have two choices:

Include this character → move both pointers: solve(i+1, j+1)

Exclude this character → move only s1 pointer: solve(i+1, j)

So:

count = solve(i+1, j+1) + solve(i+1, j);

*****************************************************

Case 2: When s1[i] != s2[j]

You can't include, so just skip s1[i]:

count = solve(i+1, j);

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

🛑 Base Cases:
✅ If j == s2.length() → we’ve matched all of s2, return 1

❌ If i == s1.length() but j < s2.length() → no way to match remaining s2, return 0

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

🧠 Time Complexity:
Exponential (2^n) in brute force

O(n * m) with memoization or tabulation
where n = s1.length() and m = s2.length()
*/


class Solution_memoization {
public:
    int solve(string s1, int n, string s2, int m, vector<vector<int>>& dp) {
        if (m == 0) return 1;

        if (n == 0 && m != 0) return 0;

        if (dp[n][m] != -1) return dp[n][m];

        int take = 0;
        int not_take = 0;
        if (s1[n - 1] == s2[m - 1]) {
            take += solve(s1, n - 1, s2, m - 1, dp) + solve(s1, n - 1, s2, m, dp);
        }
        else {
            not_take += solve(s1, n - 1, s2, m, dp);
        }

        return dp[n][m] = take + not_take;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, n, t, m, dp);
    }
};

/*
🔍 Why use double?
If you expect very large counts, use double or long long to prevent overflow.
The original Leetcode problem uses regular integers and passes, but it can overflow in theory.
*/
class Solution_tabulation {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};


int main() {
    string s1 = "rabbbit";
    string s2 = "rabbit";
    Solution_memoization obj;
    cout << obj.numDistinct(s1, s2);
    return 0;
}