/*
#LARGEST DIVISIBLE SUBSET

LINK:- https://leetcode.com/problems/largest-divisible-subset/

*/

#include<bits/stdc++.h>
using namespace std;

/*
- Sort array - ensures if a divides b, then a comes before b
- Use pick/not-pick recursion to try all possible subsets

At each index:
1. Not-pick case: Always skip current element and move to next
2. Pick case: Only if current element is divisible by previous element (or no previous element exists)
   - Add to temporary subset
   - Recurse with current element as new "previous"
   - Backtrack (remove element)

Base case: When you've processed all elements, check if current subset is longer than the best found so far

Key insight: After sorting, you only need to check if nums[idx] % prev == 0 because:
- If a divides b and b divides c, then a divides c (transitivity)
- Sorting ensures we build valid chains

Result: Explores all valid divisible subsets and returns the longest one.

Time: O(2^n) - tries all subsets
Space: O(n) - recursion stack + temporary arrays

*/
class Solution_recursion {
public:
    void solve(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
        if (idx >= nums.size()) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            solve(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }

        solve(idx + 1, nums, result, temp, prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> result;
        vector<int> temp;

        int prev = -1;
        solve(0, nums, result, temp, prev);

        return result;
    }
};

//TIME COMPLEXITY :- O(nLOGn) + O(N^2);
//SPACE COMPLEXITY :- O(N);
/*
Key Insight: This is exactly like LIS, but instead of nums[j] < nums[i], we check nums[i] % nums[j] == 0.

DP Definition:
- dp[i] = length of largest divisible subset ending at index i
- prev_idx[i] = previous index that led to best result for i (for path reconstruction)

Algorithm:
1. Sort array - ensures divisibility chain works in order
2. For each position i: Look at all previous positions j
3. If nums[i] % nums[j] == 0: Can extend subset ending at j
   - Update: dp[i] = max(dp[i], dp[j] + 1)
   - Track: prev_idx[i] = j (remember which j gave best result)
4. Track global maximum: Keep track of longest subset found and its ending index

Path Reconstruction:
- Start from last_chosen_index (where longest subset ends)
- Follow prev_idx chain backwards to get all elements
- prev_idx acts like a linked list pointing to previous element

Why it works:
- After sorting, if a divides b and b divides c, then a divides c (transitivity)
- Same principle as LIS but with divisibility condition instead of increasing condition

Time: O(n²), Space: O(n)

*/
class Solution_optimal {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), prev_idx(n, -1);

        int last_chosen_index = 0;
        int maxL = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }

                    if (dp[i] > maxL) {
                        maxL = dp[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while (last_chosen_index != -1) {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};


int main() {
    Solution_recursion obj;
    vector<int> nums = { 32,3,64,4,15 };
    vector<int> ans = obj.largestDivisibleSubset(nums);
    for (auto i : ans) cout << i << " ";
    return 0;
}