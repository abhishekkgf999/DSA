/*
#LETTER COMBINATION OF A PHONE NUMBER

LINK :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string digits, int index, string output, string mapping[], vector<string> &ans){
        if(index >= digits.size()){
            if(output != "") ans.push_back(output);
            return;
        }

        int i = digits[index] - '0';

        for(auto ch : mapping[i]){
            output = output+ch;
            solve(digits, index+1, output, mapping, ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        solve(digits, index, output, mapping, ans);
        return ans;
    }

int main(){
    string str = "23";
    vector<string> ans = letterCombinations(str);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}