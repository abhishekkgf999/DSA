#include <bits/stdc++.h>
using namespace std;

// Check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Convert Postfix to Prefix
string Postfix_to_Prefix(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];

        // If operand, push it
        if (!isOperator(ch)) {
            st.push(string(1, ch));
        }
        else {
            // Operator: need two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Create new prefix expression
            string prefix = ch + op2 + op1;
            st.push(prefix);
        }
    }

    return st.top();
}

int main() {
    string s = "abc*+d-";  // equivalent to -+a*bc d
    string ans = Postfix_to_Prefix(s);
    cout << "Postfix: " << s << endl;
    cout << "Prefix: " << ans << endl;

    // Another example
    string s2 = "AB-DE+F*";  // equivalent to *-AB+DE F
    string ans2 = Postfix_to_Prefix(s2);
    cout << "---" << endl;
    cout << "Postfix: " << s2 << endl;
    cout << "Prefix: " << ans2 << endl;

    return 0;
}
