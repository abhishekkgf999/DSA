/*
#SUBSET SUM PROBLEM (memoization -> top-down approach)

LINK:- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

*/

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY:- O(N*SUM)
//SPACE COMPLEXITY:- O(N*SUM) -> DP TABLE 
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // Any subset can make sum 0 by excluding all elements
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            //if the currect element(i-1) is smaller of equal to sum(j)
            if (arr[i - 1] <= j) {
                // Either include arr[i-1] or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                // Cannot include arr[i-1] (too large), so just exclude it
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum]; // Final answer: whether sum can be formed using n elements
}

int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2}; // Input array containing numbers
    int sum = 9; // Desired subset sum

    // Output whether subset with given sum exists (1 for true, 0 for false)
    cout << isSubsetSum(arr, sum) << endl;
    return 0;
}