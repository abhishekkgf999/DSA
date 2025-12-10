/*
#MINIMUM INSERTION STEPS TO MAKE A STRING PALINDROME

LINK :- https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
if we find a longest common palindromic subsequence in given string, and subtract it from given string length,
then it is giving us the minimum insertion steps to make a string palindrome

A palindromic subsequence is already in the right order.
Only the remaining characters (not part of it) need to be inserted — at the appropriate positions — to form a complete palindrome.

So, the fewer the characters outside the LPS, the fewer insertions we need.

means that, a palindromic subsequence is already a palindrome, we need to just add those remaining character again to make it palindrome


✅ Example:
Let’s take a string:
s = "abcda"

reverse(s) = "adcba"

LPS = "aba" (or "aca", both length 3)

👉 Minimum insertions = len(s) - len(LPS) = 5 - 3 = 2

We insert two characters (e.g., a 'c' and a 'b') at appropriate positions to make it a palindrome.
*/

class Solution {
public:
    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return  (s1.size() - dp[n][m]);
    }
};

int main() {
    string s = "zzazz";
    Solution obj;
    cout << obj.minInsertions(s);
    return 0;
}