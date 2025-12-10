
#include<bits/stdc++.h>
using namespace std;


/*
=> PROBLEM STATEMENT => SUM[S1] - SUM[S2] = DIFF;   --> eq(1)

=> ALSO, WE KNOW THAT => SUM[S1] + SUM[S2] = SUM[ARR];   --> eq(2)   

=> ADD BOTH EQUATIONS, WE GET 2*SUM[S1] = DIFF + SUM[ARR];

=> SUM[S1] = (DIFF + SUM[ARR])/2;

*/

int solve(vector<int> &arr, int start, int sum, int required, vector<vector<int>> &dp) {
    if (start == arr.size()) return sum == required ? 1 : 0;
    if (dp[start][sum] != -1) return dp[start][sum];
    int include = 0;
    if (sum + arr[start] <= required) {
        include = solve(arr, start + 1, sum + arr[start], required, dp);
    }
    int exclude = solve(arr, start + 1, sum, required, dp);
    return dp[start][sum] = include + exclude;
}

int minDifference(vector<int>& arr, int target) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    if ((target + total_sum) % 2 != 0 || target > total_sum) return 0;
    int required = (target + total_sum) / 2;
    vector<vector<int>> dp(arr.size() + 1, vector<int>(required + 1, -1));
    return solve(arr, 0, 0, required, dp);
}

int main(){
    vector<int> arr = {1, 1, 2, 3};
    // vector<int> arr2= {-36, 36};
    cout<<minDifference(arr, 1);
    return 0;
}