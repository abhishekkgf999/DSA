/*
# MATRIX CHAIN MULTIPLICATION (MCM) MEMOIZATION

LINK:- https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/


/*
MATRIX CHAIN MULTIPLICATION - MEMOIZATION (TOP-DOWN DP)

GOAL:
- Given dimensions of matrices in an array `arr` of size n,
  find the minimum number of scalar multiplications needed
  to multiply the sequence of matrices.

OBSERVATION:
- Each matrix Ai has dimensions arr[i-1] x arr[i]
- We try every possible place to split the chain (from i to j)
  and recursively compute the cost of multiplying the left and right parts,
  and add the cost of multiplying the results together.

RECURSIVE RELATION:
- solve(i, j) = min over k from i to j-1 of:
  solve(i, k) + solve(k+1, j) + arr[i-1] * arr[k] * arr[j]

BASE CASE:
- If i >= j, only one matrix or invalid, return 0

MEMOIZATION:
- Store the results in a 2D DP table `dp[i][j]` to avoid recomputation

TIME COMPLEXITY:
- O(n^3): 2D table of size n x n, with up to n iterations inside each call

SPACE COMPLEXITY:
- O(n^2) for dp table + O(n) recursion stack (can be optimized with tabulation)
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp_ans = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, temp_ans);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 1, arr.size() - 1, dp);
    }
};

int main() {
    vector<int> arr = { 2, 1, 3, 4 };
    Solution obj;
    cout << obj.matrixMultiplication(arr);
    return 0;
}