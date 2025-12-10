/*
#NINJA TRAINING

LINK:- https://www.geeksforgeeks.org/problems/geeks-training/1
*/


#include<bits/stdc++.h>
using namespace std;

//we will maintain a previous(last) taken credit index, so that we will not take it again in next iteration
//TIME COMPLEXITY :- O(N * M^N)
//SPACE COMPLEXITY :- O(N) -> Due to the recursion stack depth.
class Solution_recursive {
public:
    int solve(vector<vector<int>>& arr, int row, int last) {
        if (row == 0) return 0;

        int max_cred = INT_MIN;
        for (int j = 0; j < arr[row - 1].size(); j++) {
            if (j == last) continue;
            int temp = arr[row - 1][j] + solve(arr, row - 1, j);
            max_cred = max(max_cred, temp);
        }

        return max_cred;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int rows = arr.size();

        return solve(arr, rows, -1);
    }
};

//TIME COMPLEXITY :- O(N * M^2)
//SPACE COMPEXITY :- O(N.M) DP + O(N) Due to the recursion stack depth.

class Solution_memoization {
public:
    int solve(vector<vector<int>>& arr, int row, int last, vector<vector<int>>& dp) {

        if (row == 0) return 0;


        if (dp[row][last] != -1) return dp[row][last];

        int max_cred = INT_MIN;

        for (int j = 0; j < arr[row - 1].size(); j++) {

            if (j == last) continue;

            int temp = arr[row - 1][j] + solve(arr, row - 1, j, dp);
            max_cred = max(max_cred, temp);
        }

        return dp[row][last] = max_cred;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        int rows = arr.size();
        if (rows == 0) return 0;
        int cols = arr[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));

        return solve(arr, rows, cols, dp);
    }
};

//TABULATION
//TIME COMPLEXITY :- O(N * M^2)
//SPACE COMPLEXITY :- O(N*M)
class Solution_tabulation {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int rows = arr.size();
        if (rows == 0) return 0;

        int cols = arr[0].size();
        if (cols == 0) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols));

        for (int j = 0; j < cols; j++) {
            dp[0][j] = arr[0][j];
        }


        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                int max_prev_row_points = INT_MIN;

                for (int prev_j = 0; prev_j < cols; ++prev_j) {
                    if (prev_j == j) {
                        continue;
                    }
                    max_prev_row_points = max(max_prev_row_points, dp[i - 1][prev_j]);
                }

                if (max_prev_row_points == INT_MIN) {
                    dp[i][j] = arr[i][j];
                }
                else {
                    dp[i][j] = arr[i][j] + max_prev_row_points;
                }
            }
        }

        int overall_max = INT_MIN;
        for (int j = 0; j < cols; j++) {
            overall_max = max(overall_max, dp[rows - 1][j]);
        }

        return overall_max;
    }
};


int main() {
    vector<vector<int>> arr = { {1,2,4}, {3,1,1}, {3,3,3} };
    Solution_tabulation obj;
    cout << obj.maximumPoints(arr);
    return 0;
}