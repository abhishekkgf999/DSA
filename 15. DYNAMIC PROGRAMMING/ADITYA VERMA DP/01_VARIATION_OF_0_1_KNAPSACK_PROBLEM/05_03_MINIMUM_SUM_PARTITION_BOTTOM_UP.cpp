/*
#MINIMUM SUM PARTITION

LINK:- https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

*/

/*
================= PROBLEM OVERVIEW =================

👉 Objective:
Given an array, divide it into two subsets such that the absolute difference of their sums is minimized.

Example:
Input: arr[] = {1, 2, 7}
Subsets: [1,2] and [7] → Sum1 = 3, Sum2 = 7 → |Sum1 - Sum2| = 4

✅ Goal:
Minimize the value of |Sum1 - Sum2|

================= LOGIC & OBSERVATION =================

Let total_sum = sum of all array elements
Let set1 be the sum of one subset
Then set2 = total_sum - set1

👉 Difference = |set1 - set2| = |total_sum - 2 * set1|

To minimize the difference:
➡️ We must **maximize set1** such that (total_sum - 2 * set1) is minimum
➡️ Valid values for set1 lie in range [0, total_sum/2]
   (because if set1 > total_sum/2, set2 becomes smaller)

✔ So the problem becomes:
Find the **maximum possible value of set1 ≤ total_sum/2** such that set1 is the sum of a subset of the given array.

➡️ This is a variation of the **Subset Sum Problem**, and we’ll solve it using **Dynamic Programming (Bottom-Up)**.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum subset sum difference
//METHOD 1, VERY INTUITIVE METHOD
int minDifference1(vector<int>& arr) {
    int n = arr.size();
    int total_sum = accumulate(arr.begin(), arr.end(), 0); // Sum of all elements

    // Create DP table: dp[i][j] = true if subset of first i elements has sum j
    vector<vector<bool>> dp(n + 1, vector<bool>(total_sum + 1, false));

    // Base case: With 0 elements, we can only form sum = 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total_sum; j++) {
            if (arr[i - 1] <= j) {
                // Include or exclude the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                // Cannot include current element (too large), only exclude
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Find the largest j (subset sum) such that dp[n][j] is true and j <= total_sum / 2
    int set1 = 0;
    for (int j = 0; j <= total_sum / 2; j++) {
        if (dp[n][j]) {
            set1 = j;
        }
    }

    // Return the minimum difference
    return total_sum - 2 * set1;
}

//MY PREVIOUS CODE OPTIMIZATION TO BOTTOM UP APPROACH
int minDifference2(vector<int>& arr) {
    int n = arr.size();
    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    // dp[i][j] will be true if a subset with sum 'j' can be formed from first 'i' elements
    vector<vector<bool>> dp(n + 1, vector<bool>(total_sum + 1, false));

    // Initialization: 0 sum is always possible with 0 elements
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total_sum; j++) {
            if (arr[i - 1] <= j) {
                // Include or exclude current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                // Exclude current element
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Find the minimum difference
    int min_diff = INT_MAX;
    for (int j = 0; j <= total_sum / 2; j++) {
        if (dp[n][j]) {
            int first = j;
            int second = total_sum - j;
            min_diff = min(min_diff, abs(first - second));
        }
    }

    return min_diff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << minDifference2(arr);  // Output: 1
    return 0;
}
