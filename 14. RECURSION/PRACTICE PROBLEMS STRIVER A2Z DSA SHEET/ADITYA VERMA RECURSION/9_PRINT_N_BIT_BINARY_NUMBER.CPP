/*
#PRINT N-BIT BINARY NUMBER

LINK:- https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, string temp, vector<string> &ans, int count1, int count0){
        if(n == 0){
            if(count1 >= count0) ans.push_back(temp);
            return;
        }
        
        if(count0 > count1)return;
        
        string s1 = temp + '1';
        solve(n-1, s1, ans, count1+1, count0);
        
        string s2 = temp + '0';
        solve(n-1, s2, ans, count1, count0+1);
    }

    vector<string> NBitBinary(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, temp, ans, 0, 0);
        return ans;
    }

int main(){
    vector<string> ans = NBitBinary(3);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}