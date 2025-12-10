/*
#STOCK BUY AND SELL

LINK:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/
 

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION
//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(1)
int maxProfit(vector<int>& prices) {
    int ans = 0;
    for(int i = 0; i<prices.size(); i++){
        int ele = prices[i];
        int diff = 0;
        for(int j = i+1; j<prices.size(); j++){
            diff = ele - prices[j];
            if(diff < ans){
                ans = diff;
            }
        }
    }

    if(ans > 0) return 0;

    return -1*ans;
}

//OPTIMAL SOLUTION
//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
int maxProfit3(vector<int>& prices) {
    if (prices.empty()) return 0;

    int buy = prices[0];
    int ans = 0;

    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < buy) {
            buy = prices[i]; // Update the buy price if the current price is lower
        } else {
            int profit = prices[i] - buy; // Calculate the profit if selling at the current price
            ans = max(ans, profit); // Update the maximum profit
        }
    }

    return ans;
}

//MORE OPTIMAL SOLUTION
int maxProfit4(vector<int>& prices) {
    int min1 = prices[0];
    int maxprofit = 0;
    int n = prices.size();
    for(int i = 1; i<n; i++){
        int cost = prices[i] - min1;
        maxprofit = max(maxprofit, cost);
        min1 = min(min1, prices[i]);
    }
        
    return maxprofit;
}


int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<"Maximum profit we can achieve is:- "<<maxProfit4(prices);
    return 0;
}