/*
#LONGEST SUBSTRING WITH K UNIQUES

LINK:- https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string& s, int k) {
        // code here
        int ans = -1;
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        while (j < s.size()) {
            char ch = s[j];
            mpp[ch]++;
            if (mpp.size() > k) {
                char ch = s[i];
                mpp[ch]--;
                if (mpp[ch] == 0)mpp.erase(ch);
                i++;
            }

            if (mpp.size() == k) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "aabacbebebe";
    int k1 = 3;
    cout << "String: \"" << s1 << "\", k: " << k1 << endl;
    cout << "Longest substring length: " << sol.longestKSubstr(s1, k1) << endl << endl; // Expected: 7 (cbebebe)

    // Example 2
    string s2 = "aabaabaa";
    int k2 = 2;
    cout << "String: \"" << s2 << "\", k: " << k2 << endl;
    cout << "Longest substring length: " << sol.longestKSubstr(s2, k2) << endl << endl; // Expected: 8

    // Example 3
    string s3 = "aaabbb";
    int k3 = 3;
    cout << "String: \"" << s3 << "\", k: " << k3 << endl;
    cout << "Longest substring length: " << sol.longestKSubstr(s3, k3) << endl << endl; // Expected: -1

    return 0;
}
