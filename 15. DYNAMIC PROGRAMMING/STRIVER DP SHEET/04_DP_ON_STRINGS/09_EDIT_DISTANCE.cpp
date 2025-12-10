/*
#EDIT DISTANCE

LINK:- https://leetcode.com/problems/edit-distance/

*/

#include<bits/stdc++.h>
using namespace std;

/*
#The logic is simple: you compare the two words character by character, from left to right.

1. If the characters match: Great! You don't need to do anything for that character. You just move on to the next one in both words.

2. If they don't match: You have three choices, and you have to pick the one that will lead to the fewest total changes.

    a. Delete: Remove the character from the first word and see what's the shortest way to match the rest of the second word.

    b. Insert: Insert the character from the second word into the first word and see what's the shortest way to match the rest of the words.

    c. Replace: Change the character in the first word to match the one in the second word, and then see what's the shortest way to match the remaining parts of both words.

You add 1 for the operation you just performed and then take the minimum of the three outcomes.
You repeat this process for all possible sub-problems, and the final answer is the minimum number
of operations to turn the whole first word into the whole second word.
*/

//recursion will take O(3^(m+n))
//memoizaion will take O(n*m) time complexity
//space complexity :- O(n*m) -> dp + O(n+m)
class Solution_memoization {
public:
    int solve(string s1, int n, string s2, int m, vector<vector<int>> dp) {
        if (m == 0) return n;
        if (n == 0) return m;

        if (dp[n][m] != -1) return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = solve(s1, n - 1, s2, m - 1, dp);
        }
        else {
            int insertOp = solve(s1, n, s2, m - 1, dp);
            int deleteOp = solve(s1, n - 1, s2, m, dp);
            int replaceOp = solve(s1, n - 1, s2, m - 1, dp);

            return dp[n][m] = 1 + min({ insertOp, deleteOp, replaceOp });
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(word1, n, word2, m, dp);
    }
};


//time and space complexity :- O(n*m)
class Solution_tabulation {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({ insertOp, deleteOp, replaceOp });
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    string s1 = "prosperity";
    string s2 = "properties";
    Solution_memoization obj;
    cout << obj.minDistance(s1, s2);
    return 0;
}