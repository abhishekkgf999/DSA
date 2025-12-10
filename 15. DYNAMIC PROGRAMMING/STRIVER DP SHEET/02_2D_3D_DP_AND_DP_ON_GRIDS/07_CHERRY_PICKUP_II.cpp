/*
#CHERRY PICKUP II   => IMP QUESTION

LINK :- https://leetcode.com/problems/cherry-pickup-ii/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_recursion {
public:
    int n, m;

    int solve(vector<vector<int>>& grid, int row, int col1, int col2) {
        // Base case: if either robot goes out of bounds
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1e9;

        // If we've reached the last row
        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        int maxCherries = -1e9;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int nextCol1 = col1 + d1;
                int nextCol2 = col2 + d2;
                int cherriesCollected;

                if (col1 == col2)
                    cherriesCollected = grid[row][col1];
                else
                    cherriesCollected = grid[row][col1] + grid[row][col2];

                cherriesCollected += solve(grid, row + 1, nextCol1, nextCol2);
                maxCherries = max(maxCherries, cherriesCollected);
            }
        }

        return maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        return solve(grid, 0, 0, m - 1);
    }
};

class Solution_memoization {
public:
    int n, m;

    int solve(vector<vector<int>>& grid, int row, int col1, int col2, unordered_map<string, int>& dp) {

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1e9;

        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        string key = to_string(row) + "_" + to_string(col1) + "_" + to_string(col2);

        if (dp.find(key) != dp.end()) return dp[key];

        int maxCherries = -1e9;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int nextCol1 = col1 + d1;
                int nextCol2 = col2 + d2;
                int cherriesCollected;

                if (col1 == col2)
                    cherriesCollected = grid[row][col1];
                else
                    cherriesCollected = grid[row][col1] + grid[row][col2];

                cherriesCollected += solve(grid, row + 1, nextCol1, nextCol2, dp);
                maxCherries = max(maxCherries, cherriesCollected);
            }
        }

        return dp[key] = maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        unordered_map<string, int> dp;
        return solve(grid, 0, 0, m - 1, dp);
    }
};


//time complexity :- O(9.N.M^2)
//space comeplxtity :- O(n.m^2)
class Solution_tabulation {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Base case: last row
        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = 0; col2 < m; col2++) {
                if (col1 == col2)
                    dp[n - 1][col1][col2] = grid[n - 1][col1];
                else
                    dp[n - 1][col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
            }
        }

        // Bottom-up DP
        for (int row = n - 2; row >= 0; row--) {
            for (int col1 = 0; col1 < m; col1++) {
                for (int col2 = 0; col2 < m; col2++) {
                    int maxCherries = 0;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int newCol1 = col1 + d1;
                            int newCol2 = col2 + d2;

                            if (newCol1 >= 0 && newCol1 < m && newCol2 >= 0 && newCol2 < m) {
                                maxCherries = max(maxCherries, dp[row + 1][newCol1][newCol2]);
                            }
                        }
                    }

                    if (col1 == col2)
                        dp[row][col1][col2] = grid[row][col1] + maxCherries;
                    else
                        dp[row][col1][col2] = grid[row][col1] + grid[row][col2] + maxCherries;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};


int main() {
    Solution_tabulation obj;
    vector<vector<int>> grid = { {3,1,1},{2,5,1},{1,5,5},{2,1,1} };
    cout << obj.cherryPickup(grid);
    return 0;
}