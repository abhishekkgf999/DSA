/*
#NUMBER OF SUBSTRINGS CONTAINING ALL THREE CHARACTERS

LINK:- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

*/


#include<bits/stdc++.h>
using namespace std;

/*
### Key Insight
When window [i,j] contains all 3 characters:
- All extensions to the right are also valid
- From position j, can extend to j, j+1, j+2, ..., n-1
- Count = n - j valid substrings starting from position i

### Window Management Logic

unordered_map<char, int> mpp;  // Character frequency in window

Target: mpp.size() == 3 (all three characters present)

### Counting + Shrinking Logic

Logic:
- When we have all 3 chars, current window [i,j] and all its extensions are valid
- Count extensions: n - j
- Shrink from left to find next valid starting position

## Key Implementation Insights

Why count += n - j?
- Current window starts at i, ends at j
- Can extend to: [i,j], [i,j+1], [i,j+2], ..., [i,n-1]
- Total extensions = (n-1) - j + 1 = n - j

Multiple counting per position:
- For each valid left boundary i, count all possible right extensions
- Then move left boundary and repeat

Greedy approach:
- As soon as window becomes valid, count ALL possible extensions
- Then try next starting position

## Mental Model
Extension principle: If [i,j] contains all 3 chars, then [i,j+k] also contains all 3 chars


Process:
1. Expand until all 3 characters found
2. Count all extensions from current left boundary
3. Shrink left boundary by 1 and repeat
4. Continue until no more valid windows

Time: O(n) | Space: O(1)
*/
class Solution1 {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mpp;
        int i = 0, j = 0;
        int count = 0;
        int n = s.size();
        while (j < s.size()) {
            char ch = s[j];
            mpp[ch]++;
            while (mpp.size() == 3) {
                count += n - j;
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)mpp.erase(s[i]);
                i++;
            }
            j++;
        }
        return count;
    }
};

/*

### Key Insight
At position i, how many valid substrings end at i?
- Need all three characters somewhere in substring [start, i]
- Latest position where we can start = position after the earliest of last seen a, b, c
- Count = min(a, b, c) + 1

### Counting Logic: min(a, b, c) + 1
Core insight: To have all 3 characters in substring ending at i:
- Must include positions a, b, c (last seen of each character)
- Bottleneck: Earliest of these three positions
- Valid starting positions: 0, 1, 2, ..., min(a,b,c)
- Count: min(a,b,c) + 1

## Why This Formula Works

Example: s = "abcabc", at i=4 (char 'b')
- Last positions: a=3, b=4, c=2
- Earliest last position: min(3,4,2) = 2
- Valid substrings ending at i=4: starting from positions 0,1,2
- Count = 2 + 1 = 3

Substrings: "abcab", "bcab", "cab"

### Edge Case Handling
Initial state: a = -1, b = -1, c = -1
- If any character not yet seen → min() gives -1
- count += -1 + 1 = 0 → correct (no valid substrings yet)

At each position:
- Update recency of current character
- Count valid starting positions (limited by earliest recent character)

Key realization: Don't need to track frequencies, just last positions

Time: O(n) | Space: O(1)
*/
class Solution2 {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int a = -1, b = -1, c = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a = i;
            if (s[i] == 'b') b = i;
            if (s[i] == 'c') c = i;

            count += min(a, min(b, c)) + 1;
        }
        return count;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    string test1 = "abcabc"; // Expected: 10
    string test2 = "aaacb";  // Expected: 3
    string test3 = "abac";   // Expected: 1

    cout << "--- Testing Solution 1 (Sliding Window) ---" << endl;
    cout << "Input: " << test1 << ", Result: " << s1.numberOfSubstrings(test1) << endl;
    cout << "Input: " << test2 << ", Result: " << s1.numberOfSubstrings(test2) << endl;
    cout << "Input: " << test3 << ", Result: " << s1.numberOfSubstrings(test3) << endl;

    cout << "\n--- Testing Solution 2 (Last Seen) ---" << endl;
    cout << "Input: " << test1 << ", Result: " << s2.numberOfSubstrings(test1) << endl;
    cout << "Input: " << test2 << ", Result: " << s2.numberOfSubstrings(test2) << endl;
    cout << "Input: " << test3 << ", Result: " << s2.numberOfSubstrings(test3) << endl;

    return 0;
}
