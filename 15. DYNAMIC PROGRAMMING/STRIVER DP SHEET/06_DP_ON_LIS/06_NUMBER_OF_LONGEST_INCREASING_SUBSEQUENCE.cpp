/*
#NUMBER OF LONGEST INCREASING SUBSEQUENCE

LINK:- https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

#include<bits/stdc++.h>
using namespace std;

/*

Problem: Count how many different LIS exist in the array.

Two DP Arrays:
- dp[i] = length of LIS ending at position i
- count[i] = number of different LIS of length dp[i] ending at position i

Why Reset Count (count[i] = count[j]):
- We found a longer LIS ending at i
- All previous ways to form shorter LIS at i become invalid
- Only the ways from position j matter now (since it gives longer length)

Why Add Count (count[i] += count[j]):
- We found another way to achieve the same optimal length at i
- Position j gives us additional paths to form LIS of same length
- We combine all different ways to reach the same optimal length

Example:
- If dp[i] = 3 can be achieved from position 1 (2 ways) and position 2 (3 ways)
- Then count[i] = 2 + 3 = 5 total ways to form LIS of length 3 ending at i
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int max_len = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                        if (dp[i] > max_len) max_len = dp[i];
                    }
                    else if (dp[i] == dp[j] + 1) count[i] += count[j];
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == max_len) {
                result += count[i];
            }
        }

        return result;
    }
};

int main() {
    vector<int> num = { 1,2,4,3,5,4,7,2 };
    Solution obj;
    cout << obj.findNumberOfLIS(num);
    return 0;
}