/*

#LARGEST ODD NUMBER IN STRING 

LINK:- https://leetcode.com/problems/largest-odd-number-in-string/description/

*/

#include<bits/stdc++.h>
using namespace std;


string largestOddNumber(string num) {
        string ans = "";
        
        int head = 0, end = num.size()-1;

        for(int i = end; i>=0; i--){
            int n = num[i]-'0';

            if(n%2 == 1){
                ans += num.substr(head, i-head+1);
                break;
            }
        }

        return ans;
    }


int main(){
    string num = "52";
    string ans = largestOddNumber(num);
    cout<<ans;
    return 0;
}