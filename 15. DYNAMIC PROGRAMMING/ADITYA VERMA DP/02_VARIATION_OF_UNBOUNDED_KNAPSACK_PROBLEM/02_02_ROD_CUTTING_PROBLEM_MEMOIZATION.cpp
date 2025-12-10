/*
#ROD CUTTING PROBLEM (TOP-DOWN MEMOIZATION)

LINK:- https://www.geeksforgeeks.org/problems/rod-cutting0840/1

*/

/*
# INTUITION
1. Since both the rod length (L) and piece index (n) vary across recursive calls, we need a 2D DP table to cache intermediate results.
2. The idea is to store and reuse results for each (n, L) state to avoid redundant calculations and reduce time complexity.

# APPROACH
1. Create a 2D DP array of size (n + 1) × (L + 1), initialized with -1:
   vector<vector<int>> dp(n + 1, vector<int>(L + 1, -1));

2. During recursion, store results in dp[n][L] whenever a subproblem returns,
   so that future calls with the same inputs can retrieve the answer in constant time.

# COMPLEXITY
- Time Complexity: O(n × L), since we compute each (n, L) pair at most once
- Space Complexity: O(n × L) for the DP table + O(n + L) for recursion stack
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& price, int L, int n, vector<vector<int>> &dp) {
    if (n == 1) return price[0] * L;
        

    if(dp[n][L] != -1) return dp[n][L];
    
    int take_that_piece = 0;
    if (n <= L) {
        take_that_piece = price[n - 1] + solve(price, L - n, n, dp);
    }

    int not_take_that_piece = solve(price, L, n - 1, dp);

    return dp[n][L] = max(take_that_piece, not_take_that_piece);
}
int cutRod(vector<int>& price) {
    // code here
    int L = price.size();
    int n = L;
    vector<vector<int>> dp(n+1, vector<int>(L+1, -1));
    return solve(price, L, n, dp);
}

int main(){
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutRod(price);
    return 0;
}