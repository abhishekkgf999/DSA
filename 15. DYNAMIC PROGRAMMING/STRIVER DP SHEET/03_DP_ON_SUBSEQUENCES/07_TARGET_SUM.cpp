/*
#TARGET SUM

LINK :- https://leetcode.com/problems/target-sum/

*/

#include<bits/stdc++.h>
using namespace std;


/*
THINK LIKE THAT, WE SEPARATE +VE ELEMENTS IN S1, -VE ELEMENTS IN S2;

S1 - S2 = GIVEN TARGET

S1 + S2 = TOTAL

2S1 = (TOTAL + TARGET)

S1 = (TOTAL+TARGET)/2

WE HAVE TO FIND HOW MANY WAYS WE CAN FOR S1, THAT IS PRETTY STANDARD QUESTION

*/
class Solution_recursive {
public:
    int solve(vector<int>& nums, int required, int n) {
        if (n == 0) {
            return (required == 0) ? 1 : 0;
        }

        if (required < 0)
            return 0;

        return solve(nums, required - nums[n - 1], n - 1) + solve(nums, required, n - 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if ((total_sum + target) % 2 != 0 || (total_sum < abs(target)))
            return 0;

        int required = (total_sum + target) / 2;
        int n = nums.size();

        return solve(nums, required, n);
    }
};

class Solution_memoization {
public:
    int solve(vector<int>& nums, int required, int n, vector<vector<int>>& dp) {
        if (n == 0) {
            return (required == 0) ? 1 : 0;
        }

        if (required < 0)
            return 0;

        if (dp[n][required] != -1)
            return dp[n][required];

        return dp[n][required] =
            solve(nums, required - nums[n - 1], n - 1, dp) +
            solve(nums, required, n - 1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if ((total_sum + target) % 2 != 0 || (total_sum < abs(target)))
            return 0;

        int required = (total_sum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(required + 1, -1));
        return solve(nums, required, n, dp);
    }
};


class Solution_tabulation {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if ((total_sum + target) % 2 != 0 || (total_sum < abs(target))) return 0;

        int required = (total_sum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(required + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= required; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][required];
    }
};

int main() {
    vector<int> nums = { 1,1,1,1,1 };
    int target = 3;

    Solution_tabulation obj;
    cout << obj.findTargetSumWays(nums, target);
    return 0;
}