/*
Valid Palindrome

LINK:- https://leetcode.com/problems/valid-palindrome/description/
*/

#include<bits/stdc++.h>
using namespace std;

bool valid(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return 1;
    }
    else return 0;
}

char tolowercase(char ch){
    if(ch>='a' && ch<='z') return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(string s) {
        string temp = "";
        //faaltu character hatado
        for(int i=0; i<s.size(); i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }
        //lowercase mai convert kardo
        for(int i=0; i<temp.size(); i++){
            temp[i] = tolowercase(temp[i]);
        }
        int st = 0, e = temp.size() - 1;
        while (st<=e) {     
        if (temp[st++]!=temp[e--]) {
            return false; 
            }
        }
        return true; 
    }

int main(){
    string s;
    cout<<"Enter your string:- "<<endl;
    getline(cin, s);

    cout<<"Given string is palindrome or not:- "<<isPalindrome(s)<<endl;
    return 0;
}