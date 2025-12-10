/*
# 0/1 KNAPSACK PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1



**0/1 Knapsack Code Explanation (Structured & Concise)**

1. **Problem Goal**
   Maximize total value without exceeding the knapsack capacity `W`, where each item can be chosen at most once.

2. **Parameters**

   * `W`: Maximum weight capacity of the knapsack
   * `val`: Array of item values
   * `wt`: Array of item weights
   * `n`: Number of items (`val.size()`)

3. **DP Table Definition**

   * `dp[i][j]`: Maximum value using the first `i` items with a knapsack capacity `j`
   * Dimensions: `(n+1) x (W+1)`

4. **Initialization**

   * Set `dp[0][j] = 0` and `dp[i][0] = 0` for all `i`, `j`
   * Meaning: With 0 items or 0 capacity, the max value is 0

5. **DP Transition Logic**
   Loop through each item (`i` from 1 to `n`)
   Loop through each weight capacity (`j` from 1 to `W`)

   * If `wt[i-1] <= j` (can include item):
     `dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j])`
   * Else (can't include item):
     `dp[i][j] = dp[i-1][j]`

6. **Result**

   * Return `dp[n][W]`, the maximum value with all items and full capacity

Let me know if you want this explained as comments inside the code.


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();  // Number of items
        
        // Create DP table: dp[i][j] stores max value for first i items with capacity j
        vector<vector<int>> dp(n+1, vector<int>(W+1));
        
        // Initialize first row and column to 0: no item or no capacity means 0 value
        //Consider recursive code for this, we are making first row and column to zero because we have base condition in recursion
        //that whenever there is no object, or weight of knapsack is 0, then the cost will be zero
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= W; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // Fill the DP table
        for(int i = 1; i <= n; i++) {           // Loop over items
            for(int j = 1; j <= W; j++) {       // Loop over capacities
                if(wt[i-1] <= j) {
                    // Include the item or skip it: take the max value
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
                } else {
                    // Can't include the item as it exceeds capacity
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // Final result: max value with all items and full capacity
        return dp[n][W];
    }
};


int main(){
    Solution obj;
    int W = 4; // Maximum weight capacity of the knapsack
    vector<int> val = {2, 3, 7, 3, 6, 1}; // Values of items
    vector<int> wt = {1, 3, 3, 4, 4, 10}; // Weights of items

    cout << obj.knapsack(W, val, wt); // Output the maximum value that can be obtained
    return 0;
}