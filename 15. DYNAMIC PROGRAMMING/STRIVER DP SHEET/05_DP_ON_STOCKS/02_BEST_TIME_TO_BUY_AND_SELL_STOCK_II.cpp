/*
#BEST TIME TO BUY AND SELL STOCK II

LINK:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/


#include<bits/stdc++.h>
using namespace std;

/*
→ At each day index, you can either:

    ↪ Buy the stock (if allowed).
    ↪ Sell the stock (if you already bought).
    ↪ Or skip the action and move to the next day.

→ The function solve(prices, index, canBuy, dp) does:

    ↪ If canBuy is true, two choices:
        ⇒ Buy the stock at current price and set canBuy = false.
        ⇒ Skip buying and move to the next day with canBuy = true.

    ↪ If canBuy is false, meaning we already bought the stock, we have:
        ⇒ Sell the stock at current price and set canBuy = true.
        ⇒ Skip selling and move to the next day with canBuy = false.

→ Base case:
    ↪ When index == prices.size(), return 0 because no days are left.

*/

class Solution_recursion {
public:
    int solve(vector<int>& prices, int index, bool canBuy) {
        if (index == prices.size()) return 0;

        if (canBuy) {

            int buy = -prices[index] + solve(prices, index + 1, false);
            int skip = solve(prices, index + 1, true);
            return max(buy, skip);
        }
        else {

            int sell = prices[index] + solve(prices, index + 1, true);
            int skip = solve(prices, index + 1, false);
            return max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, 0, true);
    }
};


class Solution_memoization {
public:
    int solve(vector<int>& prices, int index, bool canBuy, vector<vector<int>>& dp) {
        if (index == prices.size()) return 0;

        if (dp[index][canBuy] != -1)return dp[index][canBuy];

        if (canBuy) {
            int buy = -prices[index] + solve(prices, index + 1, false, dp);
            int skip = solve(prices, index + 1, true, dp);
            return dp[index][canBuy] = max(buy, skip);
        }
        else {

            int sell = prices[index] + solve(prices, index + 1, true, dp);
            int skip = solve(prices, index + 1, false, dp);
            return dp[index][canBuy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};

//time and space complexity :- O(n^2)
class Solution_tabulation {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[index][canBuy]

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int buy = -prices[index] + dp[index + 1][0];
                    int skip = dp[index + 1][1];
                    dp[index][canBuy] = max(buy, skip);
                }
                else {
                    int sell = prices[index] + dp[index + 1][1];
                    int skip = dp[index + 1][0];
                    dp[index][canBuy] = max(sell, skip);
                }
            }
        }

        return dp[0][1]; // Start at day 0 with ability to buy
    }
};


class Solution_tabulation_space_optimization {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int buy = -prices[index] + ahead[0];
                    int skip = ahead[1];
                    curr[canBuy] = max(buy, skip);
                }
                else {
                    int sell = prices[index] + ahead[1];
                    int skip = ahead[0];
                    curr[canBuy] = max(sell, skip);
                }
            }
            ahead = curr;
        }

        return ahead[1]; // Start at day 0 with ability to buy
    }
};


int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    Solution_tabulation_space_optimization obj;
    cout << obj.maxProfit(prices);
    return 0;
}