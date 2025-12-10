/*
#GENERATE ALL BINARY STRINGS

LINK:- https://www.geeksforgeeks.org/problems/generate-all-binary-strings/0
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<string>& ans, string temp) {
    //BASE CASE:- WHEN OUR N BECOMES 0 (WE SUCCESSFULLY GENERATED N BINARY STRING)
    if (n == 0) {
        ans.push_back(temp);
        return;
    }

    //we have no restriction on consecutive 0's
    string s2 = temp + '0';
    solve(n - 1, ans, s2);

    //we have restriction on consecutive 1's, 
    // that's why we are checking if the last character is not 1, 
    // then only we insert 1 in our string, and proceed for that
    if (temp.empty() || temp.back() != '1') {
        string s1 = temp + '1';
        solve(n - 1, ans, s1);
    }
}
vector<string> generateBinaryStrings(int num) {
    vector<string> ans;
    string temp = "";
    solve(num, ans, temp);
    return ans;
}

int main(){
    vector<string> ans = generateBinaryStrings(3);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}