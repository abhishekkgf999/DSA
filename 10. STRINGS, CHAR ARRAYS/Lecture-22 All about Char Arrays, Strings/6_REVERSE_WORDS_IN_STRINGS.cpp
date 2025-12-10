/*
#REVERSE WORDS IN STRINGS

LINK:- https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION
string reverseWords1(string s) {
        int p1 = 0, p2=0;
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' ' ) {
                temp.push_back(s[i]);
            }
            else {
            p2 = i-1;
            reverse(temp.begin()+p1, temp.begin()+p2+1);
            p1 = i;
            while (p1 < s.size() && s[p1] == ' ') {
                temp.push_back(' ');
                p1++;
            }
            
        }
    }
    if (!temp.empty()) {
        reverse(temp.begin() + p1, temp.end());
    }
        return temp;
}

//OPTIMISED SOLUTION
string reverseWords2(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {   // when i is a non-space
                int j = i;
                for (; j < s.length() && s[j] != ' '; j++) { } // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        
        return s;
    }

int main(){
    
    string s;
    cout<<"Enter your string:- "<<endl;
    getline(cin, s);

    string temp = reverseWords2(s);
    cout<<temp;


    return 0;
}