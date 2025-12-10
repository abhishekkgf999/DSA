/*
#ROD CUTTING PROBLEM

LINK :- https://www.geeksforgeeks.org/problems/rod-cutting0840/1

*/

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution_recursion {
public:
    int solve(vector<int>& price, int L, int n) {
        if (n == 1) return price[0] * L;

        int take_that_piece = 0;
        if (n <= L) {
            take_that_piece = price[n - 1] + solve(price, L - n, n);
        }

        int not_take_that_piece = solve(price, L, n - 1);

        return max(take_that_piece, not_take_that_piece);
    }
    int cutRod(vector<int>& price) {
        // code here
        int L = price.size();
        int n = L;
        return solve(price, L, n);
    }
};

// User function Template for C++

class Solution_memoization {
public:
    int solve(vector<int>& price, int L, int n, vector<vector<int>>& dp) {
        if (n == 1) return price[0] * L;


        if (dp[n][L] != -1) return dp[n][L];

        int take_that_piece = 0;
        if (n <= L) {
            take_that_piece = price[n - 1] + solve(price, L - n, n, dp);
        }

        int not_take_that_piece = solve(price, L, n - 1, dp);

        return dp[n][L] = max(take_that_piece, not_take_that_piece);
    }
    int cutRod(vector<int>& price) {
        // code here
        int L = price.size();
        int n = L;
        vector<vector<int>> dp(n + 1, vector<int>(L + 1, -1));
        return solve(price, L, n, dp);
    }
};

// User function Template for C++

class Solution_tabulation {
public:
    int cutRod(vector<int>& price) {
        // code here
        int L = price.size();
        int n = L;
        vector<vector<int>> dp(n + 1, vector<int>(L + 1, 0));

        for (int j = 0; j <= L; j++) {
            dp[1][j] = price[0] * j;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= L; j++) {
                int not_take = dp[i - 1][j];
                int take = 0;
                if (i <= j) {
                    take = price[i - 1] + dp[i][j - i];
                }

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[n][L];
    }
};


// User function Template for C++

class Solution_tabulation_space_optimized {
public:
    int cutRod(vector<int>& price) {
        // code here
        int L = price.size(); // Total rod length
        vector<int> dp(L + 1);

        for (int cutLen = 1; cutLen <= L; cutLen++) {
            for (int rodLen = cutLen; rodLen <= L; rodLen++) {
                dp[rodLen] = max(dp[rodLen], price[cutLen - 1] + dp[rodLen - cutLen]);
            }
        }

        return dp[L];
    }
};

int main() {
    vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
    Solution_tabulation_space_optimized obj;
    cout << obj.cutRod(price);
    return 0;
}