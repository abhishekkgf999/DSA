/*
#Delete Operation for Two Strings (RECURSION)

LINK:- https://leetcode.com/problems/delete-operation-for-two-strings/description/

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s1, int i, string s2, int j) {
        if (i == s1.size() && j == s2.size()) return 0;

        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;

        if (s1[i] == s2[j]) {
            return solve(s1, i + 1, s2, j + 1);
        }
        else {
            return min(1 + solve(s1, i + 1, s2, j), 1 + solve(s1, i, s2, j + 1));
        }
    }
    int minDistance(string word1, string word2) {
        return solve(word1, 0, word2, 0);
    }
};

class Solution2 {
public:
    int solve(string s1, int n, string s2, int m) {
        if (n == 0 && m == 0) return 0;

        if (n == 0) return m;
        if (m == 0) return n;

        if (s1[n - 1] == s2[m - 1]) {
            return solve(s1, n - 1, s2, m - 1);
        }
        else {
            return min(1 + solve(s1, n - 1, s2, m), 1 + solve(s1, n, s2, m - 1));
        }
    }
    int minDistance(string word1, string word2) {
        return solve(word1, word1.size(), word2, word2.size());
    }
};

int main() {
    string text1 = "heap";
    string text2 = "pea";
    Solution obj;
    cout << obj.minDistance(text1, text2);
    return 0;
}