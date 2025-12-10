/*
#FROG JUMP

LINK :- https://www.geeksforgeeks.org/problems/geek-jump/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_recursive {
public:
    int solve(vector<int>& height, int n) {
        if (n <= 1) return 0;

        int cost1 = INT_MAX;
        if (n - 2 >= 0) {
            cost1 = abs(height[n - 1] - height[n - 2]) + solve(height, n - 1);
        }

        int cost2 = INT_MAX;
        if (n - 3 >= 0) {
            cost2 = abs(height[n - 1] - height[n - 3]) + solve(height, n - 2);
        }

        return min(cost1, cost2);
    }
    int minCost(vector<int>& height) {
        int n = height.size();

        return solve(height, n);
    }
};

class Solution_memoization {
public:
    int solve(vector<int>& height, int n, vector<int>& dp) {
        if (n <= 1) return 0;

        if (dp[n] != -1) return dp[n];

        int cost1 = INT_MAX;
        if (n - 2 >= 0) {
            cost1 = abs(height[n - 1] - height[n - 2]) + solve(height, n - 1, dp);
        }

        int cost2 = INT_MAX;
        if (n - 3 >= 0) {
            cost2 = abs(height[n - 1] - height[n - 3]) + solve(height, n - 2, dp);
        }

        return dp[n] = min(cost1, cost2);
    }
    int minCost(vector<int>& height) {
        int n = height.size();

        vector<int> dp(n + 1, -1);

        return solve(height, n, dp);
    }
};

class Solution_tabulation {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            int cost1 = dp[i - 1] + abs(height[i] - height[i - 1]);

            int cost2 = INT_MAX;
            if (i > 1) {
                cost2 = dp[i - 2] + abs(height[i] - height[i - 2]);
            }

            dp[i] = min(cost1, cost2);
        }

        return dp[n - 1];
    }
};

class Solution_tabulation_with_space_optimization {
public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();

        if (n == 0 || n == 1) return 0;

        int prev2 = 0;

        int prev1 = abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {
            int jumpOneCost = prev1 + abs(height[i] - height[i - 1]);

            int jumpTwoCost = prev2 + abs(height[i] - height[i - 2]);

            int curr = min(jumpOneCost, jumpTwoCost);

            prev2 = prev1;

            prev1 = curr;
        }

        return prev1;
    }
};


int main() {
    vector<int> height = { 20, 30, 40, 20 };
    Solution_tabulation obj;
    cout << obj.minCost(height);
    return 0;
}