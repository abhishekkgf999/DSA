/*
#SUBSET SUM EQUAL TO TARGET

LINK:- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

#include<bits/stdc++.h>
using namespace std;

//TAKE - NOT TAKE LOGIC,  O/1 KNAPSACK PATTERN
//TIME COMPLEXITY :- O(2^N)
//SPACE COMPLEXITY :- O(N) -> DUE TO RECURSION STACK DEPTH
class Solution_recursion {
public:
    bool solve(vector<int>& arr, int n, int sum) {
        if (n == 0) {
            if (sum == 0) return true;
            return false;
        }

        if (sum < 0)return false;

        return solve(arr, n - 1, sum - arr[n - 1]) || solve(arr, n - 1, sum);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();

        return solve(arr, n, sum);
    }
};

//TIME COMPLEXITY :- O(N*SUM)
//SPACE COMPLEXITY :- O(N*SUM) + O(N)
class Solution_memoization {
public:
    bool solve(vector<int>& arr, int sum, int n, vector<vector<bool>>& dp) {
        if (sum == 0) {
            return true;
        }

        if (n == 0 || sum < 0) {
            return false;
        }

        if (dp[n][sum] != false) return dp[n][sum];

        return dp[n][sum] = solve(arr, sum - arr[n - 1], n - 1, dp) || solve(arr, sum, n - 1, dp);

    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        return solve(arr, sum, n, dp);
    }
};

//TIME COMPLEXITY :- O(N*SUM)
//SPACE COMPLEXITY :- O(N*SUM)
class Solution_tabulation {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j >= arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }
};



int main() {
    vector<int> arr = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    Solution_tabulation obj;
    cout << obj.isSubsetSum(arr, sum);
    return 0;
}