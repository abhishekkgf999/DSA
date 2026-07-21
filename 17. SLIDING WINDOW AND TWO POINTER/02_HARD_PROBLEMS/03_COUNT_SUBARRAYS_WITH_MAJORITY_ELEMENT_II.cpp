/*
================================================================================
  PROBLEM: COUNT SUBARRAYS WITH MAJORITY ELEMENT II
  LINK   : https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
  TC     : O(N)   |   SC : O(N)
================================================================================

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  PROBLEM UNDERSTANDING
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Given an integer array `nums` and an integer `target`, count the number of
  subarrays in which `target` is the MAJORITY ELEMENT.

  Majority Element of a subarray: an element that appears STRICTLY MORE THAN
  half the times in that subarray.

  i.e., for a subarray of length L:
      count(target) > L / 2    (strictly more than half)

  Equivalent condition (integer arithmetic):
      count(target) * 2 > L
      2 * count(target) > count(target) + count(non-target)
      count(target) - count(non-target) > 0
      count(target) - count(non-target) >= 1

  So in ANY valid subarray, target must appear at least one more time
  than all non-target elements combined.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  KEY INSIGHT / TRANSFORMATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  The classic trick: transform the array into +1 / -1.

      nums[i] == target  →  +1
      nums[i] != target  →  -1

  Example: nums = [1, 2, 2, 3], target = 2
      Transformed: [-1, +1, +1, -1]

  Now the problem becomes:
      Count subarrays where the SUM of the transformed array >= 1
      (i.e., sum > 0, i.e., sum >= 1)

  WHY >= 1 and not > 0?
      Because sum > 0 for integers means sum >= 1. They are equivalent.
      But we use >= 1 explicitly when working with prefix sums.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  PREFIX SUM REDUCTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Define prefix sum: prefix[j] = sum of transformed[0..j-1]
      (prefix[0] = 0 by convention)

  Sum of subarray [i+1 .. j] = prefix[j] - prefix[i]

  We want:    prefix[j] - prefix[i] >= 1
  i.e.:       prefix[i] <= prefix[j] - 1

  So for each right endpoint j, we want to count the number of
  left endpoints i (where i < j) such that:
      prefix[i] <= prefix[j] - 1

  This means: how many previously seen prefix sums are
  STRICTLY LESS THAN prefix[j]?
  (since prefix[i] <= prefix[j] - 1  ⟺  prefix[i] < prefix[j])

  If we store prefix sums in a frequency map, for each j we need:
      count of prefix sums seen so far that are < prefix[j]

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  WHY THE "INCREMENTAL" TRICK WORKS
  (How validLeftPoints avoids re-scanning the map every time)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Naively, for each j we'd query: sum of mpp[k] for all k < cumSum[j].
  That's O(N) per step → O(N²) overall. Too slow.

  KEY OBSERVATION:
  cumSum (prefix sum) only changes by +1 or -1 at each step.

  Case A: nums[j] == target → cumSum increases by +1
      The threshold shifts from (cumSum - 1) to (cumSum).
      Now one more bucket (cumSum - 1, which is old cumSum) becomes valid.
      So validLeftPoints gains mpp[old cumSum] = mpp[cumSum before increment].
      We add mpp[cumSum] BEFORE doing cumSum++.

  Case B: nums[j] != target → cumSum decreases by -1
      The threshold shifts from (cumSum - 1) to (cumSum - 2).
      The bucket (cumSum - 1) = (new cumSum) is no longer valid.
      So validLeftPoints loses mpp[new cumSum] = mpp[cumSum after decrement].
      We do cumSum-- FIRST, then subtract mpp[cumSum].

  This way, validLeftPoints always holds:
      "number of previously seen prefix[i] values that are < current cumSum"
  ...updated in O(1) per step, because cumSum moves by exactly ±1.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  PROOF OF THE FORMULA
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  We want: #{i < j : prefix[i] < prefix[j]}

  This set changes as cumSum moves ±1:

  When cumSum goes from C to C+1 (target hit):
      - Previously valid: prefix[i] < C  (count = validLeftPoints)
      - Now valid:        prefix[i] < C+1
      - New additions:    prefix[i] == C  (count = mpp[C])
      ∴ validLeftPoints += mpp[C]  (add BEFORE incrementing cumSum)

  When cumSum goes from C to C-1 (non-target hit):
      - Previously valid: prefix[i] < C  (count = validLeftPoints)
      - Now valid:        prefix[i] < C-1
      - Removals:         prefix[i] == C-1  (count = mpp[C-1])
      ∴ validLeftPoints -= mpp[C-1]  (subtract AFTER decrementing cumSum)
      → same as: cumSum--; validLeftPoints -= mpp[cumSum];

  After updating validLeftPoints, add it to result:
      result += validLeftPoints
      (each valid left endpoint i pairs with current j to form a valid subarray)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  DRY RUN: nums = [1, 2, 2, 3], target = 2
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Transformed: [-1, +1, +1, -1]

  Init: mpp = {0:1}, cumSum = 0, validLeftPoints = 0, result = 0

  ── j=0, nums[0]=1 (not target) ──────────────────────────────
    cumSum-- → cumSum = -1
    validLeftPoints -= mpp[-1] = 0  → validLeftPoints = 0
    mpp[-1]++ → mpp = {0:1, -1:1}
    result += 0  → result = 0

  ── j=1, nums[1]=2 (target) ──────────────────────────────────
    validLeftPoints += mpp[0] = 1  → validLeftPoints = 1
      (mpp[cumSum] = mpp[0] = 1, because cumSum is still -1... wait)

    WAIT — let's be precise about order:
    At j=1, cumSum = -1 BEFORE processing.
    nums[1] == target:
      validLeftPoints += mpp[cumSum]  → += mpp[-1] = 1  → validLeftPoints = 1
      cumSum++  → cumSum = 0
    mpp[0]++  → mpp = {0:2, -1:1}
    result += 1  → result = 1

    Meaning: subarray ending at j=1 with left at i=0 is valid: [2]

  ── j=2, nums[2]=2 (target) ──────────────────────────────────
    nums[2] == target:
      validLeftPoints += mpp[cumSum]  → += mpp[0] = 2  → validLeftPoints = 3
      cumSum++  → cumSum = 1
    mpp[1]++  → mpp = {0:2, -1:1, 1:1}
    result += 3  → result = 4

    Meaning: 3 subarrays ending at j=2:
      [2]     (i=2)   sum of transformed[2..2] = +1 ✓
      [2,2]   (i=1)   sum of transformed[1..2] = +2 ✓
      [1,2,2] (i=0)   sum of transformed[0..2] = +1 ✓

  ── j=3, nums[3]=3 (not target) ──────────────────────────────
    nums[3] != target:
      cumSum--  → cumSum = 0
      validLeftPoints -= mpp[0] = 2  → validLeftPoints = 1
    mpp[0]++  → mpp = {0:3, -1:1, 1:1}
    result += 1  → result = 5

    Meaning: 1 subarray ending at j=3:
      [2,2,3] (i=1)   sum of transformed[1..3] = +1 ✓
      Note: [1,2,2,3] has sum 0, NOT valid (sum must be >= 1).

  FINAL result = 5 ✓  (matches expected output)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ADDITIONAL OBSERVATIONS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  1. mpp[0] = 1 initialization:
     This accounts for the "empty prefix" (subarray starting at index 0).
     Without it, subarrays [0..j] would never be counted.

  2. validLeftPoints can never go negative:
     Because cumSum can only decrease to a value that was seen before,
     and mpp tracks how many times each cumSum was seen.
     If it were ever negative, that would indicate a bug.

  3. Why long long for result and validLeftPoints?
     With N=10^5 all elements == target, every subarray is valid.
     Total subarrays = N*(N+1)/2 = ~5*10^9 which overflows int.

  4. This solution is essentially a specialized version of the classic
     "count subarrays with sum >= k" pattern, optimized for k=1 and ±1
     steps using the incremental validLeftPoints trick.

  5. Compared to the prefix-sum + sorting/BIT approach (O(N log N)),
     this O(N) approach exploits the ±1 movement of cumSum — a constraint
     unique to this problem because we're mapping to exactly +1/-1.

================================================================================
*/

#include<bits/stdc++.h>
using namespace std;

// TC: O(N) — single pass through the array
// SC: O(N) — prefix sum frequency map (at most 2N+1 distinct keys)
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        // mpp[x] = how many times prefix sum x has been seen so far
        // Initialized with mpp[0] = 1 to account for the empty prefix
        // (this enables counting subarrays that start at index 0)
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        // cumSum = current prefix sum using +1/-1 encoding:
        //   +1 for target, -1 for non-target
        // Represents: count(target) - count(non-target) from index 0 to j
        int cumSum = 0;

        // validLeftPoints = number of previously seen prefix[i] values
        // such that prefix[i] < current cumSum
        // i.e., the number of valid left endpoints for a subarray ending at j
        // that satisfy the majority condition (sum >= 1)
        long long validLeftPoints = 0;

        long long result = 0;

        for(int j = 0; j < (int)nums.size(); j++){

            if(nums[j] == target){
                // cumSum is about to increase by 1.
                // The new valid threshold becomes cumSum+1.
                // Entries with prefix[i] == cumSum (current) now become valid.
                // So add mpp[cumSum] BEFORE incrementing.
                validLeftPoints += mpp[cumSum];
                cumSum += 1;
            } else {
                // cumSum is about to decrease by 1.
                // The new valid threshold becomes cumSum-1.
                // Entries with prefix[i] == cumSum-1 (= new cumSum) become invalid.
                // So decrement cumSum FIRST, then subtract mpp[cumSum].
                cumSum -= 1;
                validLeftPoints -= mpp[cumSum];
            }

            // Record the current prefix sum into the frequency map
            // (after updating cumSum, representing prefix[0..j])
            mpp[cumSum] += 1;

            // Each valid left endpoint i pairs with current j
            // to form a valid subarray [i+1 .. j]
            result += validLeftPoints;
        }

        return result;
    }
};

int main(){
    // Test 1: [1,2,2,3], target=2 → expected 5
    vector<int> nums1 = {1,2,2,3};
    Solution sol;
    cout << sol.countMajoritySubarrays(nums1, 2) << "\n"; // 5

    // Test 2: [1,1,1,1], target=1 → expected 10
    vector<int> nums2 = {1,1,1,1};
    cout << sol.countMajoritySubarrays(nums2, 1) << "\n"; // 10

    // Test 3: [1,2,3], target=4 → expected 0
    vector<int> nums3 = {1,2,3};
    cout << sol.countMajoritySubarrays(nums3, 4) << "\n"; // 0

    return 0;
}