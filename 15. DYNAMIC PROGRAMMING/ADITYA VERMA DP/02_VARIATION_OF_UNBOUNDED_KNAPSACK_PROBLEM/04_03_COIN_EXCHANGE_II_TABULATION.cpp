/*
#COIN EXCHANGE I (RECURSION)

LINK:- https://leetcode.com/problems/coin-change-ii/description/

*/

/*
INTUITION:
1. We use recursion with memoization to count the number of ways to form the target amount using the given coins.
2. A 2D dp table of size (n+1) x (amount+1) is used to store the results of subproblems, where dp[n][amount] represents the number of ways to make up
   'amount' using the first 'n' coins.
3. If a subproblem has already been solved, we return its stored value to avoid redundant calculations.
4. Otherwise, we compute it, store it in dp, and return the result.

APPROACH:
1. Base Case:
   - If only one coin is left (n == 1), we check if the amount is divisible by coins[0].
     If yes, we can form the amount using just this coin repeatedly → return 1;
     otherwise, it's not possible → return 0.

2. Choice 1: Take the current coin (if its value ≤ amount):
   - Recurse with the same coin and reduced amount.

3. Choice 2: Skip the current coin:
   - Recurse with the remaining coins (n - 1) and the same amount.

4. Store and return the sum of both choices in dp[n][amount].

COMPLEXITY:
- Time: O(n * amount), because we solve each subproblem only once.
- Space: O(n * amount) for the dp table + O(n + amount) recursion stack in the worst case.
*/



#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) {
            dp[1][j] = (j % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                unsigned long long notTake = dp[i - 1][j];
                unsigned long long take = 0;
                if (coins[i - 1] <= j) {
                    take = dp[i][j - coins[i - 1]];
                }

                dp[i][j] = (take + notTake > INT_MAX) ? INT_MAX : take + notTake;
            }
        }

        return (int)(dp[n][amount]);

    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case
        for (int j = 0; j <= amount; j++) {
            dp[0][j] = (j % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (coins[i] <= j)
                    take = dp[i][j - coins[i]];
                dp[i][j] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};

class Solution3 {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};


int main()
{
    vector<int> coins = { 1, 2, 5 };
    int amount = 5;
    Solution obj;
    cout << obj.change(amount, coins);
    return 0;
}