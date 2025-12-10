/*
#BEST TIME TO BUY AND SELL STOCK IV

LINK :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

*/


#include<bits/stdc++.h>
using namespace std;

//just small change, int best time to buy and sell stock III, there is limit of 2 transaction, but here is limit set to k transaction, that's it, same logic and same code
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int count = 0; count < k; count++) {
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
    int k = 2;
    vector<int> prices = { 2,4,1 };
    Solution obj;
    cout << obj.maxProfit(k, prices);
    return 0;
}