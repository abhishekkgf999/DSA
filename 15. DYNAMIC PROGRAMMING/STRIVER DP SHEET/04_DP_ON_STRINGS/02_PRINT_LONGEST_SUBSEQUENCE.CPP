/*
#PRINT LONGEST SUBSEQUENCE

LINK :-
*/

#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    // Reconstruct the LCS string
    int i = n, j = m;
    string str = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            str += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(str.begin(), str.end()); // Since we built the string backwards

    cout << str << endl;
}

int main() {
    string s1 = "abcde";
    string s2 = "bdgek";

    cout << "The Longest Common Subsequence is ";
    lcs(s1, s2);
}
