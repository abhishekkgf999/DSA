/*
#CHECK FOR BALANCHED PARANTHESIS

LINK:- https://leetcode.com/problems/valid-parentheses/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto i : s) {
            if (i == '(' || i == '[' || i == '{') st.push(i);
            else {
                if (st.empty() || (i == ')' && st.top() != '(') || (i == ']' && st.top() != '[') || (i == '}' && st.top() != '{'))return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution obj;
    cout << obj.isValid("{}");
    return 0;
}