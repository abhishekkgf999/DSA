/*
#BEST TIME TO BUY AND SELL STOCK III

LINK:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

*/


#include<bits/stdc++.h>
using namespace std;

/*
Best Time to Buy and Sell Stock III - Human Logic:

You can do at most 2 complete transactions (buy-sell pairs).

Key insight: Track your state with 3 things:
1. Which day you're on
2. Can you buy? (true/false)
3. How many transactions completed? (0, 1, or 2)

Decision at each day:
- If you can buy: Either buy the stock (spend money, now you can't buy) OR skip this day
- If you can't buy (holding stock): Either sell it (earn money, complete 1 transaction, now you can buy again) OR keep holding

Base cases:
- Reached end of days → profit = 0
- Completed 2 transactions → profit = 0 (can't do more)

Algorithm: Try both options at each step, pick the maximum profit. Use memoization to avoid recalculating same scenarios.

Start: Day 0, can buy, 0 transactions completed.

*/

//time complexity :-  Time Complexity: O(n × 2 × 3) = O(n) and same for space complexity along with O(n) due to recursion stack
class Solution_memoization {
public:
    int solve(vector<int>& prices, int index, bool canBuy, int count, unordered_map<string, int>& dp) {
        if (index == prices.size()) return 0;

        if (count == 2) return 0;

        string key = to_string(index) + "_" + to_string(canBuy) + "_" + to_string(count);

        if (dp.find(key) != dp.end()) return dp[key];

        if (canBuy) {
            int buy = -prices[index] + solve(prices, index + 1, false, count, dp);
            int skip = solve(prices, index + 1, true, count, dp);
            return dp[key] = max(buy, skip);
        }
        else {
            int sell = prices[index] + solve(prices, index + 1, true, count + 1, dp);
            int skip = solve(prices, index + 1, false, count, dp);
            return dp[key] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        unordered_map<string, int> dp;
        return solve(prices, 0, true, 0, dp);
    }
};

/*
Logic behind dp[0][1][0]:

dp[i][canBuy][count] = maximum profit starting from day i, with ability to buy = canBuy, and count transactions already completed.

Breaking down dp[0][1][0]:
- 0 = start from day 0 (first day)
- 1 = canBuy = true (we can buy initially, don't own any stock)
- 0 = count = 0 (no transactions completed yet)

This represents: "What's the maximum profit I can get starting from the very beginning, when I'm allowed to buy, and haven't done any transactions yet?"

This is exactly what we want - the answer to the original problem starting from the initial state.
*/
class Solution_tabulation {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int count = 0; count < 2; count++) {
                    if (canBuy) {
                        int buy = -prices[i] + dp[i + 1][0][count];
                        int skip = dp[i + 1][1][count];
                        dp[i][canBuy][count] = max(buy, skip);
                    }
                    else {
                        int sell = prices[i] + dp[i + 1][1][count + 1];
                        int skip = dp[i + 1][0][count];
                        dp[i][canBuy][count] = max(sell, skip);
                    }
                }
            }
        }

        return dp[0][1][0];
    }
};

int main() {
    vector<int> prices = { 3,3,5,0,0,3,1,4 };
    Solution_memoization obj;
    cout << obj.maxProfit(prices);
    return 0;
}