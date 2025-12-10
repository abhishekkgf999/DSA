/*
#HOUSE ROBBER I

LINK :- https://leetcode.com/problems/house-robber/
*/

#include<bits/stdc++.h>
using namespace std;

//IF I CHOOSE A HOUSE TO ROB, THEN I WILL ADD THAT HOUSE PROFIT, AND JUMP TO ITS NEXT TO NEXT HOUSE
//IF I NOT CHOOES THAT HOUSE TO ROB, THEN I JUST SIMPLY TRY NEXT HOUSE
// TIME COMPLEXITY: O(2^N) -- exponential, due to branching at each index
// SPACE COMPLEXITY: O(N) -- due to recursion call stack
class Solution_recursion {
public:
    int solve(vector<int>& nums, int n) {
        if (n <= 0) return 0;

        if (n == 1) return nums[0];

        int take = nums[n - 1] + solve(nums, n - 2);

        int notTake = solve(nums, n - 1);

        return max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        return solve(nums, n);
    }
};


//TIME COMPLEXITY :- O(N);
//SPACE COMPLEXITY :- O(N) FOR DP + O(N) -> DUE TO RECURSION STACK DEPTH
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
        vector<int> dp(n + 1, -1);
        return solve(nums, n, dp);
    }
};

//TIME COMPLEXITY :- O(N);
//SPACE COMPLEXITY :- O(N) FOR DP 
class Solution_tabulation {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int take = nums[i] + dp[i - 2];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};


int main() {
    vector<int> nums = { 1,2,3,1 };
    Solution_tabulation obj;
    cout << obj.rob(nums);
    return 0;
}