/*
#LONGEST INCREASING SUBSEQUENCE

LINK :- https://leetcode.com/problems/longest-increasing-subsequence/description/

*/


#include<bits/stdc++.h>
using namespace std;

/*
1. Start from index 0 and move to the end of the array.
2. At every index, you have two choices:

   * Take the current element only if it is greater than the previous element in the sequence.
   * Skip the current element and move to the next index.


3. Recursively try both choices and return the maximum length obtained.
4. Use memoization to store results of overlapping subproblems to optimize.

*/

//TIME COMPLEXITY :- O(2^N)
class Solution_recursion {
public:
    int solve(vector<int>& nums, int i, int lastIndex) {
        if (i == nums.size()) {
            return 0;
        }

        int skip = solve(nums, i + 1, lastIndex);
        int pick = 0;

        if (lastIndex == -1 || nums[i] > nums[lastIndex]) {
            pick = 1 + solve(nums, i + 1, i);
        }

        return max(pick, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};

//TIME COMPLEXITY :- O(n*n) SPACE COMPLEXITY :- O(n*n)
class Solution_memoization {
public:
    int solve(vector<int>& nums, int i, int lastIndex, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][lastIndex + 1] != -1) return dp[i][lastIndex + 1];

        int skip = solve(nums, i + 1, lastIndex, dp);
        int pick = 0;

        if (lastIndex == -1 || nums[i] > nums[lastIndex]) {
            pick = 1 + solve(nums, i + 1, i, dp);
        }

        return dp[i][lastIndex + 1] = max(pick, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};


/*
Logic behind adding +1 to lastIndex:

The Problem:
- Your DP state uses lastIndex which can be -1 (meaning no previous element picked)
- But array indices in C++ must be non-negative (0, 1, 2, ...)
- You can't access dp[i][-1] - it would cause an error!

The Solution - Index Shifting:
- Shift all indices by +1 when accessing the DP array
- lastIndex = -1 → access dp[i][-1+1] = dp[i][0]
- lastIndex = 0 → access dp[i][0+1] = dp[i][1]
- lastIndex = 1 → access dp[i][1+1] = dp[i][2]

In your code:
- dp[i+1][lastIndex+1] - reading the stored result
- dp[i+1][i+1] - when picking element at index i, new lastIndex becomes i
- dp[i][lastIndex+1] - storing the result (should be dp[i][lastIndex+1])

Note: There's a bug in your code - you wrote dp[i][lastIndex] but it should be dp[i][lastIndex+1] for consistency.

The +1 is just a mapping technique to handle negative indices in arrays.
*/
class Solution_tabulation {
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int lastIndex = n - 1; lastIndex >= -1; lastIndex--) {
                int skip = dp[i + 1][lastIndex + 1];
                int pick = 0;

                if (lastIndex == -1 || nums[i] > nums[lastIndex]) {
                    pick = 1 + dp[i + 1][i + 1];
                }

                dp[i][lastIndex] = max(pick, skip);
            }
        }
        return dp[0][0];
    }
};

class Solution_tabulation_space_optimization {
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int lastIndex = n - 1; lastIndex >= -1; lastIndex--) {
                int skip = next[lastIndex + 1];
                int pick = 0;

                if (lastIndex == -1 || nums[i] > nums[lastIndex]) {
                    pick = 1 + next[i + 1];
                }

                curr[lastIndex + 1] = max(pick, skip);
            }
            next = curr;
        }
        return next[0];
    }
};


class Solution_tabulation_other_way {
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

//PATIENCE SORTING :- O(n*logn)
/*
Main Idea: Keep track of the smallest possible ending element for each subsequence length.
What we maintain:

tails[0] = smallest ending element among all subsequences of length 1
tails[1] = smallest ending element among all subsequences of length 2
tails[2] = smallest ending element among all subsequences of length 3
And so on...

For each new element:

If it's bigger than everything in tails: Add it to extend the longest subsequence
Otherwise: Find the first element in tails that's ≥ current element and replace it

Why replace?
Because a smaller ending element gives us better chances to extend the subsequence later.
*/
class Solution_Binary_Search {
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);   //justgreater than or equal to nums[i]

            if (it == sorted.end()) {
                sorted.push_back(nums[i]);  //greatest : so insert it
            }
            else {
                *it = nums[i];
            }
        }

        return sorted.size();
    }
};



int main() {
    Solution_memoization obj;
    vector<int> num = { 10,9,2,5,3,7,101,18 };
    cout << obj.lengthOfLIS(num);
    return 0;
}