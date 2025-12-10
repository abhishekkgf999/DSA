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

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        //inner loop from j = 1 to j = 0.
        //This ensures that all combinations, including those involving zero values contributing to a target of 0, 
        //are considered properly
        for (int j = 0; j <= target; j++) {
            if (arr[i - 1] <= j) {  //only that elemnet which is smaller than or equal to target
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            /*
            When arr[i-1] > j, the expression j - arr[i-1] becomes negative, and you're unknowingly accessing an 
            invalid index in dp[i-1][...]. That introduces incorrect values or even runtime errors in some environments.
            */
            // dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][target];
}

int main(){
    vector<int> arr = {0, 10, 0};
    int target = 0;
    cout<<perfectSum(arr, target);
    return 0;
}