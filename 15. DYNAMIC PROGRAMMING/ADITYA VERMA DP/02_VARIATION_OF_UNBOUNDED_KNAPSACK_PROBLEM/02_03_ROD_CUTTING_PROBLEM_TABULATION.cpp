/*
#ROD CUTTING PROBLEM (bOTTOM-UP TABULATION)

LINK:- https://www.geeksforgeeks.org/problems/rod-cutting0840/1

*/

/*
# INTUITION
1. Since both the rod length (L) and the piece index (n) vary during recursion, we need a 2D DP table to store solutions for each unique (n, L) state.

2. This avoids redundant computations by reusing previously solved subproblems.

3. We start by initializing the first row (n == 1) with base values:  i.e., using only piece length 1, the best we can do is price[0] * j.

4. The rest of the DP table is initialized to 0 and filled iteratively.

5. The outer loop represents the available piece lengths (from 2 to n), and the inner loop represents current rod lengths (from 0 to L).

# APPROACH
1. Create a 2D DP array of size (n + 1) × (L + 1), initialized to 0:
   vector<vector<int>> dp(n + 1, vector<int>(L + 1, 0));

2. Base Case:
   dp[1][j] = price[0] * j; // only 1-length cuts available

3. Fill the rest of the DP table:
   For i from 2 to n (piece lengths)
       For j from 0 to L (rod lengths)
           if (i <= j): // piece can be included
               take = price[i - 1] + dp[i][j - i];
           not_take = dp[i - 1][j];
           dp[i][j] = max(take, not_take);

# COMPLEXITY
- Time Complexity: O(n × L) — each (n, L) state is computed once
- Space Complexity: O(n × L) — for the DP table
*/

#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price)
{
    int L = price.size(); // Total rod length
    vector<vector<int>> dp(L + 1, vector<int>(L + 1, 0));

    // Base case: Only cut size 1 is available
    for (int j = 0; j <= L; j++)
    {
        dp[1][j] = price[0] * j;
    }

    // Build the DP table
    for (int i = 2; i <= L; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            int take = 0;
            if (i <= j)
            {
                take = price[i - 1] + dp[i][j - i];
            }
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }

    return dp[L][L]; // Max value using all cut lengths for full rod
}

int cutRod2(vector<int> &price)
{
    int L = price.size(); // Total rod length

    vector<int> dp(L + 1);

    for (int i = 1; i <= L; i++)
    {
        for (int j = i; j <= L; j++)
        {
            dp[j] = max(dp[j], price[i - 1] + dp[j - i]);
        }
    }

    return dp[L];
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    cout << endl;
    cout << cutRod2(price);
    return 0;
}