/*
#WORD BREAK

LINK:- https://leetcode.com/problems/word-break-ii/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*
Problem: Find ALL possible ways to segment string into dictionary words.

Approach: Backtracking - try all possible word combinations.

Algorithm:
1. At each position idx: Try making cuts at different positions (i = idx to end)
2. For each potential substring s[idx...i]:
   - Check if it exists in dictionary
   - If yes → add to current segmentation, recurse for remaining string s[i+1...]
   - Backtrack → remove the word and try next possibility
3. Base case: Reached end of string → found a complete valid segmentation
4. Format output: Convert each segmentation (vector of words) to space-separated string

Key Steps:
- s.substr(idx, i - idx + 1) → extract potential word
- dict.count(sub) → check if word exists in dictionary
- temp.push_back(sub) → add word to current segmentation
- solve(s, dict, i + 1, result, temp) → recursively segment remaining string
- temp.pop_back() → backtrack to try other possibilities

Example: s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"]
- Path 1: "cats" + "and" + "dog"
- Path 2: "cat" + "sand" + "dog"

Time: O(2^n) - exponential due to exploring all possible segmentations
Space: O(n) recursion depth
*/
class Solution_backtracking {
public:
    void solve(string s, unordered_set<string>& dict, int idx, vector<vector<string>>& result, vector<string>& temp) {
        if (idx == s.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (dict.count(sub)) {
                temp.push_back(sub);
                solve(s, dict, i + 1, result, temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> result;
        vector<string> temp;
        vector<string> ans;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        solve(s, dict, 0, result, temp);

        for (int i = 0; i < result.size(); i++) {
            string temp = "";
            for (int j = 0; j < result[i].size(); j++) {
                temp += " " + result[i][j];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};


/*
Word Break II - Recursive Logic:

Problem: Find ALL possible ways to segment string into dictionary words.

Approach: Pure recursion - divide and conquer approach.

Algorithm:
1. Base case: If string is empty, return {""} (one way to segment empty string)
2. Try all possible first words: For each prefix of length 1 to n
   - Extract currWord = s[0...l-1]
   - If currWord exists in dictionary:
     - Get all ways to segment remaining string s[l...]
     - Combine currWord with each way from remaining string
     - Add to result
3. Return all valid segmentations

Key Steps:
- s.substr(0, l) → try first word of length l
- solve(remainWord, dict) → recursively get all ways to segment rest
- currWord + " " + w → combine current word with each remaining segmentation
- Handle empty string case when concatenating

Example: s = "catsand", dict = ["cat", "cats", "and", "sand"]
- Try "cat": solve("sand") returns ["sand"] → result: ["cat sand"]
- Try "cats": solve("and") returns ["and"] → result: ["cats and"]

Difference from backtracking: Instead of building one path at a time, this recursively gets ALL possible ways for subproblems and combines them.

Time: O(2^n) - exponential
Space: O(2^n) for storing all results
*/
class Solution_recursive_way {
public:
    vector<string> solve(string s, unordered_set<string>& dict) {

        if (s.empty()) {
            return { "" };
        }

        vector<string> result;

        for (int l = 1; l <= s.size(); l++) {
            string currWord = s.substr(0, l);
            if (dict.count(currWord)) {
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord, dict);
                for (string& w : remainResult) {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }

        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return solve(s, dict);
    }
};


class Solution_memoization {
public:
    unordered_map<string, vector<string>> mp;
    vector<string> solve(string s, unordered_set<string>& dict) {

        if (s.empty()) {
            return { "" };
        }

        if (mp.count(s)) {
            return mp[s];
        }

        vector<string> result;

        for (int l = 1; l <= s.size(); l++) {
            string currWord = s.substr(0, l);
            if (dict.count(currWord)) {
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord, dict);
                for (string& w : remainResult) {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }

        return mp[s] = result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return solve(s, dict);
    }
};

int main() {
    string s = "catsanddog";
    vector<string> dict = { "cat","cats","and","sand","dog" };
    Solution_backtracking obj;
    vector<string> ans = obj.wordBreak(s, dict);
    for (auto i : ans) cout << i << ", ";
    return 0;
}