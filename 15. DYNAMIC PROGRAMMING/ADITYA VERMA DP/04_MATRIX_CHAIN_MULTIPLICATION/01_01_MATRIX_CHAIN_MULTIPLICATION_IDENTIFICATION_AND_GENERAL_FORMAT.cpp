/*
# MATRIX CHAIN MULTIPLICATION (MCM) TEMPLATE & IDENTIFICATION GUIDE

## IDENTIFYING MCM-TYPE QUESTIONS:
- You're given an array (often representing matrices, balloons, rods, etc.).
- You're asked to find the minimum/maximum value of some cost based on a sequence of operations.
- The structure is recursive with:
  → A starting point at the extreme left (usually i = 0 or 1)
  → An ending point at the extreme right (usually j = n-1 or n)
  → A partition point `k` that moves from i to j-1 (or i+1 to j-1), depending on the problem.

Examples:
- Matrix Chain Multiplication
- Burst Balloons
- Minimum Cost to Cut a Stick
- Boolean Parenthesization
- Palindrome Partitioning
- Egg Dropping Problem

## GENERIC RECURSIVE TEMPLATE:

int solve(int arr[], int i, int j) {
    // Base Case: usually when i >= j (only one element or invalid range)
    if (i >= j) return 0;

    int ans = INT_MAX; // or INT_MIN based on min/max problem

    // Try all possible partitions
    for (int k = i; k < j; k++) {
        // Divide into two parts and combine answers
        int temp = solve(arr, i, k) + solve(arr, k + 1, j)
                   + cost of combining (problem-specific logic);

        ans = min(ans, temp); // or max() depending on the problem
    }

    return ans;
}

## POINTS TO CUSTOMIZE BASED ON THE PROBLEM:
- Base case (i >= j), may change (e.g., i > j, i == j)
- How `k` moves (i to j-1, i+1 to j-1, or skipping steps)
- Cost calculation (e.g., arr[i-1] * arr[k] * arr[j] for MCM)
- Function used to update answer (min/max)

## COMPLEXITY:
- Recursive: Exponential
- Memoized: O(n³) for standard MCM
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j) {
    if (i >= j) return 0; // base case

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {

        int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]; // Example: MCM cost

        ans = min(ans, temp_ans);
    }

    return ans;
}

int main() {
    return 0;
}
