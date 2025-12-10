/*
#SCRAMBLE STRING

LINK:- https://leetcode.com/problems/scramble-string/
*/

#include<bits/stdc++.h>
using namespace std;

//WITH RECURSION
//TIME COMPLEXITY:- Exponential :- O(N. C^n) where c is come constant likely between 2 and 4, and n~N
//SPACE COMPLEXITY:- O(N^2) due to recursion stack depth and string substring copies.
class Solution_Recursion {
public:

    bool solve(const string& s1, const string& s2) {

        if (s1.length() != s2.length()) return false;

        if (s1 == s2) return true;

        int n = s1.length();

        for (int i = 1; i < n; i++) {

            bool swapped =
                solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                solve(s1.substr(i), s2.substr(0, n - i));

            if (swapped) return true;

            bool not_swapped =
                solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i));

            if (not_swapped) return true;
        }

        return false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};


//WITH MEMOIZATION
//TIME COMPLEXITY :- O(N^4)
//SPACE COMPLEXITY :- O(N^3)
/*
Scramble String Problem - Revision Note (Memoization)

Problem: Determine if s2 is a "scrambled" version of s1. A string is scrambled by recursively splitting it into two non-empty substrings and optionally swapping the two parts.

Core Idea: Recursion with Memoization (Top-Down DP)

* The problem has Optimal Substructure (larger problem depends on smaller, identical subproblems) and Overlapping Subproblems (the same subproblems are solved multiple times). This signals Dynamic Programming.
* Memoization is used to store results of solved subproblems to avoid redundant computation.

Thought Process & Logic:

1.  Base Cases:
    * Unequal Lengths: If s1 and s2 have different lengths, they cannot be scrambled versions of each other. Return false.
    * Identical Strings: If s1 and s2 are exactly the same, they are trivially scrambled. Return true.

2.  Memoization Setup:
    * State Definition: A subproblem is uniquely identified by the pair of strings (s1, s2) currently being compared.
    * Memoization Table: Use an unordered_map<string, bool> mp; to store results.
    * Key Creation: Concatenate s1 and s2 with a separator (e.g., s1 + "_" + s2) to form a unique string key for the map.
    * Check mp: Before any computation for (s1, s2), check if mp[key] already exists. If yes, return the stored value.

3.  Recursive Step (Exploring Splits):
    * Thought: How could s1 have been transformed into s2? It must involve a split. We try every possible split point.
    * Action: Iterate i from 1 to n-1 (where n is current string length). i represents the length of the first part of the split.
    * This divides s1 into s1_left = s1.substr(0, i) and s1_right = s1.substr(i).

4.  Two Scramble Possibilities for Each Split:
    * Thought: After splitting s1, s2 must have been formed in one of two ways relative to this split.
    * Possibility 1: No Swap
        * s1_left matches s2_left = s2.substr(0, i) AND
        * s1_right matches s2_right = s2.substr(i)
        * Action: solve(s1_left, s2_left) && solve(s1_right, s2_right)
    * Possibility 2: Swap Occurred
        * s1_left matches s2_right_swapped = s2.substr(n - i, i) (i.e., s2's suffix of length i) AND
        * s1_right matches s2_left_swapped = s2.substr(0, n - i) (i.e., s2's prefix of length n-i)
        * Action: solve(s1_left, s2_right_swapped) && solve(s1_right, s2_left_swapped)

5.  Accumulating Results:
    * If either swapped or not_swapped evaluates to true, then result for the current (s1, s2) is true.
    * Optimization: Use break; as soon as result becomes true (since we only need *one* way to be scrambled).

6.  Storing Result:
    * After the loop, store mp[key] = result before returning.

Initial Call:

* isScramble(s1, s2) function simply clears the map (mp.clear()) (important for multiple test cases) and calls solve(s1, s2).
*/
class Solution_Memoization {
public:

    unordered_map<string, bool> mp;

    bool solve(const string& s1, const string& s2) {

        if (s1.length() != s2.length()) return false;

        if (s1 == s2) return true;


        string key = s1 + "_" + s2;

        if (mp.find(key) != mp.end()) return mp[key];

        bool result = false;
        int n = s1.length();

        for (int i = 1; i < n; i++) {

            bool swapped =
                solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                solve(s1.substr(i), s2.substr(0, n - i));

            if (swapped) {
                result = true;
                break;
            }

            bool not_swapped =
                solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i));

            if (not_swapped) {
                result = true;
                break;
            }
        }

        return mp[key] = result;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};


int main() {
    string s1 = "great";
    string s2 = "eatgr";
    Solution_Memoization obj;
    cout << obj.isScramble(s1, s2);
    return 0;
}