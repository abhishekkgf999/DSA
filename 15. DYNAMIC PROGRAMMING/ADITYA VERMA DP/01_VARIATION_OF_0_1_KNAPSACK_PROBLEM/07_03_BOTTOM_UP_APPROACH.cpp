/*
#TARGET SUM

LINK:- https://leetcode.com/problems/target-sum/

*/

#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int> &nums, int target, int n, vector<vector<int>> &dp, int offset) {
//         if (target + offset < 0 || target + offset >= dp[0].size())
//             return 0;

//         if (n == 0) {
//             return (target == 0) ? 1 : 0;
//         }

//         if(dp[n][target + offset] != -1) return dp[n][target + offset];

//         int add = solve(nums, target - nums[n - 1], n - 1, dp, offset);
//         int subtract = solve(nums, target + nums[n - 1], n - 1, dp, offset);

//         return dp[n][target + offset] = add + subtract;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int total_sum = accumulate(nums.begin(), nums.end(), 0);

//         if (abs(target) > total_sum) return 0;

//         int offset = total_sum;
//         vector<vector<int>> dp(n + 1, vector<int>(2 * total_sum + 1, -1));

//         return solve(nums, target, n, dp, offset);
//     }

int findTargetSumWays2(vector<int>& nums, int target) {
    int n = nums.size();
    int total_sum = accumulate(nums.begin(), nums.end(), 0);

    // If target is out of possible bounds
    if (abs(target) > total_sum) return 0;

    int offset = total_sum;
    vector<vector<int>> dp(n + 1, vector<int>(2 * total_sum + 1, 0));

    // Base Case: one way to have sum = 0 at index 0
    dp[0][offset] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int sum = -total_sum; sum <= total_sum; ++sum) {
            int idx = sum + offset;
            if (idx < 0 || idx >= 2 * total_sum + 1) continue;

            int prev_num = nums[i - 1];

            // If reachable by adding the current number
            if ((sum - prev_num) + offset >= 0 && (sum - prev_num) + offset < 2 * total_sum + 1)
                dp[i][idx] += dp[i - 1][(sum - prev_num) + offset];

            // If reachable by subtracting the current number
            if ((sum + prev_num) + offset >= 0 && (sum + prev_num) + offset < 2 * total_sum + 1)
                dp[i][idx] += dp[i - 1][(sum + prev_num) + offset];
        }
    }

    return dp[n][target + offset];
}


 

/*
***THIS PROBLEM IS ALSO DEDUCED INTO THE PREVIOUS PROBLEM OF :- COUNT THE NUMBER OF SUBSETS WITH GIVEN DIFFERENCE***

FOR EXAMPLE :- NUMS = [1,1,1,1,1], TARGET = 3

ONE OF ITS SOLUTION IS :- -1 + 1 + 1 + 1 + 1 = 3;

IN THE ABOVE SOLUTION, WE CAN DIVIDE THOSE NUMBER INTO 2 SETS, +(1, 1, 1, 1) AND -(1) {+GROUP, AND -GROUP}

=> AND WE HAVE TO JUST TO SET1 - SET2 = TARGET

=> 4-1 = 3 (== TARGET)
 */

int minDifference(vector<int>& arr, int target) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    if((total_sum + target)%2 != 0 || target > total_sum) return 0;

    int required = (total_sum + target)/2;

    int n = arr.size();

    vector<vector<int>> dp(n+1, vector<int>(required+1, 0));

    for(int i = 0; i<=n; i++) dp[i][0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=required; j++){
            if(j >= arr[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][required];
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout<<findTargetSumWays2(nums, target);

    return 0;
}