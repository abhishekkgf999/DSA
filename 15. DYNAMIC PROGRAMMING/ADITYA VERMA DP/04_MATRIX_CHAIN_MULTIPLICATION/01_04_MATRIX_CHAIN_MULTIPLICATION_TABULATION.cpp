/*
# MATRIX CHAIN MULTIPLICATION (MCM) TABULATION

LINK:- https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/


#include<bits/stdc++.h>
using namespace std;

/*
Step 1: Identify the Base Cases

In your memoized solution, if (i == j) return 0; is the base case.
What does i == j mean in the dp table? It means we're looking at dp[x][x] (e.g., dp[1][1], dp[2][2], etc.).
If i == j, it's a chain of a single matrix, requiring 0 multiplications.
So, in our tabulation table, all dp[i][i] entries will be 0.


dp table:
   1 2 3 4 ... n-1
1  0 - - - ... -
2    0 - - ... -
3      0 - ... -
4        0 ... -
...
n-1            0


Step 2: Understand the Dependencies (Crucial for Order)

You saw that dp[i][j] depends on dp[i][k] and dp[k+1][j].
Graphically, if (i, j) is a cell we want to fill:

  * dp[i][k] is to its left (same row, smaller column).
  * dp[k+1][j] is below it (larger row, same column).

This means to calculate dp[i][j], you need values from:

  * Cells with the *same starting index* but *smaller ending index*.
  * Cells with *larger starting index* but *same ending index*.

This insight tells us how we *cannot* fill the table. We cannot fill row by row from top-left, nor column by column.

Step 3: The "Length" or "Gap" Strategy

Since dp[i][j] always depends on subproblems of *shorter length*, a natural way to fill the table is by increasing the length of the chain (or "gap" between i and j).

Let len be the length of the matrix chain we are considering (number of matrices).

  * len = 1: This means i = j. We already know dp[i][i] = 0.
  * len = 2: This means we have two matrices, say M_i and M_i+1. We need to calculate dp[i][i+1].
  * len = 3: We have three matrices, M_i, M_i+1, M_i+2. We need to calculate dp[i][i+2].
  * ... and so on, up to len = n-1 (the full chain).

Let's use gap or length as the variable for the difference j - i + 1.

Consider gap (or length) as the outermost loop:
*/

class Solution1 {
public:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {   // A chain of 1 matrix (gap=1) has 0 cost, handled by initialization.
            // A chain of N matrices means gap = N.
            // Our array indices go from 1 to n-1 (for actual matrices).
            // So, the maximum gap for a chain of (n-1) matrices is (n-1).
            for (int i = 1; i <= n - len; i++) {
                int j = i + len - 1;
                int mini = INT_MAX;
                for (int k = i; k < j; k++) {
                    int steps = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }
};


/*
  * i = n - 1 (largest i):

      * j goes from n down to n (no loop since j < n fails).
      * Actually, j starts from i+1. So if i = n-1, j starts from n. But j < n is n < n, which is false. So this loop does not run. This indicates that dp[n-1][n-1] would be the last element to calculate along the diagonal, which is a base case.

  * i = n - 2:

      * j goes from n - 1 to n - 1. We calculate dp[n-2][n-1].
          * Dependencies: dp[n-2][k] and dp[k+1][n-1].
          * Since k will be n-2, dp[n-2][n-2] (base case) and dp[n-1][n-1] (base case) are needed. These are already 0. So dp[n-2][n-1] is calculated correctly.

  * i = n - 3:

      * j goes from n - 2 to n - 1.
      * First, dp[n-3][n-2] is calculated (depends on base cases).
      * Then dp[n-3][n-1] is calculated.
          * Dependencies: dp[n-3][k] and dp[k+1][n-1].
          * k can be n-3 or n-2.
          * If k = n-3: dp[n-3][n-3] (base case) and dp[n-2][n-1] (calculated in previous i iteration).
          * If k = n-2: dp[n-3][n-2] (just calculated) and dp[n-1][n-1] (base case).
          * This also works\!

Why does the provided i and j loop order work?

This loop order fills the DP table diagonally, from bottom-right towards top-left (or more precisely, anti-diagonally).

Let's visualize the dp table:


    j ->
i   1   2   3   4   ... n-1
|
V
1   0   ?   ?   ?   ... Result
2       0   ?   ?   ... ?
3           0   ?   ... ?
4               0   ... ?
...
n-1                 0


  * The i loop starts from n-1 (bottom row) and goes up.
  * The j loop starts from i+1 (to the right of i's diagonal) and goes right.

When i is large and j is slightly larger, you are calculating values near the bottom-right corner of the *upper triangle* of the dp table. These values depend on cells that are either directly on the diagonal (base cases) or to their left/below, which would have been filled in previous i or j iterations.

This order ensures that when dp[i][j] is being computed, dp[i][k] and dp[k+1][j] (which represent smaller subproblems) have *already been computed*.

  * dp[i][k] means same row i, but k < j. So it's to the left.
  * dp[k+1][j] means same column j, but k+1 > i. So it's below.

Since i decreases and j increases (for a fixed i), you are effectively processing subproblems of increasing length (or increasing "gap" j-i).

      * Option B (As in the provided code - Diagonal/Anti-Diagonal):
          * "I need dp[i][k] and dp[k+1][j]. This means (i,j) depends on values to its left in the same row, and values below it in the same column."
          * To ensure dp[i][k] is computed, i should be processed *before* j (for fixed i), or j should be processed *before* k (for fixed i). This suggests processing columns from left to right, or rows from top to bottom.
          * However, the *other* dependency dp[k+1][j] means k+1 > i. This suggests processing rows from *bottom to top* (i decreasing).
          * Combining these: Process i from n-1 down to 1. Then for each i, process j from i+1 up to n-1. This fills the table anti-diagonally, ensuring all dependencies are met.
*/

class Solution2 {
public:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        // Create a 2D dp table initialized to 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = INT_MAX;
                for (int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    if (steps < mini) mini = steps;
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};


int main() {
    vector<int> arr = { 2, 1, 3, 4 };
    Solution2 obj;
    cout << obj.matrixMultiplication(arr);
    return 0;
}