/*
#GRID UNIQUE PATH II

LINK- https://leetcode.com/problems/unique-paths-ii/
*/

#include<bits/stdc++.h>
using namespace std;

//just care of the paths where stone is present other wise same as grid unique path I
//TIME COMPLEXITY :- O(2^(N+M))
//SPACE COMEPLXTY :- O(M+N);    //DUE TO RECURSION STACK DEPTH
class Solution_recursive {
public:
    int solve(vector<vector<int>>& grid, int start, int end) {
        if (start == 0 && end == 0) {
            return (grid[start][end] != 1) ? 1 : 0;
        }

        if (start < 0 || end < 0 || grid[start][end] == 1) {
            return 0;
        }

        return solve(grid, start, end - 1) + solve(grid, start - 1, end);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        return solve(grid, rows - 1, cols - 1);
    }
};


//time complexity :- O(m*n)
//space complexity :- O(m*n) + O(m+n)
class Solution_memoization {
public:
    int solve(vector<vector<int>>& grid, int start, int end, vector<vector<int>>& dp) {
        if (start == 0 && end == 0) {
            return (grid[start][end] != 1) ? 1 : 0;
        }

        if (start < 0 || end < 0 || grid[start][end] == 1) {
            return 0;
        }

        if (dp[start][end] != -1) return dp[start][end];

        return dp[start][end] = solve(grid, start, end - 1, dp) + solve(grid, start - 1, end, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return solve(grid, rows - 1, cols - 1, dp);
    }
};

//time complexity :- O(m*n)
//space complexity :- O(m*n)
class Solution_tabulation {
public:
    int uniquePathsWithObstacles_tabulation(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        dp[0][0] = (grid[0][0] != 1) ? 1 : 0;

        for (int j = 1; j < cols; j++) {
            dp[0][j] = (dp[0][j - 1] != 0 && grid[0][j] != 1) ? 1 : 0;
        }

        for (int i = 1; i < rows; i++) {
            dp[i][0] = (dp[i - 1][0] != 0 && grid[i][0] != 1) ? 1 : 0;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

int main() {
    vector<vector<int>> grid = { {0,0,0}, {0,1,0}, {0,0,0} };
    Solution_tabulation obj;
    cout << obj.uniquePathsWithObstacles_tabulation(grid);
    return 0;
}