#include<bits/stdc++.h>
using namespace std;

//METHOD - 1
int solve1(vector<int>& val, vector<int>& wt, int capacity, int n,
          vector<vector<int>>& dp) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    if (wt[n - 1] <= capacity) {

        return dp[n][capacity] =
                   max(val[n - 1] + solve1(val, wt, capacity - wt[n - 1], n, dp),
                       solve1(val, wt, capacity, n - 1, dp));
    } else {
        return dp[n][capacity] = solve1(val, wt, capacity, n - 1, dp);
    }
}
int knapSack1(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(1000 + 1, -1));
    return solve1(val, wt, capacity, n, dp);
}

//METHOD - 2 
//TIME COMPLEXITY :- O(N*W), SPACE COMPLEXITY :- O(N*W) + dp+RECURSION STACK 
int solve2(vector<int> &val, vector<int> &wt, int capacity, int n, vector<vector<int>> &dp){
    if(n == 1){
        return (capacity/wt[n-1])*val[n-1];
    }

    if(dp[n][capacity] != -1) return dp[n][capacity];

    int take = 0;
    if(wt[n-1]<= capacity){
        take += val[n-1] + solve2(val, wt, capacity-wt[n-1], n, dp);
    }

    int not_take = solve2(val, wt, capacity, n-1, dp);

    return dp[n][capacity] = max(take, not_take);
}

int knapSack2(vector<int> &val, vector<int> &wt, int capacity){
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));
    return solve2(val, wt, capacity, n, dp);
}


int main(){
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};

    int capacity = 8;

    // cout<<knapSack1(val, wt, capacity);
    cout<<knapSack2(val, wt, capacity);
    return 0;
}