/*
#LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

LINK:- https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/


#include<bits/stdc++.h>
using namespace std;

/*
Pattern:
1. Expand until constraint violated (duplicate found)
2. Contract until constraint satisfied (no duplicates)
3. Record maximum valid window size

## Key Points
- HashMap tracks frequency: Detects duplicates instantly
- Two-pointer technique: Efficient O(n) single pass
- Greedy approach: Always try to maximize current window

Time: O(n) | Space: O(min(m,n)) where m = charset size
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        while (j < s.length()) {
            mpp[s[j]]++;
            while (mpp[s[j]] > 1) {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            max_len = max(max_len, j - i + 1);
            j++;
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case with a unique substring in the middle
    string s1 = "abcabcbb";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Length of longest substring: " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 2: All unique characters
    string s2 = "pwwkew";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Length of longest substring: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 3: All the same character
    string s3 = "bbbbb";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Length of longest substring: " << sol.lengthOfLongestSubstring(s3) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 4: Empty string
    string s4 = "";
    cout << "Input: \"" << s4 << "\"" << endl;
    cout << "Length of longest substring: " << sol.lengthOfLongestSubstring(s4) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 5: Single character string
    string s5 = "a";
    cout << "Input: \"" << s5 << "\"" << endl;
    cout << "Length of longest substring: " << sol.lengthOfLongestSubstring(s5) << endl;
    cout << "---------------------------------------" << endl;

    return 0;
}