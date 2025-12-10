#include <bits/stdc++.h>
using namespace std;

// Check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Convert Prefix to Postfix
string Prefix_to_Postfix(string s) {
    stack<string> st;

    // Traverse from right to left
    for (int i = s.length() - 1; i >= 0; --i) {
        char ch = s[i];

        // If operand, push it
        if (!isOperator(ch)) {
            st.push(string(1, ch));
        }
        else {
            // Operator: pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Create new postfix expression
            string postfix = op1 + op2 + ch;
            st.push(postfix);
        }
    }

    return st.top();
}

int main() {
    string s = "-+a*bc d";  // Prefix
    string ans = Prefix_to_Postfix(s);
    cout << "Prefix: " << s << endl;
    cout << "Postfix: " << ans << endl;

    // Another example
    string s2 = "*-AB+DE";  // Prefix
    string ans2 = Prefix_to_Postfix(s2);
    cout << "---" << endl;
    cout << "Prefix: " << s2 << endl;
    cout << "Postfix: " << ans2 << endl;

    return 0;
}
