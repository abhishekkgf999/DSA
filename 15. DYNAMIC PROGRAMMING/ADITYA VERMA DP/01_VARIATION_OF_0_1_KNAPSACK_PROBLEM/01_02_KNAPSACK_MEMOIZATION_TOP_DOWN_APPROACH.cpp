/*
# 0/1 KNAPSACK PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


### **Explanation: 0/1 Knapsack using Memoization (Top-Down DP)**

1. **Goal**
   Maximize value within weight capacity `W` using given items (each used at most once).

2. **Function Structure**

   * `knapsack(...)`: Initializes the DP table and starts recursion.
   * `ks(...)`: Recursive function that returns max value using first `n` items within capacity `W`.

3. **Base Case**
   If either `W == 0` or `n == 0`, return `0` (no capacity or items left).

4. **Memoization Check**
   If `dp[n][W] != -1`, return stored result to avoid recomputation.

5. **Decision Case**

   * If `wt[n-1] <= W`: item can be included.

     * Option 1: Include item → `val[n-1] + ks(W - wt[n-1], ...)`
     * Option 2: Exclude item → `ks(W, ...)`
     * Store and return the maximum of both.
   * Else: item too heavy → skip it.

6. **DP Table**
   2D vector `dp[n+1][W+1]` stores results of subproblems. Initialized to `-1`.

7. **Time Complexity**

   * `O(n * W)` due to memoization reducing repeated calls
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Recursive function to solve 0/1 Knapsack using memoization
    int ks(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp) {
        // Base case: if no items or capacity is 0, max value is 0
        if (n == 0 || W == 0) {
            return 0;
        }

        // If value already computed, return it (Memoization)
        if (dp[n][W] != -1) {
            return dp[n][W];
        }

        // If weight of current item <= current capacity, consider both: include or exclude the item
        if (wt[n - 1] <= W) {
            return dp[n][W] = max(
                val[n - 1] + ks(W - wt[n - 1], val, wt, n - 1, dp), // Include the item
                ks(W, val, wt, n - 1, dp)                           // Exclude the item
            );
        }else {
            // If item can't be included (too heavy), skip it
            return dp[n][W] = ks(W, val, wt, n - 1, dp);
        }

        // return dp[n][W]; // Return the stored result
    }

    // Driver function to set up dp table and call the recursive function
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size(); // Number of items
        // Create dp table of size (n+1) x (W+1), initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));  //ALWAYS INITIALIZE WITH INVALID ANSWER
        return ks(W, val, wt, n, dp);
    }
};

int main() {
    Solution obj;
    int W = 4; // Maximum weight capacity of the knapsack
    vector<int> val = {2, 3, 7, 3, 6, 1}; // Values of items
    vector<int> wt = {1, 3, 3, 4, 4, 10}; // Weights of items

    cout << obj.knapsack(W, val, wt); // Output the maximum value that can be obtained
    return 0;
}
