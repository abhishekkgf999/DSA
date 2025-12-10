/*
#TARGET SUM

LINK:- https://leetcode.com/problems/target-sum/

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int target, int n, vector<vector<int>> &dp, int offset) {
        if (target + offset < 0 || target + offset >= dp[0].size())
            return 0;

        if (n == 0) {
            return (target == 0) ? 1 : 0;
        }

        if(dp[n][target + offset] != -1) return dp[n][target + offset];

        int add = solve(nums, target - nums[n - 1], n - 1, dp, offset);
        int subtract = solve(nums, target + nums[n - 1], n - 1, dp, offset);

        return dp[n][target + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total_sum) return 0;

        int offset = total_sum;
        vector<vector<int>> dp(n + 1, vector<int>(2 * total_sum + 1, -1));

        return solve(nums, target, n, dp, offset);
    }

/*
***THIS PROBLEM IS ALSO DEDUCED INTO THE PREVIOUS PROBLEM OF :- COUNT THE NUMBER OF SUBSETS WITH GIVEN DIFFERENCE***

FOR EXAMPLE :- NUMS = [1,1,1,1,1], TARGET = 3

ONE OF ITS SOLUTION IS :- -1 + 1 + 1 + 1 + 1 = 3;

IN THE ABOVE SOLUTION, WE CAN DIVIDE THOSE NUMBER INTO 2 SETS, +(1, 1, 1, 1) AND -(1) {+GROUP, AND -GROUP}

=> AND WE HAVE TO JUST TO SET1 - SET2 = TARGET

=> 4-1 = 3 (== TARGET)
 */

int solve2(vector<int> &arr, int start, int sum, int required, vector<vector<int>> &dp) {
    if (start == arr.size()) return sum == required ? 1 : 0;
    if (dp[start][sum] != -1) return dp[start][sum];
    int include = 0;
    if (sum + arr[start] <= required) {
        include = solve2(arr, start + 1, sum + arr[start], required, dp);
    }
    int exclude = solve2(arr, start + 1, sum, required, dp);
    return dp[start][sum] = include + exclude;
}

int findTargetSumWays2(vector<int>& arr, int target) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    if ((target + total_sum) % 2 != 0 || target > total_sum) return 0;
    int required = (target + total_sum) / 2;
    vector<vector<int>> dp(arr.size() + 1, vector<int>(required + 1, -1));
    return solve2(arr, 0, 0, required, dp);
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout<<findTargetSumWays(nums, target);

    return 0;
}