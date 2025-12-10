/*
#Boolean Parenthesization

LINK:- https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
*/

#include<bits/stdc++.h>
using namespace std;


//RECURSIVE CODE
/*
TIME COMPLEXITY :- O(N*(4^(N/2)))
SPACE COMPLEXITY :- O(N) (due to recursion stack depth)
*/
/*
Thought Process & Crucial Steps:

1.  Problem Decomposition (Recursion):
    * Thought: The core idea is to break the larger problem into smaller, similar subproblems. An expression (A op B) can be evaluated if we know how A and B evaluate.
    * Action: Define a function solve(s, i, j, isTrue) that returns the number of ways the sub-expression s[i...j] evaluates to isTrue (true or false).

2.  Base Cases (Smallest Problems):
    * Thought: What are the simplest expressions we can solve directly without further recursion?
    * Action 1 (Invalid Range): If i > j, the range is empty/invalid. No ways to evaluate. Return 0.
    * Action 2 (Single Literal): If i == j, we have a single 'T' or 'F'.
        * If isTrue is desired: Return 1 if s[i] is 'T', else 0.
        * If isFalse is desired: Return 1 if s[i] is 'F', else 0.

3.  Recursive Step (Choosing the Last Operator):
    * Thought: For any expression s[i...j], there must be one operator that is performed last. We need to try all possibilities for this "last operator."
    * Action: Iterate k from i+1 to j-1, stepping by 2. Each s[k] is a potential last operator. This splits the expression into s[i...k-1] (left) and s[k+1...j] (right).

4.  Combining Subproblem Results:
    * Thought: To find the ways for s[i...j], we need to know how the left and right parts can evaluate to true or false.
    * Action: Make recursive calls for both truth values of the left and right sub-expressions:
        * lt = solve(s, i, k-1, true)
        * lf = solve(s, i, k-1, false)
        * rt = solve(s, k+1, j, true)
        * rf = solve(s, k+1, j, false)

5.  Applying Boolean Logic (Truth Tables):
    * Thought: Based on the operator s[k] and whether we want the final result to be true or false, combine lt, lf, rt, rf according to boolean logic rules.
    * Action: Use if/else if statements for '&', '|', '^' operators. For each operator, sum up the products of ways from left and right subproblems that yield the desired isTrue or !isTrue outcome.
        * Example for & and isTrue: ways += lt * rt (only T&T yields True)
        * Example for & and !isTrue: ways += lt*rf + lf*rt + lf*rf (T&F, F&T, F&F all yield False)
        * Similar logic for | and ^.

6.  Accumulate and Return:
    * Thought: The total ways for the current s[i...j] is the sum of ways from all possible k splits.
    * Action: ways accumulates sums in the loop. Return ways.

7.  Initial Call:
    * Thought: To get the answer for the entire problem, call solve on the full string asking for a true result.
    * Action: return solve(s, 0, s.size() - 1, true);
*/
class Solution_RECURSION {
public:
    int solve(string s, int i, int j, bool isTrue) {
        if (i > j) return 0;

        if (i == j) {
            if (isTrue == true) return s[i] == 'T';
            else return s[i] == 'F';
        }

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {
            char op = s[k];

            int lt = solve(s, i, k - 1, true);    //lt = left true;
            int lf = solve(s, i, k - 1, false);   //lf = left false;
            int rt = solve(s, k + 1, j, true);    //rt = right true;
            int rf = solve(s, k + 1, j, false);   //rf = right false;

            if (op == '&') {
                if (isTrue) {
                    ways += lt * rt;
                }
                else {
                    ways += lt * rf + lf * rt + lf * rf;
                }
            }
            else if (op == '|') {
                if (isTrue) {
                    ways += lt * rf + lf * rt + lt * rt;
                }
                else {
                    ways += lf * rf;
                }
            }
            else if (op == '^') {
                if (isTrue) {
                    ways += lt * rf + lf * rt;
                }
                else {
                    ways += lf * rf + lt * rt;
                }
            }
        }

        return ways;
    }
    int countWays(string& s) {
        // code here
        return solve(s, 0, s.size() - 1, true);
    }
};


//MEMOIZATION
//TIME COMPLEXITY :- O(N^3)
//SPACE COMPLEXITY :- O(N^2)
/*
dp Table: unordered_map<string, int> dp;

Purpose: Stores (i, j, isTrue) as a string key, and the int number of ways as value.

Why string key? Convenient way to combine int i, int j, and bool isTrue into a hashable key for unordered_map.
*/
class Solution_MEMOIZATION {
public:
    // Modulo value as specified in problem constraints (or to prevent overflow)
    int mod = 1003;

    // Memoization table: stores results of subproblems
    // Key: string representing (start_index_i, end_index_j, boolean_isTrue_flag)
    // Value: number of ways the sub-expression evaluates to the desired boolean
    unordered_map<string, int> dp;

    int countWays(string& s, int i, int j, bool isTrue) {
        if (i > j) return 0;

        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        // Memoization Check: Construct a unique key for the current state (i, j, isTrue)
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        // If the result for this subproblem is already computed and stored in dp, return it
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {
            char op = s[k];

            int lt = countWays(s, i, k - 1, true);
            int lf = countWays(s, i, k - 1, false);
            int rt = countWays(s, k + 1, j, true);
            int rf = countWays(s, k + 1, j, false);

            // Apply boolean logic based on the operator to accumulate ways
            // Importantly: Modulo operations should be applied at each addition/multiplication
            // to prevent integer overflow before the final sum, as intermediate products can be large.
            // Using 1LL promotes to long long for multiplication to prevent overflow.
            if (op == '&') {
                if (isTrue) {
                    ways = (ways + (1LL * lt * rt) % mod) % mod;
                }
                else {
                    ways = (ways + (1LL * lt * rf) % mod + (1LL * lf * rt) % mod + (1LL * lf * rf) % mod) % mod;
                }
            }
            else if (op == '|') {
                if (isTrue) {
                    ways = (ways + (1LL * lt * rt) % mod + (1LL * lt * rf) % mod + (1LL * lf * rt) % mod) % mod;
                }
                else {
                    ways = (ways + (1LL * lf * rf) % mod) % mod;
                }
            }
            else if (op == '^') {
                if (isTrue) {
                    ways = (ways + (1LL * lt * rf) % mod + (1LL * lf * rt) % mod) % mod;
                }
                else {
                    ways = (ways + (1LL * lt * rt) % mod + (1LL * lf * rf) % mod) % mod;
                }
            }
            return dp[key] = ways;
        }

    }

    int countEval(string s) {
        // Clear the memoization table for each new test case
        // This is crucial to prevent results from previous calls from affecting current ones.
        dp.clear();
        return countWays(s, 0, s.size() - 1, true);
    }
};


//TABULATION
class Solution_TABULATION {
public:
    int countWays(int n, string s) {
        // dp_true[i][j] stores the number of ways s[i...j] evaluates to true
        // dp_false[i][j] stores the number of ways s[i...j] evaluates to false
        vector<std::vector<int>> dp_true(n, std::vector<int>(n, 0));
        vector<std::vector<int>> dp_false(n, std::vector<int>(n, 0));

        // Base cases: single symbols (length 1)
        // Symbols are at even indices: 0, 2, 4, ...
        for (int i = 0; i < n; i += 2) {
            if (s[i] == 'T') {
                dp_true[i][i] = 1;
            }
            else {
                dp_false[i][i] = 1;
            }
        }

        // Fill the DP tables for lengths from 3 to n (stepping by 2)
        // Length represents the number of characters in the sub-expression.
        // It goes from 3 (e.g., "T|F") up to n.
        for (int length = 3; length <= n; length += 2) {
            // i represents the starting index of the sub-expression.
            // It also increments by 2 to always start on a symbol.
            for (int i = 0; i <= n - length; i += 2) {
                int j = i + length - 1; // j is the ending index of the sub-expression

                // Iterate through operators k within the current sub-expression s[i...j]
                // k represents the index of the operator that splits the sub-expression.
                // Operators are at odd indices: i+1, i+3, ..., j-1.
                for (int k = i + 1; k < j; k += 2) {
                    // Left sub-expression: s[i...k-1]
                    int lt = dp_true[i][k - 1];   // ways left part is true
                    int lf = dp_false[i][k - 1];  // ways left part is false

                    // Right sub-expression: s[k+1...j]
                    int rt = dp_true[k + 1][j];   // ways right part is true
                    int rf = dp_false[k + 1][j];  // ways right part is false

                    char operator_char = s[k];

                    if (operator_char == '&') {
                        // Ways to make true: (True & True)
                        dp_true[i][j] += lt * rt;
                        // Ways to make false: (True & False) or (False & True) or (False & False)
                        dp_false[i][j] += lt * rf + lf * rt + lf * rf;
                    }
                    else if (operator_char == '|') {
                        // Ways to make true: (True | True) or (True | False) or (False | True)
                        dp_true[i][j] += lt * rt + lt * rf + lf * rt;
                        // Ways to make false: (False | False)
                        dp_false[i][j] += lf * rf;
                    }
                    else if (operator_char == '^') {
                        // Ways to make true: (True ^ False) or (False ^ True)
                        dp_true[i][j] += lt * rf + lf * rt;
                        // Ways to make false: (True ^ True) or (False ^ False)
                        dp_false[i][j] += lt * rt + lf * rf;
                    }
                }
            }
        }

        return dp_true[0][n - 1];
    }
};

int main() {
    string s = "T|T&F^T";
    Solution_RECURSION obj;
    Solution_MEMOIZATION obj2;
    Solution_TABULATION obj3;
    cout << obj.countWays(s) << endl;
    cout << obj2.countEval(s) << endl;
    cout << obj3.countWays(s.length(), s) << endl;

    return 0;
}