
#include<bits/stdc++.h>
using namespace std;


/*
=> PROBLEM STATEMENT => SUM[S1] - SUM[S2] = DIFF;   --> eq(1)

=> ALSO, WE KNOW THAT => SUM[S1] + SUM[S2] = SUM[ARR];   --> eq(2)   

=> ADD BOTH EQUATIONS, WE GET 2*SUM[S1] = DIFF + SUM[ARR];

=> SUM[S1] = (DIFF + SUM[ARR])/2;

*/


int minDifference(vector<int>& arr, int target) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    if((total_sum + target)%2 != 0 || target > total_sum) return 0;

    int required = (total_sum + target)/2;

    int n = arr.size();

    vector<vector<int>> dp(n+1, vector<int>(required+1, 0));

    for(int i = 0; i<=n; i++) dp[i][0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=required; j++){
            if(j >= arr[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][required];
}

int main(){
    vector<int> arr = {1, 1, 2, 3};
    // vector<int> arr2= {-36, 36};
    cout<<minDifference(arr, 1);
    return 0;
}