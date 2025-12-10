/*
#BEST TIME TO BUY AND SELL STOCK WITH COOLDOWN

LINK:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

*/


#include<bits/stdc++.h>
using namespace std;

//just little change, after selling stock, move index to one more  (index+2), and all same logic as buy and sell stock
class Solution_memoization {
public:
    int solve(vector<int>& prices, bool canBuy, int index, vector<vector<int>>& dp) {
        if (index >= prices.size())return 0;

        if (dp[index][canBuy] != -1) return dp[index][canBuy];

        if (canBuy) {
            int buy = -prices[index] + solve(prices, false, index + 1, dp);
            int skip = solve(prices, true, index + 1, dp);
            return dp[index][canBuy] = max(buy, skip);
        }
        else {
            int sell = prices[index] + solve(prices, true, index + 2, dp);
            int skip = solve(prices, false, index + 1, dp);
            return dp[index][canBuy] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(prices, true, 0, dp);
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));     // n+2 to handle i+2 access

        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int buy = -prices[i] + dp[i + 1][0];
                    int skip = dp[i + 1][1];
                    dp[i][canBuy] = max(buy, skip);
                }
                else {
                    int sell = prices[i] + dp[i + 2][1];
                    int skip = dp[i + 1][0];
                    dp[i][canBuy] = max(sell, skip);
                }
            }
        }

        return dp[0][1];
    }
};

int main() {
    vector<int> prices = { 1,2,3,0,2 };
    Solution obj;
    cout << obj.maxProfit(prices);
    return 0;
}