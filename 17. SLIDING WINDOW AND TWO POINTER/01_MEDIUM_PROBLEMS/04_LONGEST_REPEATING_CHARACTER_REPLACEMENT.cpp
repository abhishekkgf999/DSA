/*
#LONGEST REPEATING CHARACTER REPLACEMENT

LINK:- https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*

## Problem Logic
Find longest substring where you can make all characters same by changing at most K characters.

## Core Algorithm: Sliding Window + Frequency Tracking

### Key Insight
To make all characters same: Keep most frequent character, change all others
- If window has length len and max frequency is max_freq
- Changes needed = len - max_freq
- Valid window: len - max_freq ≤ k

### Window Management Logic

vector<int> freq(26, 0);  // Character frequency in current window
int max_frequent = 0;     // Highest frequency in current window


### Expansion Phase

freq[s[j] - 'A']++;
max_frequent = max(max_frequent, freq[s[j] - 'A']);

Logic: Add new character and update max frequency if needed

### Validation Check

int len = j - i + 1;
if(len - max_frequent > k){  // Too many changes needed
    freq[s[i] - 'A']--;      // Remove leftmost character
    i++;                     // Shrink window by 1
}


Logic: If current window needs >k changes, shrink from left by exactly 1
- Why only 1 step? We want to find maximum valid window
- Why not while loop? Single shrink maintains largest possible window

### Update Maximum

max_len = max(max_len, j - i + 1);

Logic: After validation, current window is guaranteed valid

## Key Implementation Insights

Why track max_frequent?
- Determines minimum changes needed for current window
- Critical for validity check: changes = window_size - max_frequency

Why single shrink vs while loop?

i++;  // Not while(invalid) { i++; }

Reason: We're finding maximum length, so we want to keep window as large as possible

Frequency array indexing:

freq[s[j] - 'A']  // Maps 'A' to 0, 'B' to 1, etc.


## Mental Model
Strategy: Keep most frequent character in window, change others to match it


s = "AABABBA", k = 1
Window "AAB": max_freq=2, changes=3-2=1 ≤ k ✓
Window "AABA": max_freq=3, changes=4-3=1 ≤ k ✓
Window "AABAB": max_freq=3, changes=5-3=2 > k ✗
Shrink: "ABAB": max_freq=2, changes=4-2=2 > k ✗


Pattern:
1. Expand and track max frequency
2. Check if changes needed ≤ k
3. Shrink minimally if invalid
4. Record maximum valid window

## Key Points
- Validity condition: window_length - max_frequency ≤ k
- Greedy approach: Minimal shrinking to maintain largest window
- Frequency tracking: Efficient with fixed-size array for 26 letters

Time: O(n) | Space: O(1) - fixed array of size 26
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int max_frequent = 0;
        int max_len = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            freq[s[j] - 'A']++;

            max_frequent = max(max_frequent, freq[s[j] - 'A']);

            int len = j - i + 1;

            if (len - max_frequent > k) {
                freq[s[i] - 'A']--;
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

    // Test Case 1: Example from problem statement
    // s = "AABABBA", k = 1
    // Longest substring after one replacement is "BBBB" or "AAAA", length 4
    string s1 = "AABABBA";
    int k1 = 1;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Longest repeating character replacement length: " << sol.characterReplacement(s1, k1) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 2: All 'A's to 'B's, or vice versa
    // s = "ABAB", k = 2
    // Result: "AAAA" or "BBBB", length 4
    string s2 = "ABAB";
    int k2 = 2;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Longest repeating character replacement length: " << sol.characterReplacement(s2, k2) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 3: No changes needed
    // s = "AAAB", k = 0
    // Result: "AAA", length 3
    string s3 = "AAAB";
    int k3 = 0;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Longest repeating character replacement length: " << sol.characterReplacement(s3, k3) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 4: K is large enough to change the entire string
    // s = "A", k = 100
    // Result: "A", length 1
    string s4 = "A";
    int k4 = 100;
    cout << "Input: s = \"" << s4 << "\", k = " << k4 << endl;
    cout << "Longest repeating character replacement length: " << sol.characterReplacement(s4, k4) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 5: Empty string
    // s = "", k = 1
    // Result: 0
    string s5 = "";
    int k5 = 1;
    cout << "Input: s = \"" << s5 << "\", k = " << k5 << endl;
    cout << "Longest repeating character replacement length: " << sol.characterReplacement(s5, k5) << endl;

    return 0;
}