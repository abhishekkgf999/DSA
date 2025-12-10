/*
#PALINDROME PARTITIONING

LINK :- https://leetcode.com/problems/palindrome-partitioning/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O((2^n)*n)
class Solution_backtracking {
public:
    bool check(int start, int end, string s) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(string& s, int idx, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx >= s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (check(idx, i, s)) {
                string t = s.substr(idx, i - idx + 1);
                temp.push_back(t);
                solve(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(s, 0, temp, ans);
        return ans;
    }
};

class Solution_dp {
public:
    void solve(string& s, int idx, vector<string>& temp, vector<vector<bool>>& dp, vector<vector<string>>& ans) {
        if (idx >= s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (dp[idx][i] == true) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, temp, dp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) dp[i][i] = true;

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, dp, ans);
        return ans;
    }
};



int main() {
    Solution_dp obj;
    vector<vector<string>> ans = obj.partition("aab");
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}