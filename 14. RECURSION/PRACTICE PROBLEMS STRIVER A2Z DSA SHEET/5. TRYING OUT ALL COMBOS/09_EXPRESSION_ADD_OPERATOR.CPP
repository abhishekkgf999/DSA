/*
#EXPRESSION ADD OPERATOR

LINK:- https://leetcode.com/problems/expression-add-operators/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_not_working {
public:
    unordered_map<string, int> memo;
    int order(char ch) {
        if (ch == '+' || ch == '-') return 1;
        return 2;
    }
    int evaluate(string temp) {      //this function will evalute the value of final expression with the help of stack, using concept of infix operation
        if (memo.count(temp)) return memo[temp];
        stack<char> op_stack;
        stack<int> operand;

        for (int i = 0; i < temp.size(); i++) {
            char ch = temp[i];
            if (isdigit(ch)) {
                long long num = 0;
                while (i < temp.size() && isdigit(temp[i])) {
                    num = num * 10 + (temp[i] - '0');
                    i++;
                }
                i--;
                operand.push(num);
            }
            else {
                while (!op_stack.empty() && order(op_stack.top()) >= order(ch)) {
                    long long op1 = operand.top(); operand.pop();
                    long long op2 = operand.top(); operand.pop();
                    char op = op_stack.top(); op_stack.pop();

                    if (op == '+') operand.push(op2 + op1);
                    else if (op == '-') operand.push(op2 - op1);
                    else if (op == '*') operand.push(op2 * op1);
                }
                op_stack.push(ch);
            }
        }

        while (!op_stack.empty()) {
            long long op1 = operand.top(); operand.pop();
            long long op2 = operand.top(); operand.pop();
            char op = op_stack.top(); op_stack.pop();
            if (op == '+') operand.push(op2 + op1);
            else if (op == '-') operand.push(op2 - op1);
            else if (op == '*') operand.push(op2 * op1);
        }

        return memo[temp] = operand.top();

    }
    void solve(string num, int target, int idx, vector<string>& ans, string temp) {
        if (idx == num.size()) {
            int res = evaluate(temp);
            if (res == target) {
                ans.push_back(temp);
            }
            return;
        }

        for (int len = 1; idx + len <= num.size(); len++) {
            string nextNum = num.substr(idx, len);
            if (nextNum.size() > 1 && nextNum[0] == '0') break;
            if (idx == 0) {
                solve(num, target, idx + len, ans, nextNum);
            }
            else {
                solve(num, target, idx + len, ans, temp + "+" + nextNum);
                solve(num, target, idx + len, ans, temp + "-" + nextNum);
                solve(num, target, idx + len, ans, temp + "*" + nextNum);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, ans, "");
        return ans;
    }
};

class Solution_correct_code {
public:
    void solve(string num, int target, int idx, long long current, long long prev, string expr, vector<string>& ans) {
        if (idx == num.size()) {
            if (current == target) {
                ans.push_back(expr);
            }
            return;
        }

        for (int len = 1; idx + len <= num.size(); len++) {
            string nextNum = num.substr(idx, len);
            if (nextNum.size() > 1 && nextNum[0] == '0') break;

            long long val = stoll(nextNum); //The stoll() function is a C++ library function that converts a string to a long long integer. It stands for "string to long long."

            if (idx == 0) {
                solve(num, target, idx + len, val, val, nextNum, ans);
            }
            else {
                // Addition: current + val
                solve(num, target, idx + len, current + val, val, expr + "+" + nextNum, ans);

                // Subtraction: current - val
                solve(num, target, idx + len, current - val, -val, expr + "-" + nextNum, ans);

                // Multiplication: current - prev + (prev * val)
                // We undo the previous operation and apply multiplication
                solve(num, target, idx + len, current - prev + prev * val, prev * val, expr + "*" + nextNum, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};

int main() {
    string num = "232";
    int target = 6;
    Solution_correct_code obj;
    vector<string> ans = obj.addOperators(num, target);
    for (const auto& i : ans) {
        cout << "\"" << i << "\" ";
    }
    return 0;
}