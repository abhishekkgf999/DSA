/*
#MINIMUM FALLING PATH SUM

LINK:- https://leetcode.com/problems/minimum-falling-path-sum/
*/

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY :- O(N.M^2) 
/*
States: The recursive function solve(row, start, end) has N possible values for row, M possible values for start, and M possible values for end. This leads to O(N⋅M⋅M)=O(N⋅M^2) potential unique calls (or states).
*/
class Solution_recursive {
public:
    int solve(vector<vector<int>>& matrix, int row, int start, int end) {
        if (row == matrix.size()) {
            return 0;
        }

        int mini = INT_MAX;
        for (int j = start; j <= end; j++) {
            int temp_Start = (j - 1 < 0) ? 0 : j - 1;
            int temp_End = (j + 1 == matrix[row].size()) ? matrix[row].size() - 1 : j + 1;

            int temp = matrix[row][j] + solve(matrix, row + 1, temp_Start, temp_End);

            mini = min(temp, mini);
        }

        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return solve(matrix, 0, 0, matrix[0].size() - 1);
    }
};

//time complexity :- O(n.m)
//space complexity :- O(n.m)
class Solution_memoization {
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (col < 0 || col >= m) return 1e9;

        if (row == n - 1) return matrix[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int down = matrix[row][col] + solve(matrix, row + 1, col, dp);
        int leftDiag = matrix[row][col] + solve(matrix, row + 1, col - 1, dp);
        int rightDiag = matrix[row][col] + solve(matrix, row + 1, col + 1, dp);

        return dp[row][col] = min({ down, leftDiag, rightDiag });
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int mini = INT_MAX;
        for (int col = 0; col < m; col++) {
            mini = min(mini, solve(matrix, 0, col, dp));
        }

        return mini;
    }
};


//time complexity :- O(n.m)
//space comeplxity :- O(n.m)
class Solution_tabulation {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int down = dp[i + 1][j];
                int leftDiag = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int rightDiag = (j < m - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({ down, leftDiag, rightDiag });
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[0][j]);
        }

        return mini;
    }
};


int main() {
    vector<vector<int>> matrix = { {2,1,3}, {6,5,4}, {7,8,9} };
    Solution_tabulation obj;
    cout << obj.minFallingPathSum(matrix);
    return 0;
}