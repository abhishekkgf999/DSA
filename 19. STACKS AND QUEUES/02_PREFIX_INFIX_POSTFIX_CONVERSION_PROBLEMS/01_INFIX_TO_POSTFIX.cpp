/*
#INFIX TO POSTFIX

*/

#include<bits/stdc++.h>
using namespace std;

/*
# Infix to Postfix Conversion - Revision Notes

## Problem
Convert infix expression to postfix using stack (Shunting Yard Algorithm).

## Key Concepts
- Infix: a + b  c (operators between operands)
- Postfix: a b c  + (operators after operands)
- Stack: Used to manage operator precedence and parentheses

## Operator Precedence (Higher number = Higher priority)
cpp
int priority(char ch) {
    if (ch == '^') return 3;        // Exponentiation (highest)
    else if (ch == '' || ch == '/') return 2;  // Multiplication/Division
    else if (ch == '+' || ch == '-') return 1;  // Addition/Subtraction
    else return 0;                  // Parentheses or invalid
}


## Algorithm Steps

### 1. Process Each Character
cpp
while (i < s.length()) {
    // Check character type and handle accordingly
}


### 2. Handle Operands (Letters/Numbers)
cpp
if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
    ans = ans + s[i];  // Directly add to result
}

Rule: Operands go directly to output

### 3. Handle Opening Parenthesis '('
cpp
else if (s[i] == '(') {
    st.push(s[i]);     // Always push to stack
}

Rule: Opening parenthesis always goes to stack

### 4. Handle Closing Parenthesis ')'
cpp
else if (s[i] == ')') {
    while (!st.empty() && st.top() != '(') {
        ans += st.top();   // Pop all operators until '('
        st.pop();
    }
    st.pop();             // Remove the '('
}

Rule: Pop all operators until matching '(' is found

### 5. Handle Operators (+, -, , /, ^)
cpp
else {
    while (!st.empty() && priority(s[i]) < priority(st.top())) {
        ans += st.top();   // Pop higher/equal precedence operators
        st.pop();
    }
    st.push(s[i]);        // Push current operator
}

Rule: Pop operators with higher/equal precedence, then push current

### 6. Final Cleanup
cpp
while (!st.empty()) {
    ans += st.top();      // Pop remaining operators
    st.pop();
}


## Example Walkthrough: a+b(c^d-e)

| Step | Character | Stack | Output | Action |
|------|-----------|-------|--------|---------|
| 1 | a | [] | a | Operand → output |
| 2 | + | [+] | a | Operator → stack |
| 3 | b | [+] | ab | Operand → output |
| 4 |  | [+,] | ab | Higher precedence → stack |
| 5 | ( | [+,,(] | ab | Opening bracket → stack |
| 6 | c | [+,,(] | abc | Operand → output |
| 7 | ^ | [+,,(,^] | abc | Operator → stack |
| 8 | d | [+,,(,^] | abcd | Operand → output |
| 9 | - | [+,,(,-] | abcd^ | Pop ^, push - |
| 10 | e | [+,,(,-] | abcd^ e | Operand → output |
| 11 | ) | [+,] | abcd^e- | Pop until ( |
| 12 | End | [] | abcd^e-+ | Pop remaining |

Final Result: abcd^e-+

## Time Complexity: O(n)
## Space Complexity: O(n)

## Key Points to Remember
1. Operands → Direct to output
2. Higher precedence → Pop from stack first
3. Parentheses → Control precedence temporarily
4. Left-to-right processing with stack for operators
5. Final cleanup → Pop all remaining operators
*/

int priority(char ch) {
    if (ch == '^')return 3;
    else if (ch == '*' || ch == '/')return 2;
    else if (ch == '+' || ch == '-')return 1;
    else return 0;
}

string Infix_to_Postfix(string s) {
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
            while (!st.empty() && priority(s[i]) < priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }


    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string infix = "a+b*(c^d-e)";
    string postfix = Infix_to_Postfix(infix);
    cout << postfix;
    return 0;
}