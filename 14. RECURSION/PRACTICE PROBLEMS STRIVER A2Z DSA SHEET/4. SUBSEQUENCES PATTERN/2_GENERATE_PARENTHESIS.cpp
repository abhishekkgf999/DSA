/*
#GENERATE PARENTHESIS

LINK:- https://leetcode.com/problems/generate-parentheses/description/


*/


#include<bits/stdc++.h>
using namespace std;

void solve(int n, string temp, int count, vector<string> &ans){
        // BASE CONDITION - 1
        // If all '(' have been used (n == 0), we add remaining ')' to balance
        // and push the completed combination to the result vector.
        if(n == 0){
            while(count){
                temp += ')';
                count--;
            }
            ans.push_back(temp);
            return;
        }

        // BASE CONDITION - 2
        // If count becomes negative, it means more ')' have been used than '(',
        // which is invalid. Simply return without doing anything.
        if(count<0){
            return;
        }

        // OPENING PARENTHESIS
        // Add '(' to the temp string and make a recursive call with updated parameters:
        // - Reduce 'n' as one '(' is added.
        // - Increment 'count' to track unmatched '('.
        temp += '(';
        solve(n-1, temp, count+1, ans);
        temp.pop_back();    // Backtrack by removing the last added '(' to restore the original state.

        // CLOSING PARENTHESIS
        // Add ')' to the temp string and make a recursive call with updated parameters:
        // - 'n' remains the same as we haven't added '('.
        // - Decrement 'count' to match an unmatched '('.
        temp += ')';
        solve(n, temp, count-1, ans);
        temp.pop_back();   // Backtrack by removing the last added ')' to restore the original state.
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, temp, 0, ans);
        return ans;
    }

int main(){
    int n = 3;  
    vector<string> result = generateParenthesis(n);
    for(const string &s : result){
        cout << s << endl;  
    }
    return 0;
}