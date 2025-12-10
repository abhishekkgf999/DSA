#include<bits/stdc++.h>
using namespace std;

bool isvalid(char ch){
    if((ch>= 'a' && ch<= 'z') || (ch >= 'A' && ch<= 'Z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}

char convertToLower(char ch){
    if(ch>='A' && ch<='Z'){
        return ch-'A'+'a';
    }
    return ch;
}

bool check(string temp, int start, int end){
    if(start >= end)return true;

    if(temp[start] != temp[end])return false;

    return check(temp, start+1, end-1);
}
    
bool isPalindrome(string s) {
    string temp = "";
    int i = 0; 
    while(i < s.length()){
        if(isvalid(s[i])){
            temp.push_back(convertToLower(s[i]));
        }
        i++;
    }
    int start = 0, end = temp.size()-1;
    return check(temp, start, end);
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}