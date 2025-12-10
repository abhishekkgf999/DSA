/*
#PALINDROME PARTIONING (RECURSION)

LINK:- https://leetcode.com/problems/palindrome-partitioning/description/

LINK2:- https://leetcode.com/problems/palindrome-partitioning-ii/description/
*/




#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(2ⁿ * n) (worst case)
// SPACE COMPLEXITY = O(N) => DUE TO RECURSION STACK, NO EXTRA SPACE OTHERWISE
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        int start = i, end = j;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }

        return true;
    }
    int solve(string& s, int i, int j) {
        if (i >= j) return 0;

        if (isPalindrome(s, i, j)) return 0;

        int ans = INT_MAX;

        for (int k = i; k < j; k++) {
            int temp_ans = solve(s, i, k) + solve(s, k + 1, j) + 1;

            ans = min(ans, temp_ans);
        }
        return ans;
    }

    int minCut(string s) {
        return solve(s, 0, s.size() - 1);
    }
};


int main() {
    string s = "aab";
    Solution obj;

    cout << obj.minCut(s);
    return 0;
}