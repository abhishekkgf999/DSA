/*
#SUBSET SUM PROBLEM (memoization -> top-down approach)

LINK:- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if a subset with the given sum exists
//TIME COMPLEXITY:- O(N*SUM)
//SPACE COMPLEXITY:- O(N*SUM) + O(N) -> DP TABLE + RECURSION STACK
bool solve(vector<int>& arr, int sum, int n, vector<vector<bool>>& dp) {
    // Base Case 1: If sum becomes 0, a valid subset has been found
    if (sum == 0) {
        return true;
    }

    // Base Case 2: If no elements remain or sum becomes negative, subset not possible
    if (n == 0 || sum < 0) {
        return false;
    }

    // If the subproblem result is already computed, return cached value (Memoization)
    if (dp[n][sum] != false) {
        return dp[n][sum];
    }

    // Two choices: 
    // 1. Include the current element in the subset and check remaining sum
    // 2. Exclude the current element and check if subset is possible with remaining elements
    return dp[n][sum] = solve(arr, sum - arr[n - 1], n - 1, dp) || solve(arr, sum, n - 1, dp);
}

// Driver function to set up memoization table and start recursion
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();

    // Create a DP table to store subproblem solutions
    // Rows represent number of elements considered (0 to n)
    // Columns represent possible sum values (0 to sum)
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    return solve(arr, sum, n, dp);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2}; // Input array containing numbers
    int sum = 9; // Desired subset sum

    // Output whether subset with given sum exists (1 for true, 0 for false)
    cout << isSubsetSum(arr, sum) << endl;

    return 0;
}