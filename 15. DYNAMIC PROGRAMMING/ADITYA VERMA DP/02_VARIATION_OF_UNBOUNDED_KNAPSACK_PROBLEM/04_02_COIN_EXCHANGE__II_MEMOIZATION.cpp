/*
#COIN EXCHANGE I (RECURSION)

LINK:- https://leetcode.com/problems/coin-change-ii/description/

*/

/*
INTUITION:
1. We use recursion with memoization to count the number of ways to form the target amount using the given coins.
2. A 2D dp table of size (n+1) x (amount+1) is used to store the results of subproblems, where dp[n][amount] represents the number of ways to make up
   'amount' using the first 'n' coins.
3. If a subproblem has already been solved, we return its stored value to avoid redundant calculations.
4. Otherwise, we compute it, store it in dp, and return the result.

APPROACH:
1. Base Case:
   - If only one coin is left (n == 1), we check if the amount is divisible by coins[0].
     If yes, we can form the amount using just this coin repeatedly → return 1;
     otherwise, it's not possible → return 0.

2. Choice 1: Take the current coin (if its value ≤ amount):
   - Recurse with the same coin and reduced amount.

3. Choice 2: Skip the current coin:
   - Recurse with the remaining coins (n - 1) and the same amount.

4. Store and return the sum of both choices in dp[n][amount].

COMPLEXITY:
- Time: O(n * amount), because we solve each subproblem only once.
- Space: O(n * amount) for the dp table + O(n + amount) recursion stack in the worst case.
*/



#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int solve(int amount, vector<int>& coins, int n, vector<vector<int>>& dp) {
        if (n == 1) {
            if (amount % coins[0] == 0) return 1;
            return 0;
        }

        if (dp[n][amount] != -1) return dp[n][amount];

        int take = 0;
        if (coins[n - 1] <= amount) {
            take += solve(amount - coins[n - 1], coins, n, dp);
        }

        int notTake = solve(amount, coins, n - 1, dp);

        return dp[n][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(amount, coins, n, dp);
    }
};

class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) return (amount % coins[0] == 0);

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = solve(ind - 1, amount, coins, dp);
        int take = 0;
        if (coins[ind] <= amount)
            take = solve(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};


int main()
{
    vector<int> coins = { 1, 2, 5 };
    int amount = 5;
    Solution obj;
    cout << obj.change(amount, coins);
    return 0;
}