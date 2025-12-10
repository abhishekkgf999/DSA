/*
#UNBOUNDED KNAPSACK

LINK :- https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

*/

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution_recursion {
public:
    int solve(vector<int>& val, vector<int>& wt, int capacity, int n) {
        if (n == 0 || capacity == 0) {
            return 0;
        }

        if (wt[n - 1] <= capacity) {
            // int value =  max(val[n-1] + solve(val, wt, capacity-wt[n-1], n-1), val[n-1] + solve(val, wt, capacity-wt[n-1], n));

            return max(val[n - 1] + solve(val, wt, capacity - wt[n - 1], n), solve(val, wt, capacity, n - 1));
        }
        else {
            return solve(val, wt, capacity, n - 1);
        }

    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        return solve(val, wt, capacity, n);
    }
};

// User function Template for C++

class Solution_memoization {
public:
    int solve(vector<int>& val, vector<int>& wt, int capacity, int n, vector<vector<int>>& dp) {
        if (n == 0 || capacity == 0) {
            return 0;
        }

        if (dp[n][capacity] != -1) return dp[n][capacity];

        if (wt[n - 1] <= capacity) {
            // int value =  max(val[n-1] + solve(val, wt, capacity-wt[n-1], n-1), val[n-1] + solve(val, wt, capacity-wt[n-1], n));

            return dp[n][capacity] = max(val[n - 1] + solve(val, wt, capacity - wt[n - 1], n, dp), solve(val, wt, capacity, n - 1, dp));
        }
        else {
            return dp[n][capacity] = solve(val, wt, capacity, n - 1, dp);
        }

    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(1000 + 1, -1));
        return solve(val, wt, capacity, n, dp);
    }
};

// User function Template for C++

class Solution_tabulation {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (j >= wt[i - 1]) {
                    dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][capacity];

    }
};

int main() {
    vector<int> val = { 1,1 };
    vector<int> wt = { 2,1 };
    int capacity = 3;
    Solution_tabulation obj;
    cout << obj.knapSack(val, wt, capacity);
    return 0;
}