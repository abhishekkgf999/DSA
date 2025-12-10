/*
#SHORTEST COMMON SUPERSEQUENCE (MEMOIZATION)

LINK:- https://leetcode.com/problems/shortest-common-supersequence/

*/

/*
INTUITION

- The goal is to find the shortest string that contains both s1 and s2 as subsequences.
- At each step, we compare characters from both strings:
  1. If the characters match, we include that character once in the result and move both pointers forward.
  2. If they don’t match, we have two choices:
     - Take the current character from s1 and recursively find the SCS for the remaining part.
     - Take the current character from s2 and recursively find the SCS for the remaining part.
     - We return the option that gives a shorter overall supersequence.

APPROACH (Recursive with Memoization)

1. Function Definition:
   - `solve(i, j)` returns the shortest common supersequence of s1 starting at index `i` and s2 starting at index `j`.

2. Base Cases:
   - If both i and j reach the end of their strings, return an empty string.
   - If s1 is exhausted, return the remaining part of s2.
   - If s2 is exhausted, return the remaining part of s1.

3. Memoization:
   - A 2D DP table `dp[i][j]` stores the shortest supersequence starting at indices i and j.
   - Before computing a subproblem, check if it's already solved in `dp[i][j]`.

4. Recursive Steps:
   - If s1[i] == s2[j], include the character once and recurse with (i+1, j+1).
   - If characters don’t match:
     - Try both options: add s1[i] or s2[j] to the result.
     - Choose the option which leads to a shorter supersequence.
   - Store the result in `dp[i][j]` before returning.

5. Final Answer:
   - Call solve(0, 0) with an empty DP table to construct the shortest common supersequence from the start.

COMPLEXITY

- Time: O(n × m), where n and m are the lengths of s1 and s2, due to memoization avoiding repeated computations.
- Space: O(n × m) for the DP table + O(n + m) for the recursion stack depth.
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string s1, int i, string s2, int j, vector<vector<string>>& dp) {
        if (i == s1.size() && j == s2.size()) return "";

        if (i == s1.size()) return s2.substr(j);
        if (j == s2.size()) return s1.substr(i);

        // Return cached result if already computed
        if (dp[i][j] != "") return dp[i][j];

        // If characters match, include it once and move both pointers
        if (s1[i] == s2[j]) {
            dp[i][j] = s1[i] + solve(s1, i + 1, s2, j + 1, dp);
        }
        else {
            // If characters differ, explore both options:
            // 1. Include s1[i] and move i
            // 2. Include s2[j] and move j
            string option1 = s1[i] + solve(s1, i + 1, s2, j, dp);
            string option2 = s2[j] + solve(s1, i, s2, j + 1, dp);

            // Choose the shorter supersequence
            dp[i][j] = (option1.size() < option2.size()) ? option1 : option2;
        }

        return dp[i][j];
    }

    string shortestCommonSupersequence(string s1, string s2) {
        vector<vector<string>> dp(s1.size() + 1, vector<string>(s2.size() + 1, ""));
        return solve(s1, 0, s2, 0, dp);
    }
};

int main() {
    string text1 = "abac";
    string text2 = "cab";
    Solution obj;
    cout << obj.shortestCommonSupersequence(text1, text2);
    return 0;
}