/*
#CLIMB STAIRS

LINK:- https://leetcode.com/problems/climbing-stairs/description/
*/

#include<bits/stdc++.h>
using namespace std;

//time complexity :- O(2^n)
//space complexity :- O(n) due to recursion stack depth
//same logic as fibonacci sequence
class Solution_recursion {
public:
    int climbStairs(int n) {

        if (n < 0) return 0;

        if (n == 0 || n == 1) return 1;


        int count = climbStairs(n - 1) + climbStairs(n - 2);

        return count;
    }
};

//time complexity :- O(n);
//space complexity :- O(n) + O(n) -> due to recursion stack depth
class Solution_memoization {
public:
    int solve(int n, vector<int>& dp) {

        if (n < 0) return 0;

        if (n == 0 || n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};

class Solution_tabulation {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 1; dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class Solution_tabulation_with_space_optimization {
public:
    int climbStairs(int n) {
        int curr = 0;

        int prev1 = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;

            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

int main() {
    Solution_tabulation_with_space_optimization obj;
    cout << obj.climbStairs(5);
    return 0;
}