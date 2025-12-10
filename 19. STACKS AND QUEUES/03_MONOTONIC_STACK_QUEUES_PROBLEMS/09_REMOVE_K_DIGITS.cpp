/*
#REMOVE K DIGITS

LINK:- https://leetcode.com/problems/remove-k-digits/description/

# Remove K Digits - Revision Notes

## Problem Statement
Given a number as string and integer k, remove k digits to make the smallest possible number.

Example: num = "1432219", k = 3
- Remove 4, 3, 2 → Result = "1219"
*/

#include<bits/stdc++.h>
using namespace std;

/*
## Core Concept: Greedy Monotonic Stack

### Key Insight
To get the smallest number:
Remove larger digits that appear BEFORE smaller digits


"1432" with k=2
     ↓
Remove 4 (larger before smaller 3)
Remove 3 (larger before smaller 2)
Result: "12"


### Why Greedy Works?
The leftmost digit has the highest place value. Making it smaller has maximum impact.

4321 vs 1234
↑          ↑
Thousands  Thousands
(most significant)
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};


int main() {
    Solution obj;
    string s = "1432219";
    cout << obj.removeKdigits(s, 3);
    return 0;
}