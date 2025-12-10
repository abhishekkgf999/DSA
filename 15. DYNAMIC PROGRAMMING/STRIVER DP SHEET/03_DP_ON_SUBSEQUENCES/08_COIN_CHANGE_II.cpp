/*#COIN CHANGE II


LINK :- https://leetcode.com/problems/coin-change-ii/description/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution_recursion {
public:
    int solve(int amount, vector<int>& coins, int n) {
        if (n == 1) {
            if (amount % coins[0] == 0) return 1;
            return 0;
        }

        int take = 0;
        if (coins[n - 1] <= amount) {
            take += solve(amount - coins[n - 1], coins, n);
        }

        int notTake = solve(amount, coins, n - 1);

        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(amount, coins, n);
    }
};

class Solution_memoization {
public:
    int solve(int amount, vector<int>& coins, int n) {
        if (n == 1) {
            if (amount % coins[0] == 0) return 1;
            return 0;
        }

        int take = 0;
        if (coins[n - 1] <= amount) {
            take += solve(amount - coins[n - 1], coins, n);
        }

        int notTake = solve(amount, coins, n - 1);

        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(amount, coins, n);
    }
};

class Solution_tabulation {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) {
            dp[1][j] = (j % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                unsigned long long notTake = dp[i - 1][j];
                unsigned long long take = 0;
                if (coins[i - 1] <= j) {
                    take = dp[i][j - coins[i - 1]];
                }

                dp[i][j] = (take + notTake > INT_MAX) ? INT_MAX : take + notTake;
            }
        }

        return (int)(dp[n][amount]);

    }
};


int main() {
    vector<int> coins = { 1,2,5 };
    int amount = 5;
    Solution_tabulation obj;
    cout << obj.change(5, coins);
    return 0;
}