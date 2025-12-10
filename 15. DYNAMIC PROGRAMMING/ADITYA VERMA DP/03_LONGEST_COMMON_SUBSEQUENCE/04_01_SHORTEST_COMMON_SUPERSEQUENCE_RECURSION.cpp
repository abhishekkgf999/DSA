/*
#SHORTEST COMMON SUPERSEQUENCE (RECURSION)

LINK:- https://leetcode.com/problems/shortest-common-supersequence/

*/

/*
INTUITION

- The goal is to find the shortest string that contains both s1 and s2 as subsequences.
- At each step, we compare characters from both strings:
  1. If the characters match, we include that character once in the result and move both pointers forward.
  2. If they don’t match, we have two choices:
     - Take the current character from s1 and recursively find the SCS for the remaining part.
     - Take the current character from s2 and recursively find the SCS for the remaining part.
     - We return the option that gives a shorter overall supersequence.

APPROACH (Recursive)

1. Function Definition:
   - `solve(i, j)` returns the shortest common supersequence of s1 starting from index `i` and s2 starting from index `j`.

2. Base Cases:
   - If both i and j reach the end of their strings, return "" (done).
   - If only s1 is exhausted, return the remaining part of s2.
   - If only s2 is exhausted, return the remaining part of s1.

3. Recursive Steps:
   - If s1[i] == s2[j], include the character once and recurse on the next indices.
   - If not equal, try two options:
     - Include s1[i] and recurse on (i+1, j)
     - Include s2[j] and recurse on (i, j+1)
     - Choose the option with the smaller resulting string length.

4. Final Answer:
   - Call solve(0, 0) to build the shortest common supersequence from the beginning of both strings.

COMPLEXITY

- Time: Exponential in the worst case, O(2^(n + m)), due to exploring both options at every mismatch.
- Space: O(n + m), used by the recursion stack.
- (Can be optimized with memoization to O(n × m) time and space.)
*/





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to find the shortest common supersequence
    string solve(string& s1, int i, string& s2, int j) {
        if (i == s1.size() && j == s2.size()) return "";
        // If we've reached the end of s1, append the remaining part of s2
        if (i == s1.size()) return s2.substr(j);

        // If we've reached the end of s2, append the remaining part of s1
        if (j == s2.size()) return s1.substr(i);

        // If characters match, include the character once and move both pointers
        if (s1[i] == s2[j]) {
            return s1[i] + solve(s1, i + 1, s2, j + 1);
        }
        else {
            // If characters don't match, explore both options:
            // 1. Include s1[i] and move i
            // 2. Include s2[j] and move j
            string option1 = s1[i] + solve(s1, i + 1, s2, j);
            string option2 = s2[j] + solve(s1, i, s2, j + 1);

            // Return the shorter of the two options
            return (option1.size() < option2.size()) ? option1 : option2;
        }
    }

    // Entry point: starts recursion from the beginning of both strings
    string shortestCommonSupersequence(string s1, string s2) {
        return solve(s1, 0, s2, 0);
    }
};

int main() {
    string text1 = "abac";
    string text2 = "cab";
    Solution obj;
    cout << obj.shortestCommonSupersequence(text1, text2);
    return 0;
}