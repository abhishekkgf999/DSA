/*
#RECURSIVE IMPLEMENTATION OF ATOI FUNCTION

LINK:- https://leetcode.com/problems/string-to-integer-atoi/description/
*/

#include<bits/stdc++.h>
using namespace std;

int get_number(string s, int index, int ans, bool isNegative){
    //BASE CONDITION - 1
    if(index >= s.length())return ans;

    //BASE CONDITION - 2
    if(s[index]<'0' || s[index] > '9'){
        return ans;
    }

    int digit = s[index]-'0';

    //BASE CONDTITION - 3
    if (ans > (INT32_MAX / 10) || (ans == INT32_MAX / 10 && digit > 7)) {
        return isNegative ? INT32_MIN : INT32_MAX;
    }

    ans = ans*10 + digit;
    return get_number(s, index+1, ans, isNegative);
}

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

        ans = get_number(s, i, ans, isNegative);

        // while(i < n && s[i] >= '0' && s[i] <= '9'){
        //     int digit = s[i] - '0';

        //     if (ans > (INT32_MAX / 10) || (ans == INT32_MAX / 10 && digit > 7)) {
        //         return isNegative ? INT32_MIN : INT32_MAX;
        //     }

        //     ans = ans * 10 + digit;
        //     i++;
        // }

        return isNegative ? -ans : ans;
    }

int main(){
    // string s = "  -042";
    string s = "-2147483647";
    cout<<myAtoi(s);
    return 0;
}