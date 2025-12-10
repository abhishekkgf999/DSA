/*
#DELETE OPERATION FOR TWO STRINGS

LINK :- https://leetcode.com/problems/delete-operation-for-two-strings/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*
🧠 Intuition:
LCS represents the part of both strings you don’t want to delete.

So:

From word1, delete everything except the LCS ⇒ len1 - lcs deletions

From word2, delete everything except the LCS ⇒ len2 - lcs deletions

Total deletions = deletions from both

*/
class Solution {
public:
    int minDistance(string s1, string s2) {
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

        return (n - dp[n][m]) + (m - dp[n][m]);
    }
};

int main() {
    string s1 = "dinitrophenylhydrazine";
    string s2 = "benzalphenylhydrazone";
    Solution obj;
    cout << obj.minDistance(s1, s2);
    return 0;
}