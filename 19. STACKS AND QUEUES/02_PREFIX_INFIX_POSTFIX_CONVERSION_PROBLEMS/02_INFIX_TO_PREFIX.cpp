/*
#INFIX TO PREFIX
*/

#include<bits/stdc++.h>
using namespace std;

/*
RULES

1. REVERSE THE INFIX EXPRESSION
2. INFIX TO POSTFIX
3. REVERSE THE FINAL ANSWER
*/

int priority(char ch) {
    if (ch == '^')return 3;
    else if (ch == '*' || ch == '/')return 2;
    else if (ch == '+' || ch == '-')return 1;
    else return 0;
}

string Infix_to_prefix(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')s[i] = ')';
        else if (s[i] == ')')s[i] = '(';
    }
    string ans = "";
    int i = 0;
    stack<char> st;
    while (i < s.length()) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans = ans + s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if (s[i] == '^') {
                while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            else {
                while (!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }


    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string infix = "(A+B)*C-D+F";
    string prefix = Infix_to_prefix(infix);
    cout << prefix;
    return 0;
}