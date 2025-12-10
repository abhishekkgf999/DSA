/*
#PARTITION EQUAL SUBSET SUM

LINK:- https://leetcode.com/problems/partition-equal-subset-sum/
*/


#include<bits/stdc++.h>
using namespace std;

//SAME AS 0/1 KNAPSACK PROBLEM, LITTLE CHANIGE IS THAT, IF THE SUM IS ODD WE CANNOT DIVIDE IN 2 PARTS, IF EVEN, THEN JUST FIND THE HALF OF THE TOTAL SUM
//TIME COMPLEXITY :- O(2^N);
//SPACE COMPLEXITY :- O(N) -> DUE TO RECURSION STACK DEPTH
class Solution_recursion {
public:
    bool solve(vector<int>& arr, int n, int sum) {
        if (n == 0) {
            if (sum == 0)
                return true;
            return false;
        }

        if (sum < 0)
            return false;

        return solve(arr, n - 1, sum - arr[n - 1]) || solve(arr, n - 1, sum);
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum & 1)
            return false;

        int to_find = total_sum / 2;

        int n = nums.size();

        return solve(nums, n, to_find);
    }
};


//TIME COMPLEXITY :- O(N*SUM)
//SPACE COMPLEXITY :- O(N*SUM) + O(N)
class Solution_memoization {
public:
    bool solve(vector<int>& arr, int n, int sum, vector<vector<bool>>& dp) {
        if (n == 0) {
            if (sum == 0) return true;
            return false;
        }

        if (sum < 0) return false;

        if (dp[n][sum] != false) return dp[n][sum];

        return dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1], dp) || solve(arr, n - 1, sum, dp);
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum & 1)
            return false;

        int to_find = total_sum / 2;

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(to_find + 1, false));

        return solve(nums, n, to_find, dp);
    }
};


//TIME COMPLEXITY :- O(N*SUM)
//SPACE COMPLEXITY :- O(N*SUM) 
class Solution_tabulation {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum & 1)
            return false;

        int to_find = total_sum / 2;

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(to_find + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= to_find; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][to_find];
    }
};



int main() {
    vector<int> nums = { 1,5,11,5 };
    Solution_recursion obj;
    cout << obj.canPartition(nums);
    return 0;
}