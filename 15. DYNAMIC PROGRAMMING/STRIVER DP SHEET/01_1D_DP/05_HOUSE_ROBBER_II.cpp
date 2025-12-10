/*
#HOUSE ROBBER II

LINK :- https://leetcode.com/problems/house-robber-ii/description/
*/

/*
Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to
rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem
has degenerated to the House Robber, which is already been solved.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution_memoization {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if (n <= 0) return 0;

        if (n == 1) return nums[0];

        if (dp[n] != -1) return dp[n];

        int take = nums[n - 1] + solve(nums, n - 2, dp);

        int notTake = solve(nums, n - 1, dp);

        return dp[n] = max(take, notTake);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp;
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        for (int i = 1; i < n; i++) {
            temp.push_back(nums[i]);
        }
        return max(solve(nums, n - 1, dp1), solve(temp, temp.size(), dp2));
    }
};

class Solution_tabulation {
public:
    int robLinear(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int temp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = temp;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> nums1(nums.begin(), nums.end() - 1); // exclude last
        vector<int> nums2(nums.begin() + 1, nums.end()); // exclude first

        return max(robLinear(nums1), robLinear(nums2));
    }
};


int main() {
    vector<int> nums = { 1,2,3,1 };
    Solution_memoization obj;
    cout << obj.rob(nums);
    return 0;
}