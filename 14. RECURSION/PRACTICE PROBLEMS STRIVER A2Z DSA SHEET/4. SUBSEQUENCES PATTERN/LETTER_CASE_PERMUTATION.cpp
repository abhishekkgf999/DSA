/*
#LETTER CASE PERMUTATION

LINK :- https://leetcode.com/problems/letter-case-permutation/
*/

#include<bits/stdc++.h>
using namespace std;

char UPPER(char ch){
        if(ch >= 'A' && ch <= 'Z') return ch;
        return 'A'+ (ch-'a');
    }
    char LOWER(char ch){
        if(ch>='a' && ch <= 'z')return ch;
        return 'a'+ (ch-'A');
    }
    void solve(string s, string temp, vector<string> &ans, int index){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }

        char ch = s[index];

        if((ch >= '0' && ch <= '9')){
            //IF NUMBERS CAME, JUST INSERT IT
            temp.push_back(ch);
            solve(s, temp, ans, index+1);
        }
        else{
            //CHANGING ITS CASE TO LOWER
            string s1 = temp + LOWER(ch);
            solve(s, s1, ans, index+1);

            //CHANGING ITS CASE TO UPPER
            string s2 =  temp + UPPER(ch);
            solve(s, s2, ans, index+1);   
        }

    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp = "";
        solve(s, temp, ans, 0);
        return ans;
    }

int main(){
    string s = "a1B2";
    vector<string> ans = letterCasePermutation(s);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}