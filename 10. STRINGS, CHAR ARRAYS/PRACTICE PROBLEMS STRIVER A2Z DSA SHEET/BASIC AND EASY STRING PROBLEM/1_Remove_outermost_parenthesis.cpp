/*

#REMOVE THE OUTERMOST PARENTHESIS

LINK:- https://leetcode.com/problems/remove-outermost-parentheses/

*/


#include<bits/stdc++.h>
using namespace std;

/*

Remove the outermost parentheses while retaining valid inner parentheses.  


  1. Use a variable opened to track how many open parentheses are currently active.  
  2. Traverse the string character by character:  
     - If '(':  
       - Check if opened > 0 (indicates this is not the outermost opening).  
       - If true, append '(' to the result.  
       - Increment opened to account for the newly opened parenthesis.  
     - If ')':  
       - Check if opened > 1 (indicates this is not the outermost closing).  
       - If true, append ')' to the result.  
       - Decrement opened as one parenthesis has been closed.  

- Important Points: 
  - The first and last parentheses of the string are the outermost ones, so they are excluded from the result.  
  - Inner parentheses are included based on the value of `opened`.  

- Example Walkthrough:  
  Input: "(()())"  
  - Process '(': opened = 1 → Skip (outermost).  
  - Process '(': opened = 2 → Add '(' to result.  
  - Process ')': opened = 1 → Add ')' to result.  
  - Process '(': opened = 2 → Add '(' to result.  
  - Process ')': opened = 1 → Add ')' to result.  
  - Process ')': opened = 0 → Skip (outermost).  
  Result: "()()".  

*/
string removeOuterParentheses(string s) {
        string ans;

        int opened = 0;

        for(auto ch : s){
            if(ch == '(' && opened++ > 0) ans += ch;
            if(ch == ')' && opened-- > 1) ans += ch;
        }

        return ans;
    }

int main(){
    string s1 = "(()())(())";
    string s2 = "(()())(())(()(()))";
    string s3 = "((()()))(())";
    string ans = removeOuterParentheses(s1);
    cout<<ans;
    return 0;
}