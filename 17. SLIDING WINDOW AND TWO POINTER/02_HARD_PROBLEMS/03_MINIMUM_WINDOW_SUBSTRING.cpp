/*
#Minimum Window Substring

link :- https://leetcode.com/problems/minimum-window-substring/description/
*/


#include<bits/stdc++.h>
using namespace std;

/*
## Core Algorithm: Sliding Window + Frequency Matching

### Key Insight
Need to satisfy frequency requirements: Window must contain at least as many of each character as required by t.

### Setup: Frequency Arrays

vector<int> fs(128, 0);  // Frequency of chars in current window
vector<int> ft(128, 0);  // Required frequency from string t


Logic: ASCII table size 128 covers all possible characters

### Helper Function: Check Validity
Logic: Window is valid when it has at least the required frequency of every character
Frequency comparison logic:
- fs[i] < ft[i] -> insufficient count of character i
- Must have fs[i] >= ft[i] for all characters

### Sliding Window Logic

### Contraction Phase (When Valid)
Logic: When window is valid, try to minimize it by removing from left

## Key Implementation Insights

Why shrink when valid?
- Want minimum window, so keep shrinking until invalid
- Update answer during valid shrinking phase

Time: O(|s| + |t|) | Space: O(1) - fixed size arrays
*/
class Solution {
public:
    bool check(vector<int>& fs, vector<int>& ft) {
        for (int i = 0; i < 128; i++) {
            if (fs[i] < ft[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> fs(128, 0);
        vector<int> ft(128, 0);

        for (auto ch : t) {
            ft[ch]++;   // ✅ use ch directly
        }

        int start = -1, end = -1;
        int i = 0, j = 0;
        int min_len = INT_MAX;

        while (j < s.size()) {
            char ch = s[j];
            fs[ch]++;   // ✅ use ch directly

            while (check(fs, ft)) {
                if ((j - i + 1) < min_len) {   // ✅ strictly smaller window
                    min_len = (j - i + 1);
                    start = i;
                    end = j;
                }
                fs[s[i]]--;  // ✅ use s[i] directly
                i++;
            }
            j++;
        }

        return (end != -1) ? s.substr(start, end - start + 1) : "";
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Minimum Window Substring: \"" << sol.minWindow(s1, t1) << "\"" << endl; // Expected: "BANC"
    cout << "---" << endl;

    // Example 2
    string s2 = "a";
    string t2 = "a";
    cout << "s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Minimum Window Substring: \"" << sol.minWindow(s2, t2) << "\"" << endl; // Expected: "a"
    cout << "---" << endl;

    // Example 3
    string s3 = "a";
    string t3 = "aa";
    cout << "s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Minimum Window Substring: \"" << sol.minWindow(s3, t3) << "\"" << endl; // Expected: ""
    cout << "---" << endl;

    return 0;
}
