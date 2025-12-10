/*
#TRIANGLE

LINK:- https://leetcode.com/problems/triangle/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(2^N)
//SPACE COMPLEXITY :- O(N+M) -> DUE TO RECURSION STACK DEPTH
class Solution_recursion {
public:
    int solve(vector<vector<int>>& triangle, int row, int last) {
        if (row == triangle.size()) {
            return 0;
        }

        int explore1 = triangle[row][last] + solve(triangle, row + 1, last);

        int explore2 = triangle[row][last] + solve(triangle, row + 1, last + 1);

        return min(explore1, explore2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
};

//time complexity :- O(n^2)
//space complexity :- o(n^2)   
class Solution_memoization {
public:
    int solve(vector<vector<int>>& triangle, int row, int last,
        vector<vector<int>>& dp) {
        if (row == triangle.size()) {
            return 0;
        }

        if (dp[row][last] != -1)
            return dp[row][last];

        int explore1 = triangle[row][last] + solve(triangle, row + 1, last, dp);

        int explore2 = triangle[row][last] + solve(triangle, row + 1, last + 1, dp);

        return dp[row][last] = min(explore1, explore2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }

        return solve(triangle, 0, 0, dp);
    }
};


//TIME COMPLEXITY :- O(N^2)
//SPACE COMPLEXITY :- O(N^2)
class Solution_tabulation {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Create a DP table with same dimensions as triangle
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: copy the last row of triangle into dp
        for (int j = 0; j < triangle[n - 1].size(); j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Fill the DP table from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        // The answer is in the top cell
        return dp[0][0];
    }
};


int main() {
    vector<vector<int>> triangle = { {2}, {3,4}, {6,5,7}, {4,1,8,3} };
    Solution_tabulation obj;
    cout << obj.minimumTotal(triangle);

    return 0;
}