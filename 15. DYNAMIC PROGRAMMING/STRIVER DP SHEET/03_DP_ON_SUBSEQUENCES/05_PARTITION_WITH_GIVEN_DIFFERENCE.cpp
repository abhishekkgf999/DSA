/*
#PARTITIONS WITH GIVEN DIFFERENCE

LINK :- https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_recursion {
public:
    int solve(vector<int>& arr, int n, int target) {
        if (n == 0) {
            if (target == 0)return 1;
            return 0;
        }

        if (n <= 0 || target < 0) return 0;

        return solve(arr, n - 1, target) + solve(arr, n - 1, target - arr[n - 1]);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int total_sum = accumulate(arr.begin(), arr.end(), 0);

        int to_find = (total_sum + d) / 2;

        int n = arr.size();

        return solve(arr, n, to_find);
    }
};


class Solution_memoization {
public:
    int solve(vector<int>& arr, int n, int target, vector<vector<int>>& dp) {
        if (n == 0) {
            if (target == 0)return 1;
            return 0;
        }

        if (n <= 0 || target < 0) return 0;

        if (dp[n][target] != -1)return dp[n][target];

        return solve(arr, n - 1, target, dp) + solve(arr, n - 1, target - arr[n - 1], dp);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int total_sum = accumulate(arr.begin(), arr.end(), 0);

        if ((total_sum + d) % 2 != 0 || total_sum < d)   return 0;

        int to_find = (total_sum + d) / 2;

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(to_find + 1, -1));

        return solve(arr, n, to_find, dp);
    }
};

class Solution_tabulation {
public:
    int countPartitions(vector<int>& arr, int d) {
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();

        // Check for edge cases:
        // 1. (total_sum + d) must be even for a partition to exist.
        // 2. The target sum must be non-negative.
        // 3. The total_sum cannot be less than the difference 'd'.
        if ((total_sum + d) % 2 != 0 || total_sum < d) {
            return 0;
        }

        // The target sum for one of the partitions (s1).
        int target = (total_sum + d) / 2;

        // dp[i][j] will store the number of ways to form a sum 'j' using the first 'i' elements.
        // The size of the DP table is (n+1) x (target+1).
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Correct Base Case:
        // There is one way to form a sum of 0, by taking no elements, using the first 0 elements.
        // This is the only valid base case to start the recurrence.
        dp[0][0] = 1;       // think like that, arr = [0], then we have two ways to make sum 0, one - we will not take any element, second - we will take that zero
        //that's why we have only one base case where we have empty array and target is 0;

        // Loop through each element of the array. 'i' represents the number of elements considered.
        // The element at index (i-1) in 'arr' corresponds to the 'i'-th element.
        for (int i = 1; i <= n; ++i) {
            // Loop through all possible sums.
            for (int j = 0; j <= target; ++j) {
                // Case 1: Don't include the current element (arr[i-1]).
                // The number of ways is the same as the number of ways using the previous 'i-1' elements.
                int not_take = dp[i - 1][j];

                // Case 2: Include the current element (arr[i-1]).
                int take = 0;
                // Only consider this case if the current sum 'j' is large enough to include the element.
                if (j >= arr[i - 1]) {
                    // The number of ways is the number of ways to form the remaining sum
                    // (j - arr[i-1]) using the previous 'i-1' elements.
                    take = dp[i - 1][j - arr[i - 1]];
                }

                // The total number of ways is the sum of ways from both cases.
                dp[i][j] = not_take + take;
            }
        }

        // The final answer is the number of ways to form the 'target' sum using all 'n' elements.
        return dp[n][target];
    }
};

int main() {
    vector<int> arr = { 0, 1, 2, 2, 2, 3, 0, 3, 0, 1 };
    int d = 12;
    Solution_tabulation obj;
    cout << obj.countPartitions(arr, d);
    return 0;
}