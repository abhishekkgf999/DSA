/*
#COIN CHANGE I

LINK :- https://leetcode.com/problems/coin-change/description/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution_recursion {
public:
    int solve(vector<int>& coins, int amount, int n) {
        if (n == 1) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            }
            return -1;
        }

        int take = INT_MAX;
        if (coins[n - 1] <= amount) {
            int res = solve(coins, amount - coins[n - 1], n);
            if (res != -1) take = 1 + res;
        }

        int notTake = solve(coins, amount, n - 1);

        if (take == INT_MAX && notTake == -1) return -1;
        if (take == INT_MAX) return notTake;
        if (notTake == -1) return take;

        return min(take, notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        return solve(coins, amount, n);
    }
};

class Solution_memoization {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (n == 1) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            }

            return -1;
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


class Solution_tabulation {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
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
    int amount = 11;
    Solution_tabulation obj;
    cout << obj.coinChange(coins, amount);
    return 0;
}