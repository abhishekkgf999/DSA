/*

#STRING TO INTEGER (ATOI)   (REVIEW THIS QUESTION)

LINK:- https://leetcode.com/problems/string-to-integer-atoi/description/

*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION
int myAtoi(string s) {
        int n = s.size();
        bool isNegative = false;
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        if (i == n) return 0; // No valid number found

        if (s[i] == '-' || s[i] == '+') {
            isNegative = (s[i] == '-');
            i++;
        }
        int ans = 0;

        while(i < n && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';

            if (ans > (INT32_MAX / 10) || (ans == INT32_MAX / 10 && digit > 7)) {
                return isNegative ? INT32_MIN : INT32_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return isNegative ? -ans : ans;
      
    }

int main(){
    string s = " -042";
    cout<<myAtoi(s);
    return 0;
}