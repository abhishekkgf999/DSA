/*
#BINARY SUBARRAYS WITH SUM

LINK:- https://leetcode.com/problems/binary-subarrays-with-sum/
*/

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY :- O(N^2)
//SPACE COMPLEXITY :- O(N);
/*
The logic of this code is a brute-force approach using a prefix sum array to count subarrays with a specific sum.

First, it creates a prefix sum array ps where ps[j] stores the sum of all elements from nums[0] to nums[j]. This allows the sum of any subarray to be calculated in constant time.

Second, it uses nested loops to check every possible subarray. For each ending index j, it iterates through all possible starting indices i. The sum of the subarray from i to j is calculated as ps[j] - ps[i].
If this sum equals the goal, the counter ans is incremented. The inner loop's break condition is an attempt at an optimization, but it's flawed since prefix sum values are not always sorted.
*/
class Solution_BRUTE_FORCE {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> ps(n, 0);
        ps[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ps[i] = nums[i] + ps[i - 1];
        }
        int ans = 0;
        if (ps[0] == goal)ans += 1;

        for (int j = 1; j < ps.size(); j++) {
            if (ps[j] == goal) ans++;
            int req = ps[j] - goal;
            for (int i = 0; i < j; i++) {
                if (ps[i] == req)ans++;
                else if (ps[i] > req) break;
            }
        }

        return ans;
    }
};


//TIME COMPLEXITY :- O(N)
//SPACE COMPLEXITY :- O(N)
class Solution_BETTER_TIME_COMPLEXITY {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        map<long long, int> preSumMap;
        preSumMap[0]++;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            long long rem = sum - goal;
            if (preSumMap.find(rem) != preSumMap.end()) {
                count += preSumMap[rem];
            }
            preSumMap[sum]++;
        }

        return count;
    }
};

/*

## Core Challenge
Multiple valid subarrays can end at same position due to leading zeros.

Example: [0,0,1,0,1] with goal=2
- Subarrays ending at index 4: [1,0,1], [0,1,0,1], [0,0,1,0,1]

## Sliding Window + Zero Counting Logic


Logic:
- Remove zeros: Count them as potential subarray starting points
- Remove ones: Reset zero count (breaks the leading zero sequence)
- Shrink when sum > goal: Maintain valid window

### Counting Valid Subarrays

if(window_sum == goal){
    result += 1 + count_zeroes;
}

Logic: When window sum equals goal:
- 1: Current window [i...j]
- count_zeroes: Additional subarrays by including leading zeros

## Key Implementation Insights

Why count leading zeros?
- Each leading zero creates an additional valid subarray
- [0,0,1,1] with goal=2 → can start from index 0, 1, or 2

Why reset count_zeroes on non-zero removal?

else { count_zeroes = 0; }

Reason: Removing a '1' breaks the sequence of leading zeros

Shrinking condition: nums[i] == 0 || window_sum > goal
- Remove excess sum OR collect leading zeros

## Mental Model
Think of leading zeros as "flexible starting points":


nums = [0,0,1,0,1], goal = 2
At j=4: window_sum = 2, count_zeroes = 2
Valid subarrays: [1,0,1], [0,1,0,1], [0,0,1,0,1]
Count = 1 + 2 = 3


Pattern:
1. Expand window to include current element
2. Shrink to maintain sum ≤ goal while counting removed zeros
3. Count all subarrays ending at current position when sum = goal

## Key Points
- Zero counting: Tracks additional valid starting positions
- Flexible window: Adjusts based on sum constraint
- Multiple subarrays: One position can contribute multiple valid subarrays

Time: O(n) | Space: O(1)

*/
class Solution_optimal1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0;
        int result = 0;
        int count_zeroes = 0;
        int window_sum = 0;
        while (j < nums.size()) {
            window_sum += nums[j];
            while (i < j && (nums[i] == 0 || window_sum > goal)) {
                if (nums[i] == 0) {
                    count_zeroes++;
                }
                else {
                    count_zeroes = 0;
                }
                window_sum -= nums[i];
                i++;
            }

            if (window_sum == goal) {
                result += 1 + count_zeroes;
            }
            j++;
        }

        return result;
    }
};


/*
## Core Insight: Transform "Exactly K" to "At Most K"
Key Formula: exactly(goal) = atMost(goal) - atMost(goal-1)

Why this works?
- atMost(goal): All subarrays with sum ≤ goal
- atMost(goal-1): All subarrays with sum ≤ goal-1
- Difference: Subarrays with sum exactly = goal


### Key Counting Logic: count += j-i+1
At position j, number of valid subarrays ending at j:
- [i, j], [i+1, j], [i+2, j], ..., [j, j]
- Total count = j - i + 1

Why this works? All subarrays from any position ≥ i to j have sum ≤ goal

Edge Case: if(goal < 0) return 0;
- When goal=0, goal-1=-1 → invalid, return 0


Why j-i+1 works for counting?
- At each position j, window [i,j] has sum ≤ goal
- ALL subarrays starting from i to j and ending at j are valid
- Count = number of possible starting positions

Difference technique advantage:
- Converts complex "exactly K" to simpler "at most K"
- Single sliding window solution instead of zero-counting complexity

Time: O(n) for each solve call = O(n) total | Space: O(1)
*/
class Solution_optmial2 {
public:
    int solve(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int i = 0, j = 0;
        int sum = 0;
        int count = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};

int main() {
    Solution_BRUTE_FORCE s1;
    Solution_BETTER_TIME_COMPLEXITY s2;
    Solution_optimal1 s3;
    Solution_optmial2 s4;

    vector<int> nums = { 1, 0, 1, 0, 1 };
    int goal = 2;

    cout << "Test Case 1: nums = {1, 0, 1, 0, 1}, goal = 2" << endl;

    // Brute Force Solution
    cout << "Brute Force: " << s1.numSubarraysWithSum(nums, goal) << endl;

    // Prefix Sum with Hash Map Solution
    cout << "Prefix Sum with HashMap: " << s2.numSubarraysWithSum(nums, goal) << endl;

    // Sliding Window with Zero Counting Solution
    cout << "Sliding Window with Zero Counting: " << s3.numSubarraysWithSum(nums, goal) << endl;

    // Sliding Window with At Most K Solution
    cout << "Sliding Window with At Most K: " << s4.numSubarraysWithSum(nums, goal) << endl;

    cout << "---------------------------------" << endl;

    // Test Case 2: Different input
    vector<int> nums2 = { 0, 0, 0, 0, 0 };
    int goal2 = 0;

    cout << "Test Case 2: nums = {0, 0, 0, 0, 0}, goal = 0" << endl;

    cout << "Brute Force: " << s1.numSubarraysWithSum(nums2, goal2) << endl;
    cout << "Prefix Sum with HashMap: " << s2.numSubarraysWithSum(nums2, goal2) << endl;
    cout << "Sliding Window with Zero Counting: " << s3.numSubarraysWithSum(nums2, goal2) << endl;
    cout << "Sliding Window with At Most K: " << s4.numSubarraysWithSum(nums2, goal2) << endl;

    return 0;
}