/*
#PERMUTATION WITH SPACES

LINK:- https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1

*/

#include<bits/stdc++.h>
using namespace std;

void solve(string s, string temp, vector<string> &ans, int index) {
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        
        // First branch: Add space before the character
        string temp1 = temp + ' ' + s[index];
        solve(s, temp1, ans, index + 1);
        
        // Second branch: Add character without space
        string temp2 = temp + s[index];
        solve(s, temp2, ans, index + 1);

    }


    vector<string> permutation(string s) {
        vector<string> ans;
        string temp = string(1, s[0]);
  
        solve(s, temp, ans, 1);
        
        return ans;
        
    }

int main(){
    string s = "ABC";
    vector<string> ans = permutation(s);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}