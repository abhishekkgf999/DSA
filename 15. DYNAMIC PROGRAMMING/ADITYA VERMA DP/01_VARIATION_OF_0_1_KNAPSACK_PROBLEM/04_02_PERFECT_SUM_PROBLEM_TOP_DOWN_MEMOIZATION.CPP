/*
#PERFECT SUM PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1


***SIMILAR TO SUBSET SUM PROBLEM***

=> BUT HERE WE HAVE TO COUNT TOTAL NUMBER OF SUBSET HAVING TARGET SUM

=> IN THIS CODE, THERE IS MINOR CHANGE, WHEN "0" IS PRESNET IN OUR ARRAY, WE HAVE TO ENSURE THAT, FIRST WE TRAVERSE ENTIRE
   ARRAY AND THEN CHECK FOR THE SUBSET SUM EQUAL TO TARGET OR NOT, IF EQUAL THEN INCREASE THE COUNT
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n, int target, vector<vector<int>>& dp) {
    if (n == 0) {
        if (target == 0)
            return 1;
        return 0;
    }

    if (target < 0)
        return 0;

    if (dp[n][target] != -1)
        return dp[n][target];

    return dp[n][target] = solve(arr, n - 1, target - arr[n - 1], dp) +
                           solve(arr, n - 1, target, dp);
}
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    return solve(arr, n, target, dp);
}

int main(){
    vector<int> arr = {0, 10, 0};
    int target = 0;
    cout<<perfectSum(arr, target);
    return 0;
}