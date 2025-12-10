/*
#BEST TIME TO BUY AND SELL STOCK WITH TRASACTION FEE

LINK :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/

#include<bits/stdc++.h>
using namespace std;

//same logic as buy and sell stock, buty whenever we are selling, just subtract transaction fee from it, that's it
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int buy = -prices[index] + dp[index + 1][0];
                    int skip = dp[index + 1][1];
                    dp[index][canBuy] = max(buy, skip);
                }
                else {
                    int sell = prices[index] - fee + dp[index + 1][1];
                    int skip = dp[index + 1][0];
                    dp[index][canBuy] = max(sell, skip);
                }
            }
        }

        return dp[0][1];
    }
};

int main() {
    vector<int> prices = { 1,3,2,8,4,9 };
    int fee = 2;
    Solution obj;
    cout << obj.maxProfit(prices, fee);
    return 0;
}