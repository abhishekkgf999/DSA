/*
#EXTRA CHARACTERS IN A STRING

LINK :- https://leetcode.com/problems/extra-characters-in-a-string/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
Problem: Find minimum number of extra characters when breaking string using dictionary words.

Approach: Try all possible ways to partition the string and pick the one with minimum extra characters.

Algorithm:
1. At each position idx: Try making cuts at all possible positions (i = idx to end)
2. For each substring s[idx...i]:
   - If substring exists in dictionary → 0 extra characters
   - If substring doesn't exist in dictionary → all characters are extra (sub.size())
3. Recursively solve for remaining string s[i+1...]
4. Take minimum of all possible partitions

Key Steps:
- s.substr(idx, i-idx+1) → try substring from idx to i
- dict.find(sub) == dict.end() → check if word NOT in dictionary
- current_extra + remaining_extra → total extra chars for this partition
- min(mini, current_extra + remaining_extra) → find optimal partition

Example: s = "sayhelloworld", dict = ["hello", "world"]
- Partition: "say" + "hello" + "world" → 3 extra chars (only "say")
- Partition: "sayhelloworld" → 13 extra chars (entire string)
- Choose minimum: 3

Base case: Reached end of string → no more extra characters needed

Time: O(2^n) without memoization
Space: O(n) recursion depth
*/
class Solution_recursion {
public:
    int solve(string s, unordered_set<string>& dict, int idx) {
        if (idx >= s.size()) {
            return 0;
        }

        int mini = s.size();

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            int current_extra = 0;
            if (dict.find(sub) == dict.end()) {
                current_extra = sub.size();
            }

            int remaining_extra = solve(s, dict, i + 1);

            mini = min(mini, current_extra + remaining_extra);
        }

        return mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return solve(s, dict, 0);
    }
};

/*
### Time Complexity
O(n^2), where n is the length of string s. The code uses recursion with memoization.
The recursive function solve is called once for each index idx from 0 to n-1. Inside each call,
a for loop runs up to n times. The substr and find operations within the loop take O(n) time
in the worst case, making the total time for each solve call O(n). Thus, the overall time complexity is O(n \times n) = O(n^2).

---

### Space Complexity
O(n), where n is the length of string s. The primary space usage comes from the dp vector,
which stores results for each index and has a size of O(n). The recursion call stack can
also grow up to a depth of n, contributing an additional O(n) to the space. The unordered_set
has a space complexity dependent on the size and length of the words in the dictionary,
which is considered part of the input.
*/
class Solution_memoization {
public:
    int solve(string s, unordered_set<string>& dict, int idx, vector<int>& dp) {
        if (idx >= s.size()) {
            return 0;
        }

        if (dp[idx] != -1) return dp[idx];

        int mini = s.size();

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            int current_extra = 0;
            if (dict.find(sub) == dict.end()) {
                current_extra = sub.size();
            }

            int remaining_extra = solve(s, dict, i + 1, dp);

            mini = min(mini, current_extra + remaining_extra);
        }

        return dp[idx] = mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size() + 1, -1);
        return solve(s, dict, 0, dp);
    }
};

//ANOTHER RECURSIVE METHOD
class Solution_method2 {
public:
    int solve(int idx, string s, unordered_set<string>& dict, int& n, vector<int>& dp) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx] != -1) return dp[idx];

        int result = 1 + solve(idx + 1, s, dict, n, dp);

        for (int j = idx; j < n; j++) {
            string curr = s.substr(idx, j - idx + 1);
            if (dict.count(curr)) {
                result = min(result, solve(j + 1, s, dict, n, dp));
            }
        }

        return dp[idx] = result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, dict, n, dp);
    }
};

/*
Minimum Extra Characters - Tabulation Logic:

Problem: Find minimum number of extra characters when breaking string using dictionary words.

DP Definition: dp[i] = minimum extra characters needed for substring s[i...] (from index i to end)

Algorithm:
1. Base case: dp[n] = 0 (empty string needs 0 extra characters)
2. For each position i (from n-1 to 0):
   - Default choice: Skip current character → dp[i] = 1 + dp[i+1] (1 extra char)
   - Try all substrings starting at i: s[i...j] for j from i to n-1
     - If substring exists in dictionary → dp[i] = min(dp[i], dp[j+1])
     - (Use this word with 0 extra chars + solve remaining string)
3. Answer: dp[0] (minimum extra chars for entire string)

Key Steps:
- dp[i] = 1 + dp[i+1] → assume current character is extra
- s.substr(i, j-i+1) → try word from position i to j
- dp[i] = min(dp[i], dp[j+1]) → if word found, no extra chars for this word
- Bottom-up: Build solution from end to beginning

Example: s = "abc", dict = ["ab"]
- dp[3] = 0, dp[2] = 1, dp[1] = 1
- dp[0]: try "ab" (in dict) → dp[0] = min(3, dp[2]) = min(3, 1) = 1

Time: O(n³), Space: O(n)
*/
class Solution_tabulation {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];

            for (int j = i; j < n; j++) {
                string curr = s.substr(i, j - i + 1);
                if (dict.count(curr)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};

int main() {
    string s = "leetscode";
    vector<string> dictionary = { "leet", "code", "leetcode" };
    Solution_tabulation obj;
    cout << obj.minExtraChar(s, dictionary);
    return 0;
}