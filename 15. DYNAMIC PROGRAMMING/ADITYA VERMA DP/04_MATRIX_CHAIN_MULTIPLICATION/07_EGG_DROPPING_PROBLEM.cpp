/*
#SUPER-EGG

LINK:- https://leetcode.com/problems/super-egg-drop/description/
*/

/*
### Super Egg Drop Problem - Revision Note

Problem: Find the minimum number of moves to find the "critical floor" (highest floor from which an egg will not break) given E eggs and F floors.

---

### 1. Recursive Approach (Brute Force)

* State: solve(eggs, floors) returns the minimum moves.
* Thought Process:
    * To find the critical floor in F floors with E eggs, we must choose a floor k to drop the egg from (1 to F).
    * Case 1 (Egg Breaks): We lose 1 egg (E-1) and search k-1 floors below. Cost: solve(E-1, k-1).
    * Case 2 (Egg Doesn't Break): We keep all eggs (E) and search F-k floors above. Cost: solve(E, F-k).
    * We want the *worst-case* outcome for a chosen k, so we take max(Case1, Case2).
    * Since we want the *minimum* total moves, we iterate k from 1 to F and take the min of 1 + max(cost_break, cost_not_break).
* Base Cases:
    * floors == 0: 0 moves.
    * floors == 1: 1 move.
    * eggs == 1: floors moves (linear search from bottom).

---

### 2. Memoized Approach (Top-Down DP)

* Concept: Optimize recursion by storing results of solved subproblems in a dp table/map to avoid re-computation.
* State: dp[eggs][floors] stores the minimum moves. Initialize with -1.
* Thought Process: Same as recursive approach, but add:
    * Check Memo: Before computing solve(eggs, floors), check if dp[eggs][floors] is already calculated. If so, return it.
    * Store Result: After computing min_moves, store dp[eggs][floors] = min_moves before returning.

---

### 3. Tabulation Approach (Bottom-Up DP)

* Concept: Build the dp table iteratively from base cases up to the desired dp[E][F].
* State: dp[i][j] = min moves for i eggs and j floors.
* Thought Process:
    * Initialize dp table:
        * dp[1][j] = j for all j (1 egg, linear search).
        * dp[i][0] = 0 (0 floors, 0 moves).
        * dp[i][1] = 1 (1 floor, 1 move).
    * Fill table:
        * Outer loops: i from 2 to E (eggs), j from 2 to F (floors).
        * Inner loop: k from 1 to j (floor to drop from).
        * dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][k-1], dp[i][j-k])).

---

### 4. Tabulation with Binary Search

* Concept: The max(dp[i-1][k-1], dp[i][j-k]) function: dp[i-1][k-1] is increasing with k, dp[i][j-k] is decreasing with k. The minimum of their maximum occurs when they are roughly equal. This allows binary search for optimal k.
* State: dp[i][j] = min moves for i eggs and j floors.
* Thought Process:
    * Same base cases and outer loops as standard tabulation.
    * Crucial Change: Instead of linear scan for k (inner loop), use binary search on k within [1, j].
    * In binary search:
        * mid = low + (high - low) / 2.
        * cost_break = dp[i-1][mid-1]
        * cost_not_break = dp[i][j-mid]
        * current_cost = 1 + max(cost_break, cost_not_break)
        * Update dp[i][j] with min(dp[i][j], current_cost).
        * Adjust search range:
            * If cost_break < cost_not_break: Try low = mid + 1 (to increase cost_break or decrease cost_not_break to balance).
            * Else (cost_break >= cost_not_break): Try high = mid - 1 (to decrease cost_break or increase cost_not_break to balance).


---

### Alternative Optimization :

* Concept: Redefine DP state to dp[m][e] = maximum floors testable with e eggs in m moves.
* Thought Process:
    * If you make 1 move:
        * If egg breaks: You have e-1 eggs and m-1 moves left to test floors below. dp[m-1][e-1] floors can be covered.
        * If egg doesn't break: You have e eggs and m-1 moves left to test floors above. dp[m-1][e] floors can be covered.
    * Total floors covered: dp[m][e] = 1 (current floor) + dp[m-1][e-1] + dp[m-1][e].
    * Iterate m (moves) from 1 upwards. The answer is the first m where dp[m][E] >= F.

*/


#include<bits/stdc++.h>
using namespace std;

//RECUSIION
//TIME COMPLEXITY :- 
//SPACE COMPLEXITY :- 
class Solution_recursion {
public:
    int superEggDrop(int e, int f) {
        if (f == 0 || f == 1) return f;

        if (e == 1) return f;

        int mini = INT_MAX;

        for (int k = 1; k <= f; k++) {
            int temp = 1 + max(superEggDrop(e - 1, f - 1), superEggDrop(e, f - 1));

            mini = min(mini, temp);
        }

        return mini;
    }
};

//MEMOIZED 
class Solution_Memoization {
public:
    int solve(int e, int f, vector<vector<int>>& dp) {
        if (f == 0 || f == 1)
            return f;

        if (e == 1)
            return f;

        if (dp[e][f] != -1) return dp[e][f];

        int mini = INT_MAX;

        for (int k = 1; k <= f; k++) {
            int break_case = (dp[e - 1][k - 1] != -1) ? dp[e - 1][k - 1] : solve(e - 1, k - 1, dp);
            int not_break_case = (dp[e][f - k] != -1) ? dp[e][f - k] : solve(e, f - k, dp);
            int temp = 1 + max(break_case, not_break_case);

            mini = min(mini, temp);
        }

        return dp[e][f] = mini;
    }

    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
        return solve(e, f, dp);
    }
};

//TABULATION
class Solution_Tabulation {
public:
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e + 1, vector<int>(f + 1, 0));

        for (int j = 1; j <= f; j++) {
            dp[1][j] = j;
        }

        for (int i = 1; i <= e; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int i = 2; i <= e; i++) {
            for (int j = 2; j <= f; j++) {
                int mini = INT_MAX;

                for (int k = 1; k <= j; k++) {
                    int break_case = dp[i - 1][k - 1];
                    int not_break_case = dp[i][j - k];
                    int temp = 1 + max(break_case, not_break_case);
                    mini = min(mini, temp);
                }

                dp[i][j] = mini;
            }
        }

        return dp[e][f];
    }
};

//TABULATION + BINARYSEARCH
class Solution_Tabulation_with_Binary_search {
public:
    int superEggDrop(int e, int f) {
        // dp[i][j] represents the minimum number of moves needed with 'i' eggs
        // to find the critical floor among 'j' floors.
        std::vector<std::vector<int>> dp(e + 1, std::vector<int>(f + 1, 0));

        // Base cases:
        // If 1 egg (i=1), in worst case, you have to try each floor from 1 to j.
        for (int j = 1; j <= f; j++) {
            dp[1][j] = j;
        }

        // If 0 or 1 floor (j=0 or j=1), you need 0 or 1 attempt respectively, regardless of eggs.
        for (int i = 1; i <= e; i++) {
            dp[i][0] = 0; // 0 floors, 0 attempts
            dp[i][1] = 1; // 1 floor, 1 attempt
        }

        // Fill the DP table
        // i: number of eggs (from 2 to e)
        // j: number of floors (from 2 to f)
        for (int i = 2; i <= e; i++) {
            for (int j = 2; j <= f; j++) {
                int mini = INT_MAX;

                // Use binary search for 'k' instead of linear scan
                // k represents the floor we are currently dropping the egg from (1 to j)
                int low = 1, high = j;
                int current_min_for_jf_eggs_i = INT_MAX; // Store min for this dp[i][j]

                while (low <= high) {
                    int mid = low + (high - low) / 2; // Current floor to test

                    // Case 1: Egg breaks at 'mid' floor
                    // We lose one egg (i-1) and need to check floors below 'mid' (k-1)
                    int break_cost = dp[i - 1][mid - 1];

                    // Case 2: Egg does not break at 'mid' floor
                    // We keep all eggs (i) and need to check floors above 'mid' (j-k)
                    int not_break_cost = dp[i][j - mid];

                    // The number of moves in this worst-case scenario (for this 'mid')
                    // is 1 (for the current drop) + max of the two subproblems.
                    int temp_cost = 1 + std::max(break_cost, not_break_cost);

                    // Update minimum moves for dp[i][j]
                    current_min_for_jf_eggs_i = std::min(current_min_for_jf_eggs_i, temp_cost);

                    // Adjust binary search range:
                    // If egg breaks cost is less than or equal to not-break cost,
                    // it means we might need to test a lower 'mid' floor to reduce the 'not_break_cost'.
                    // Or, the increasing function (break_cost) is "too low", so we need to move 'mid' up to balance.
                    if (break_cost <= not_break_cost) {
                        low = mid + 1; // Try higher floors to find the optimal balance
                    }
                    else {
                        high = mid - 1; // Try lower floors
                    }
                }
                dp[i][j] = current_min_for_jf_eggs_i;
            }
        }

        return dp[e][f];
    }
};

int main() {
    int e = 2, f = 4;
    Solution_Tabulation_with_Binary_search obj;
    cout << obj.superEggDrop(e, f);
    return 0;
}