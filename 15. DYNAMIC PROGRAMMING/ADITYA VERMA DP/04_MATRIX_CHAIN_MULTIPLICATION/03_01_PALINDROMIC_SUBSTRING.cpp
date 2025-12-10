/*
#PALINDROMIC SUBSTRINGS

LINK :- https://leetcode.com/problems/palindromic-substrings/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_MEMO {
public:
    bool check(string s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = check(s, i + 1, j - 1, dp);
        }

        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j, dp)) count++;
            }
        }

        return count;
    }
};


//BLUPRINT TO SOLVE MANY PROBLEMS
//KHANDANI TEMPLATE
/*
This solution uses tabulation (bottom-up DP) to count all palindromic substrings in the string.
It builds a 2D table dp[i][j] where each entry stores whether the substring s[i..j] is a palindrome.
It handles all substring lengths from 1 to n, checking characters and previously computed results to fill the table.
The overall time and space complexity is O(n²).
*/
class Solution_TABU {
public:
    int countSubstrings(string s) {
        int n = s.length();

        // dp[i][j] will be true if substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        // L is the length of the substring
        for (int L = 1; L <= n; L++) {
            // i is the starting index of the substring
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1; // j is the ending index of the substring

                // Case 1: Single character is always a palindrome
                if (i == j) dp[i][j] = true;

                // Case 2: Two-character substrings are palindrome if both characters are equal
                else if (i + 1 == j) dp[i][j] = (s[i] == s[j]);

                // Case 3: For longer substrings, check first and last characters, and the middle substring
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);

                // If current substring is palindrome, increment count
                if (dp[i][j]) count++;
            }
        }

        return count;
    }
};

int main() {
    string s = "abc";
    Solution_MEMO obj1;
    cout << obj1.countSubstrings(s) << endl;

    Solution_TABU obj2;
    cout << obj2.countSubstrings(s) << endl;
    return 0;
}