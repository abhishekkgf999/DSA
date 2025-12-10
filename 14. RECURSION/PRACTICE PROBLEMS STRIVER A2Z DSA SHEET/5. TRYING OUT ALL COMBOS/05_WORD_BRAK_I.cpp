/*
#WORD BREAK

LINK:- https://leetcode.com/problems/word-break/
*/

#include<bits/stdc++.h>
using namespace std;

/*
👉 Idea: Try to break the string at every index. If the prefix is in wordDict, recurse on the remaining string.
*/
//TIME COMPLEXITY :- O(N^2)
class Solution_MEMOIZATION {
public:
    bool solve(string s, unordered_set<string>& dict, int idx, vector<int>& dp) {
        if (idx == s.size()) {
            return true;
        }

        if (dp[idx] != -1) return dp[idx];

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (dict.count(sub) && solve(s, dict, i + 1, dp)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(s, dict, 0, dp);
    }
};

/*
Problem: Check if string can be segmented into words from dictionary.

DP Definition: dp[i] = true if substring s[0...i-1] can be segmented using dictionary words.

Algorithm:
1. Base case: dp[0] = true (empty string can always be segmented)
2. For each position i (1 to n): Check if we can form valid segmentation ending at position i
3. Try all possible split points j (0 to i-1):
   - If dp[j] is true (prefix s[0...j-1] can be segmented)
   - AND s[j...i-1] exists in dictionary
   - Then dp[i] = true
4. Answer: dp[n] (can entire string be segmented?)

Key Insight:
- dp[j] represents if prefix before position j is valid
- s.substr(j, i-j) is the word from position j to i-1
- We need BOTH conditions: valid prefix + current word in dictionary
*/
class Solution_tabulation {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true; // base case: empty string

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // no need to check further if already true
                }
            }
        }
        return dp[n];
    }
};


int main() {
    string s = "leetcode";
    vector<string> dict = { "leet", "code" };
    Solution_MEMOIZATION obj;
    cout << obj.wordBreak(s, dict);
    return 0;
}