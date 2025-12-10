/*
#LONGEST COMMON SUBSTRING (RECURSION)

LINK:- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

*/

/*

### 📌 1. Substring
- A **substring** is a **contiguous** part of a string.
- All characters must appear **in order and without gaps**.
- Example:
  For the string `"abcde"`, valid substrings include:
  - `"a"`, `"ab"`, `"bcd"`, `"abcde"`
  Invalid: `"ace"` (not contiguous)

---

### 📌 2. Subsequence
- A **subsequence** is a sequence that can be derived by **deleting some (or no) characters** without changing the order of the remaining characters.
- Characters must appear **in the same order**, but **not necessarily contiguous**.
- Example:
  For `"abcde"`, valid subsequences include:
  - `"a"`, `"ace"`, `"bde"`, `"abcde"`
  Invalid: `"aed"` (order changed)

---

### 📌 3. Subset
- A **subset** refers to a selection of elements from a **set**, not necessarily in any order.
- It applies to **sets** (like `{1, 2, 3}`), not strings.
- All combinations of elements (including the empty set) are valid subsets.
- Example:
  For the set `{1, 2, 3}`, valid subsets include:
  - `{}`, `{1}`, `{2, 3}`, `{1, 2, 3}`
  Order doesn’t matter: `{1, 2}` is the same as `{2, 1}`

---

### 🔍 Summary Table

| Term        | Applies To | Order Matters  | Contiguous Required   | Example from `"abcde"`  |
|-------------|------------|----------------|---------------------- |-------------------------|
| Substring   | String     | ✅ Yes         | ✅ Yes               | `"bcd"`                 |
| Subsequence | String     | ✅ Yes         | ❌ No                | `"ace"`                 |
| Subset      | Set        | ❌ No          | ❌ No                | `{a, c, e}`             |


*/

/*
INTUITION

=> The function checks each character of s1 and s2 starting at index i and j.

=> If characters match, we extend the current matching substring by increasing the count and moving both pointers.

=> If they don't, the current substring is broken, so we reset the count to 0 and explore two new branches:
   - Move only i (i.e., skip a character from s1)
   - Move only j (i.e., skip a character from s2)

=> maxLen keeps track of the longest matching substring seen so far during all recursive paths.

APPROACH (Recursive)

1. Function Definition:
   - The recursive function takes indices i, j and a `count` that stores the current length of a matching substring.

2. Base Case:
   - If either i or j reaches the end of the string, return the count (as no further matching is possible).

3. Recursive Steps:
   - If s1[i] == s2[j], call the function for (i+1, j+1) with count+1.
   - Always explore the next characters independently by:
     - Calling (i+1, j, 0)
     - Calling (i, j+1, 0)
   - Update maxLen in each call when characters match.

4. Final Answer:
   - maxLen holds the maximum length of any common substring found.

COMPLEXITY

- Time: Exponential in worst case O(3^(n + m)) , due to multiple recursive branches.
- Space: O(n + m), for the recursive call stack.
- (Can be optimized with memoization or converted to DP.)
*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int max_length = 0;

    int solve(string& s1, int n, string& s2, int m) {
        if (n == 0 || m == 0) return 0;

        int current = 0;
        if (s1[n - 1] == s2[m - 1]) {
            current = 1 + solve(s1, n - 1, s2, m - 1);  // here returning "current" matters to add up the rest of the contiguous string length
            max_length = max(max_length, current);
        }

        solve(s1, n, s2, m - 1);
        solve(s1, n - 1, s2, m);

        /*
        Returning current allows the recursion to propagate the length of the current contiguous match back up the call stack.
        Without returning it, we’d lose track of how long the current substring is.
        */
        return current;
    }

    int longestCommonSubstr(string& s1, string& s2) {
        // The reason we reset max_length in longestCommonSubstr() is to ensure correctness across multiple test cases.
        // If you call longestCommonSubstr() multiple times on different inputs, the max_length from a previous call might still be stored in memory, leading to incorrect results.
        max_length = 0;
        solve(s1, s1.size(), s2, s2.size());
        return max_length;
    }
};

int main() {
    string text1 = "ABCDGH";
    string text2 = "ACDGHR";
    Solution obj;
    cout << obj.longestCommonSubstr(text1, text2);
    return 0;
}