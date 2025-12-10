/*
#FROG JUMP WITH K DISTANCE

LINK :- https://www.youtube.com/watch?v=Kmh3rhyEtB8


A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by
the frog to go from the 0th step to the (n-1)th step.
*/

/*
| Version      | Time Complexity | Space Complexity    |
| ------------ | --------------- | ------------------- |
| Top-Down DP  | `O(n * k)`      | `O(n)` (DP + stack) |
| Bottom-Up DP | `O(n * k)`      | `O(n)`              |

*/

#include<bits/stdc++.h>
using namespace std;

class Solution_memoization {
public:
    int solve(vector<int>& heights, int k, int ind, vector<int>& dp) {
        if (ind == 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int min_steps = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (ind - j >= 0) {
                int jump = solve(heights, k, ind - j, dp) + abs(heights[ind] - heights[ind - j]);
                min_steps = min(jump, min_steps);
            }
        }

        return dp[ind] = min_steps;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(heights, k, n - 1, dp);
    }
};

class Solution_tabulation {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            int min_steps = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    min_steps = min(min_steps, jump);
                }
            }
            dp[i] = min_steps;
        }

        return dp[n - 1];
    }
};


int main() {
    Solution_memoization obj;
    vector<int> heights = { 10, 5, 20, 0, 15 };
    int k = 2;
    cout << obj.frogJump(heights, k);
    return 0;
}