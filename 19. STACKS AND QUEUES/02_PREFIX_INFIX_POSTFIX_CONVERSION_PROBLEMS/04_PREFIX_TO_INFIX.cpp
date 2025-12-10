#include <bits/stdc++.h>
using namespace std;

// Check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Convert Prefix to Infix
string Prefix_to_Infix(string s) {
    stack<string> st;

    // Traverse from right to left
    for (int i = s.length() - 1; i >= 0; --i) {
        char ch = s[i];

        // If operand, push it
        if (!isOperator(ch)) {
            st.push(string(1, ch));
        }
        else {
            // Operator: need two operands
            string op1 = st.top(); st.pop(); // first operand
            string op2 = st.top(); st.pop(); // second operand

            // Combine into infix expression
            string infix = "(" + op1 + ch + op2 + ")";
            st.push(infix);
        }
    }

    return st.top();
}

int main() {
    string s = "-+a*bc d";  // equivalent to ((a+(b*c))-d)
    string ans = Prefix_to_Infix(s);
    cout << "Prefix: " << s << endl;
    cout << "Infix: " << ans << endl;

    // Another example
    string s2 = "*-AB+DE";  // equivalent to ((A-B)*(D+E))
    string ans2 = Prefix_to_Infix(s2);
    cout << "---" << endl;
    cout << "Prefix: " << s2 << endl;
    cout << "Infix: " << ans2 << endl;

    return 0;
}
