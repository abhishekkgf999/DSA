/*
#COIN EXCHANGE I (RECURSION)

LINK:- https://leetcode.com/problems/coin-change/description/

*/

/*
INTUITION

- The goal is to find the minimum number of coins required to make up a given amount using the available coin denominations.
- At each step, we have two choices:
  1. Take the current coin (if it’s not larger than the remaining amount), and reduce the amount accordingly. We stay on the same coin since coins can be used unlimited times.
  2. Skip the current coin and move to the next smaller denomination.
- If only one coin is left (n == 1), we can only form the amount if it's divisible by that coin. Otherwise, it’s impossible.

APPROACH

1. Base Case:
   - When there's only one coin (n == 1), check if the amount is divisible by that coin:
     - If yes, we return the number of coins needed.
     - If not, return -1 to indicate it's not possible.

2. Recursive Choices:
   - Take the current coin:
     - Only proceed if the coin value is ≤ remaining amount.
     - Recurse with reduced amount and same coin count.
     - Add 1 to the result if it's a valid path.
   - Skip the current coin:
     - Recurse with one less coin (n - 1) and same amount.

3. Result:
   - If both paths are invalid, return -1.
   - If only one path is valid, return that.
   - If both are valid, return the minimum of the two.

COMPLEXITY

- Time: O(2^n), since every amount and coin index leads to two recursive calls (no memoization).
- Space: O(n + amount) due to the recursion stack depth.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (n == 1) {
            return (amount % coins[0] == 0) ? amount / coins[0] : -1;
        }


        if (dp[n][amount] != -2)
            return dp[n][amount];

        int take = INT_MAX;
        if (coins[n - 1] <= amount) {
            int res = solve(coins, amount - coins[n - 1], n, dp);
            if (res != -1)
                take = 1 + res;
        }

        int notTake = solve(coins, amount, n - 1, dp);
        if (take == INT_MAX && notTake == -1) return dp[n][amount] = -1;

        if (take == INT_MAX) return dp[n][amount] = notTake;

        if (notTake == -1) return dp[n][amount] = take;

        return dp[n][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -2));
        return solve(coins, amount, n, dp);
    }
};

int main() {
    vector<int> coins = { 1,2,5 };
    Solution obj;
    cout << obj.coinChange(coins, 11);
    return 0;
}