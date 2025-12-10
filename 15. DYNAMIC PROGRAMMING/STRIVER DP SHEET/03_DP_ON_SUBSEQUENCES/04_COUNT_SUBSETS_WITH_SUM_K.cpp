/*
#COUNT SUBSETS WITH SUM K

LINK:- https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/


#include<bits/stdc++.h>
using namespace std;

class Solution_recursion {
public:
    int solve(vector<int>& arr, int target, int n) {
        if (n == 0) {
            if (target == 0)return 1;
            return 0;
        }

        if (n <= 0 || target < 0) return 0;

        return solve(arr, target - arr[n - 1], n - 1) + solve(arr, target, n - 1);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return solve(arr, target, n);
    }
};


class Solution_memoization {
public:
    int solve(vector<int>& arr, int n, int target, vector<vector<int>>& dp) {
        if (n == 0) {
            if (target == 0) return 1;
            return 0;
        }

        if (target < 0) return 0;

        if (dp[n][target] != -1) return dp[n][target];

        return dp[n][target] = solve(arr, n - 1, target - arr[n - 1], dp) + solve(arr, n - 1, target, dp);

    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(arr, n, target, dp);
    }
};


class Solution_tabulation {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    vector<int> arr = { 5, 2, 3, 10, 6, 8 };
    Solution_tabulation obj;
    cout << obj.perfectSum(arr, 10);
    return 0;
}