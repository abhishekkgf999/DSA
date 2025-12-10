/*
#COIN EXCHANGE I (RECURSION)

LINK:- https://leetcode.com/problems/coin-change-ii/description/

*/

/*
INTUITION:
1. We are given an unlimited supply of each type of coin, so we can use any coin multiple times to make up the target amount.

2. This is a classic case of the Unbounded Knapsack problem, where each coin can be chosen repeatedly.

3. If the current coin value is less than or equal to the remaining amount, we have the option to include it and try again with the same coin.

4. Alternatively, we can skip the current coin and move to the next one.

5. When we are left with only one coin type, we simply check if the amount can be fully formed using just this coin. This can be done using modulus.

APPROACH:
1. Base Case:
   If only one coin is available (n == 1), check whether the remaining amount is divisible by that coin.
   If yes, return 1 (one valid way); otherwise, return 0.

2. Try including the current coin (if it doesn't exceed the remaining amount):
   - Recurse with the same coin and reduced amount.

3. Try excluding the current coin:
   - Recurse with the previous coin and the same amount.

4. Total number of ways to form the amount is the sum of both choices.

COMPLEXITY:
- Time: O(2^n) in the worst case due to overlapping subproblems and exponential branching.
- Space: O(amount + n) due to the recursive call stack (without memoization).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int solve(int amount, vector<int>& coins, int n) {
        if (n == 1) {
            return (amount % coins[0] == 0);
        }

        int take = 0;
        if (coins[n - 1] <= amount) {
            take += solve(amount - coins[n - 1], coins, n);
        }

        int notTake = solve(amount, coins, n - 1);

        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(amount, coins, n);
    }
};


class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins) {
        if (ind == 0) return (amount % coins[0] == 0);

        int notTake = solve(ind - 1, amount, coins);
        int take = 0;
        if (coins[ind] <= amount)
            take = solve(ind, amount - coins[ind], coins);

        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n - 1, amount, coins);
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