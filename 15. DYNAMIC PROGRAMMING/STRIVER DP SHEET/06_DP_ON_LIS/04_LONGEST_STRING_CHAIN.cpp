/*
#LONGEST STRING CHAIN

LINK:- https://leetcode.com/problems/longest-string-chain/
*/

#include<bits/stdc++.h>
using namespace std;

/*
Simple Logic for Longest String Chain:

Problem: Find the longest chain of words where each word is formed by adding exactly one character to the previous word.

Approach: Pick/Not-pick recursion with constraint checking

Steps:
1. Sort by length - shorter words must come before longer words in a valid chain
2. At each word: Two choices:
   - Skip it - don't include in current chain
   - Pick it - only if it can extend current chain (either first word or follows chain rule)
3. Chain rule: Current word can follow previous word if it has exactly one more character and can be formed by inserting one character into previous word
4. Return maximum of both choices

Key insight:
- isEqual(s1, s2) checks if s2 can be formed by adding exactly one character to s1
- After sorting by length, we only need to check consecutive valid extensions
- Similar to LIS but with string predecessor relationship instead of numerical comparison

Base case: Processed all words → return 0
Result: Length of longest valid chain found

Time: O(2^n) without memoization
Space: O(n) recursion stack
*/

class Solution_recursion {
public:
    static bool comp(const string& a, const string& b) {
        return a.size() < b.size();
    }

    bool isEqual(string s1, string s2) {
        if (s2.size() - s1.size() != 1)
            return false;

        int i = 0, j = 0, diff = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                diff++;
                if (diff > 1)
                    return false;
                j++;
            }
        }
        return true;
    }
    int solve(vector<string>& words, int i, string& last_picked) {
        if (i == words.size()) {
            return 0;
        }

        int not_pick = solve(words, i + 1, last_picked);
        int pick = 0;
        if (last_picked.empty() || isEqual(last_picked, words[i])) {
            pick = 1 + solve(words, i + 1, words[i]);
        }

        return max(pick, not_pick);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        string temp = "";
        return solve(words, 0, temp);
    }
};

/*
Connection to LIS: This is exactly the same pattern as Longest Increasing Subsequence,
but instead of checking nums[j] < nums[i], we check isEqual(words[j], words[i]).

DP Definition:
- dp[i] = length of longest string chain ending at index i

Algorithm:
1. Sort by length - ensures shorter words come before longer words (like sorting numbers in LIS)
2. For each word i: Check all previous words j (where j < i)
3. If isEqual(words[j], words[i]): Can extend chain ending at j
   - Update: dp[i] = max(dp[i], dp[j] + 1)
4. Answer: Maximum value in entire dp array

Key Similarity to LIS:
- LIS: if(nums[j] < nums[i]) → can extend sequence
- String Chain: if(isEqual(words[j], words[i])) → can extend chain
- Same DP structure: build optimal solution for each position using previous results

Why it works:
- After sorting by length, we ensure valid chain order
- Each dp[i] represents the longest chain ending at position i
- We check all possible predecessors and take the best one

Time: O(n² × m) where m = average string length
Space: O(n)
*/
class Solution_tabulation {
public:
    static bool comp(const string& a, const string& b) {
        return a.size() < b.size();
    }

    bool isEqual(string s1, string s2) {
        if (s2.size() - s1.size() != 1)
            return false;

        int i = 0, j = 0, diff = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                diff++;
                if (diff > 1)
                    return false;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isEqual(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    vector<string> words = { "a","b","ba","bca","bda","bdca" };
    Solution_recursion obj;
    cout << obj.longestStrChain(words);
    return 0;
}