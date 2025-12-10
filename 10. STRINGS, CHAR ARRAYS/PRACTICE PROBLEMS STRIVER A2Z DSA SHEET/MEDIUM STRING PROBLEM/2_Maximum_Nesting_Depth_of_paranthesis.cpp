/*

#MAXIMUM NESTING DEPTH OF THE PARENTHESES

LINK:- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

*/


#include<bits/stdc++.h>
using namespace std;


int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for(char ch : s){
            if(ch == '('){
                ans = max(ans, ++count);
            }
            else if(ch == ')'){
                count--;
            }
        }

        return ans;
    }

int main(){
    string s = "(1)+((2))+(((3)))";
    cout<<maxDepth;
    return 0;
}