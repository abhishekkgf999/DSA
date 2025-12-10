/*
#LONGEST COMMON SUBSEQUENCE (RECURSION)

LINK:- https://leetcode.com/problems/longest-common-subsequence/description/

*/

/*
INTUITION

- We aim to find the length of the Longest Common Subsequence (LCS) between two strings.
- A subsequence is a sequence that appears in the same relative order, but not necessarily contiguously.
- At each step, we compare characters from both strings:
  1. If the characters match, we include it in the LCS and move both pointers back.
  2. If they don't match, we try two options:
     - Skip the current character of the first string.
     - Skip the current character of the second string.
     - Take the maximum result from these two options.

APPROACH (Recursive)

1. DP Definition:
   - Let solve(i, j) represent the length of the LCS between the first i characters of text1 and the first j characters of text2.

2. Base Case:
   - If either i == 0 or j == 0, return 0 since one of the strings is empty and no common subsequence is possible.

3. Transition:
   - If text1[i - 1] == text2[j - 1]:
     - Return 1 + solve(i - 1, j - 1).
   - Else:
     - Return max(solve(i - 1, j), solve(i, j - 1)).

4. Final Answer:
   - Call solve(n, m) where n and m are the lengths of text1 and text2 respectively.

COMPLEXITY

- Time: Exponential in the worst case, O(2^(n + m)), due to overlapping subproblems.
- Space: O(n + m), used by the recursion stack.
- (Can be optimized using memoization or tabulation.)
*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s1, int n, string s2, int m) {
        //THINK OF THE SMALLEST VALID INPUT, WHICH CAN BE EMPTY STRING, IN THAT CASE NO MATCHING CHARACTER WILL BE THERE, SO SIMPLY RETURN 0
        if (n == 0 || m == 0) return 0;

        //CHECK IF CURRENT CHARACTER MATCHES OR NOT? IF YES, THEN COUNT 1 AND MOVE BOTH INDEXES
        if (s1[n - 1] == s2[m - 1]) {
            return 1 + solve(s1, n - 1, s2, m - 1);
        }

        //IF IT DOESN'T MATCHES, THERE WILL BE TWO CASES CAN BE ARISE:-
        //1. THE CURRENT CHARACTER OF TEXT1 CAN BE FOUND IN THE REST OF THE REMAINING STRING IN TEXT2, STAY AT TEXT1 INDEX, AND MOVE TEXT2 INDEX
        //2. THE CURRENT CHARACTER OF TEXT2 CAN BE FOUND IN THE REST OF THE REMAINING STRING IN TEXT1, STAY AT TEXT2 INDEX, AND MOVE TEXT1 INDEX
        return max(solve(s1, n, s2, m - 1), solve(s1, n - 1, s2, m));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        return solve(text1, n, text2, m);
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution obj;
    cout << obj.longestCommonSubsequence(text1, text2);
    return 0;
}