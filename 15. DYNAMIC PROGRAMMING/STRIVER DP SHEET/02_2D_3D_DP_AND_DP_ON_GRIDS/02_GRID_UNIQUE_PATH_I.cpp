/*
#GRID UNIQUE PATH I

LINK :- https://leetcode.com/problems/unique-paths/description/
*/

#include<bits/stdc++.h>
using namespace std;


//first explore right, and then down, if it goes out of boudn then simply return 0, or if it reaches last cell of matrix, then simply return 1
//TIME COMPLEXITY :- O(2^(M+N));
//SPACE COMPLEXITY :- O(M+N);
class Solution_recursion {
public:
    int solve(int m, int n, int i, int j) {
        // Base case: out of bounds
        if (i >= m || j >= n) return 0;

        // Base case: reached destination
        if (i == m - 1 && j == n - 1) return 1;

        // Recursive calls: down and right
        return solve(m, n, i + 1, j) + solve(m, n, i, j + 1);
    }

    int uniquePaths(int m, int n) {
        return solve(m, n, 0, 0);
    }
};

//TIME COMPLEXITY :- O(N*M);
//SPACE COMPLEXITY :- O(N*M) DP + O(M+N) RECURSION DEPTH STACK
class Solution_memoization {
public:
    int solve(int m, int n, int start, int end, vector<vector<int>>& dp) {
        if (start >= m || end >= n) return 0;

        if (start == m - 1 && end == n - 1) return 1;

        if (dp[start][end] != -1) return dp[start][end];

        return dp[start][end] = solve(m, n, start + 1, end, dp) + solve(m, n, start, end + 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, 0, 0, dp);
    }
};

//time complexity :- O(m*n);
//space comlexity :- O(m*n);
class Solution_tabulation {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));   //think like that, you have only one row and n column, then there is only 1 possible way, and same for vice verse

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    int m = 3, n = 7;
    Solution_tabulation obj;
    cout << obj.uniquePaths(m, n);
    return 0;
}