#include <bits/stdc++.h>
using namespace std;

// Check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Convert Postfix to Infix
string Postfix_to_Infix(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];

        // If it's an operand, push it as a string
        if (!isOperator(ch)) {
            st.push(string(1, ch));
        }
        else {
            // Operator: need two operands
            string op1 = st.top(); st.pop(); // second operand
            string op2 = st.top(); st.pop(); // first operand

            // Combine into infix expression
            string infix = "(" + op2 + ch + op1 + ")";
            st.push(infix);
        }
    }

    return st.top();
}

int main() {
    string s = "abc*+d-";
    string ans = Postfix_to_Infix(s);
    cout << "Postfix: " << s << endl;
    cout << "Infix: " << ans << endl;

    // Another example
    string s2 = "AB-DE+F*";
    string ans2 = Postfix_to_Infix(s2);
    cout << "---" << endl;
    cout << "Postfix: " << s2 << endl;
    cout << "Infix: " << ans2 << endl;

    return 0;
}
