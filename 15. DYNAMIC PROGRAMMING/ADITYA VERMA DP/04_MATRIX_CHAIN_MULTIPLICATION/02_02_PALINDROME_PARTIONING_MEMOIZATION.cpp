/*
#PALINDROME PARTIONING (MEMOIZATION)

LINK:- https://leetcode.com/problems/palindrome-partitioning/description/

LINK2:- https://leetcode.com/problems/palindrome-partitioning-ii/description/
*/

/*
MATRIX CHAIN MULTIPLICATION - TABULATION (BOTTOM-UP DP)

GOAL:
Given an array 'arr' of size n, where the dimensions of matrices are:
Matrix 1: arr[0] x arr[1]
Matrix 2: arr[1] x arr[2]
...
Matrix n-1: arr[n-2] x arr[n-1]
Find the minimum number of scalar multiplications needed to multiply the entire chain.

APPROACH:
1. Create a 2D dp table of size n x n initialized to 0.
2. dp[i][j] represents the minimum cost (multiplications) to multiply matrices from index i to j.
3. Fill dp table in increasing order of chain length (from 2 to n-1).
4. For each pair (i, j), try all possible partitions (k from i to j-1).
5. For each partition, calculate cost as:
   dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]
6. Take the minimum of all possible partitions.
7. Final answer will be in dp[1][n-1].

TIME COMPLEXITY:
O(n^3) due to three nested loops: one for chain length, one for i, and one for k.

SPACE COMPLEXITY:
O(n^2) for the dp table.

USAGE:
Used when we need to find optimal parenthesization of matrix chain to minimize cost.

*/


#include<bits/stdc++.h>
using namespace std;


//Time Complexity = O(n²) subproblems × O(n) per subproblem = O(n³)
//Total space = O(n²) + O(n) = O(n²)
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        int start = i, end = j;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }

        return true;
    }
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (isPalindrome(s, i, j)) return 0;

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp_ans = solve(s, i, k, dp) + solve(s, k + 1, j, dp) + 1;

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