/*
#SUM OF SUBARRAY MINIMUM

LINK:- https://leetcode.com/problems/sum-of-subarray-minimums/
*/

#include<bits/stdc++.h>
using namespace std;

/*
## Core Concept: Contribution Technique

### Key Insight
Instead of finding minimum of each subarray, calculate:
How many subarrays have arr[i] as their minimum?

Then: contribution of arr[i] = arr[i] × count of subarrays

---

## Understanding the Pattern

### For element at index i to be minimum in a subarray:
1. Subarray must include index i
2. All elements in subarray must be ≥ arr[i]

### Range of Valid Subarrays:
- Left boundary: How far left can we extend while elements ≥ arr[i]?
- Right boundary: How far right can we extend while elements > arr[i]?


Array: [5, 3, 7, 4, 2, 6]
           ↑ (index i=1, value=3)

Left range:  Can't go to index 0 (5 > 3, but we want ≥)
             Can extend from index 0
Right range: Can extend to index 2 (7 > 3)
             Can't go to index 4 (2 < 3)


---

## Algorithm Components

### Part 1: Find Next Smaller Element (NSE)
Purpose: Find the first index on RIGHT where element is smaller than arr[i]

Note: Uses <= to handle duplicates (strict inequality on one side)

---

### Part 2: Find Previous Smaller Element (PSE)
Purpose: Find the first index on LEFT where element is smaller than arr[i]

Note: Uses < (different from NSE) to handle duplicates correctly

---

### Part 3: Calculate Contribution
## Detailed Example: arr = [3, 1, 2, 4]

### Step 1: Calculate NSE (Next Smaller Element)

Index:  0  1  2  3
Array: [3, 1, 2, 4]

i=3: 4 → NSE[3] = 4 (no smaller on right)
i=2: 2 → NSE[2] = 4 (no smaller on right)
i=1: 1 → NSE[1] = 4 (no smaller on right)
i=0: 3 → NSE[0] = 1 (1 is smaller)

NSE = [1, 4, 4, 4]


### Step 2: Calculate PSE (Previous Smaller Element)

Index:  0  1  2  3
Array: [3, 1, 2, 4]

i=0: 3 → PSE[0] = -1 (no smaller on left)
i=1: 1 → PSE[1] = -1 (no smaller on left)
i=2: 2 → PSE[2] = 1  (1 is smaller)
i=3: 4 → PSE[3] = 2  (2 is smaller)

PSE = [-1, -1, 1, 2]


### Step 3: Calculate Contribution

i=0: arr[0]=3
  left = 0 - (-1) = 1
  right = 1 - 0 = 1
  contribution = 3 × 1 × 1 = 3
  Subarrays: [3]

i=1: arr[1]=1
  left = 1 - (-1) = 2
  right = 4 - 1 = 3
  contribution = 1 × 2 × 3 = 6
  Subarrays: [1], [3,1], [1,2], [3,1,2], [1,2,4], [3,1,2,4]

i=2: arr[2]=2
  left = 2 - 1 = 1
  right = 4 - 2 = 2
  contribution = 2 × 1 × 2 = 4
  Subarrays: [2], [2,4]

i=3: arr[3]=4
  left = 3 - 2 = 1
  right = 4 - 3 = 1
  contribution = 4 × 1 × 1 = 4
  Subarrays: [4]

Total = 3 + 6 + 4 + 4 = 17


## Why Different Comparisons? (< vs <=)

### Problem: Handling Duplicates
If arr = [2, 2], both elements would claim the same subarrays without proper handling.

### Solution:
- NSE uses <=: arr[i] ≤ arr[st.top()] → Pop equal elements
- PSE uses <: arr[i] < arr[st.top()] → Keep equal elements

This ensures each subarray is counted exactly once!


Array: [2, 2]

For i=0 (value=2):
  PSE[0] = -1
  NSE[0] = 2 (pops the duplicate at i=1)
  Contribution counts: [2], [2,2]

For i=1 (value=2):
  PSE[1] = 0 (keeps the duplicate at i=0)
  NSE[1] = 2
  Contribution counts: [2] (only this one)

Total subarrays counted = 3 (no overlap!)


---
## Key Takeaways

### 1. Contribution Technique
Instead of checking every subarray, count how many times each element contributes.

### 2. Boundary Finding
Use monotonic stack to efficiently find boundaries where element is minimum.

### 3. Multiplication Principle
Total subarrays = (left choices) × (right choices)

### 4. Duplicate Handling
Use strict inequality on one side, non-strict on other to avoid double counting.


*/
#define MOD 1000000007

class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
        stack<int> st;
        vector<int> result(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }

            if (!st.empty()) result[i] = st.top();
            else result[i] = arr.size();

            st.push(i);
        }

        return result;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> st;
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }

            if (!st.empty()) result[i] = st.top();
            else result[i] = -1;

            st.push(i);
        }

        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);

        long long int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return ans;
    }
};

int main() {
    vector<int> arr = { 1,4,6,7,3,7,8,1 };
    Solution obj;
    cout << obj.sumSubarrayMins(arr);
    return 0;
}