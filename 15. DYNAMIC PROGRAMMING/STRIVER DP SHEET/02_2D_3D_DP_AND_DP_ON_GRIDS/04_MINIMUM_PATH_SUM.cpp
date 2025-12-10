/*
#MINIMUM PATH SUM

LINK:- https://leetcode.com/problems/minimum-path-sum/
*/

#include<bits/stdc++.h>
using namespace std;

//time complexity :- O(2^(rows+cols))
//space complexity :- O(rows + cols) recursion stack depth
class Solution_recursion {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {

        if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        int right = solve(grid, i, j + 1);
        int down = solve(grid, i + 1, j);

        return grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid, 0, 0);
    }
};

//time complexity :- O(rows * cols)
//space complexity :- O(rows * cols) + O(rows+cols)
class Solution_memoization {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

        if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(grid, i, j + 1, dp);
        int down = solve(grid, i + 1, j, dp);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return solve(grid, 0, 0, dp);
    }
};


//time complexity :- O(rows * cols)
//space complexity :- O(rows * cols)
class Solution_tabulation {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = grid[0][0];

        for (int j = 1; j < cols; j++) {
            dp[0][j] += grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < rows; i++) {
            dp[i][0] += grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};


int main() {
    Solution_tabulation obj;
    vector<vector<int>> grid = { {1,3,1}, {1,5,1}, {4,2,1} };
    cout << obj.minPathSum(grid);
    return 0;
}