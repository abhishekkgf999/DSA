#include<bits/stdc++.h>
using namespace std;

//METHOD - 1
int knapSack1(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=capacity; j++){
                if(j >= wt[i-1]){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][capacity];
        
    }

//METHOD - 2
//TIME COMPLEXITY :- O(N*W), SPACE COMPLEXITY :- O(N*W);
int unboundedKnapsack(int n, int W, vector<int>& weight, vector<int>& value) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
   
    // Base case: fill for index 0
    for (int w = 0; w <= W; ++w) {
        dp[0][w] = (w / weight[0]) * value[0];
    }

    for (int i = 1; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            int notPick = dp[i - 1][w];
            int pick = 0;
            if (weight[i] <= w)
                pick = value[i] + dp[i][w - weight[i]];
            dp[i][w] = max(pick, notPick);
        }
    }

    return dp[n - 1][W];
}


//METHOD - 3
//TIME COMPLEXITY :- O(N*W), SPACE COMPLEXITY :- O(W);
int knapSack2(vector<int>& value, vector<int>& weight, int W) {
        int n = weight.size();
        /*
        ✅ Goal: Use only 1D array dp[W+1]
    
        Why? Because at any time, we just need the current row values (not all rows). So we can reuse the same array
        */
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; ++i) {
            //we iterating with weight[i] because, weights < weight[i] will not be affected cause 
            //(lets weight[i] = 4 && we start looping from 0(default looping), then w-weight[i] = 0-4 will not be valid weight) 
            for (int w = weight[i]; w <= W; ++w) {
                dp[w] = max(dp[w], value[i] + dp[w - weight[i]]);
            }
        }

    }


int main(){
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};

    int capacity = 8;

    // cout<<knapSack1(val, wt, capacity);
    cout<<knapSack2(val, wt, capacity);
    return 0;
}