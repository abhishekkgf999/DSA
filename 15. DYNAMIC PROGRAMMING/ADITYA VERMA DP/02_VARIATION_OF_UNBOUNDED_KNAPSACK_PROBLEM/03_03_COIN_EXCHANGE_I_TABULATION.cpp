/*
#COIN EXCHANGE I (RECURSION)

LINK:- https://leetcode.com/problems/coin-change/description/

*/

/*
INTUITION

- We aim to find the **minimum number of coins** needed to make up a target amount using a given set of coin denominations.
- Since each coin can be used an unlimited number of times, we can choose either:
  1. **Skip** the current coin and rely on previous ones.
  2. **Take** the current coin (if it doesn’t exceed the current amount) and reduce the problem size accordingly.

APPROACH (Tabulation - Bottom-Up DP)

1. **DP Definition**:
   - Let `dp[i][j]` represent the minimum number of coins required to form amount `j` using the first `i` coins.

2. **Initialization**:
   - If the target amount `j` is 0, `dp[i][0] = 0` (0 coins needed to form amount 0).
   - All other values are initialized to `INT_MAX` to represent an unreachable state.

3. **DP Transition**:
   - For each coin `i` and amount `j`:
     - **Not Take**: Use the answer from the row above → `dp[i-1][j]`.
     - **Take**: If the current coin can be used (i.e., `coins[i-1] <= j`) and `dp[i][j - coins[i-1]]` is not `INT_MAX`, then:
       - Take = `1 + dp[i][j - coins[i-1]]`.
     - `dp[i][j]` is the minimum of the two options.

4. **Final Answer**:
   - If `dp[n][amount] == INT_MAX`, return `-1` (not possible to form amount).
   - Otherwise, return `dp[n][amount]`.

COMPLEXITY

- Time: O(n * amount) where `n` is the number of coins.
- Space: O(n * amount) for the 2D DP table.
- (Can be optimized to 1D if needed.)
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //- Using -1 to represent unreachable values in a min-coin-count problem adds confusion. Better to use INT_MAX as the sentinel and interpret it at the end.
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MAX;
                if (coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INT_MAX) {
                    take = 1 + dp[i][j - coins[i - 1]];
                }
                dp[i][j] = min(notTake, take);
            }
        }

        return (dp[n][amount] == INT_MAX) ? -1 : dp[n][amount];
    }
};

int main() {
    vector<int> coins = { 1,2,5 };
    Solution obj;
    cout << obj.coinChange(coins, 11);
    return 0;
}