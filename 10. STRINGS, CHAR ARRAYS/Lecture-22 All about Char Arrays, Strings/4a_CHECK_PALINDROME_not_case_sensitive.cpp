/*
#CHECK IF THE STRING IS A PALINDROME

#given char string is not case sensitive 
'N' and 'n' both are same things in this question

LINK:- https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633
*/

#include<bits/stdc++.h>
using namespace std;

char toLowercase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome1(char name[], int len) {
    int s = 0, e = len - 1;
    while (s<=e) {     
        if (toLowercase(name[s++]) != toLowercase(name[e--])) {
            return false; 
        }
    }
    return true;  
}

int getLength(char name[]){
    int count = 0;
    for(int i=0; name[i]!='\0'; i++){
        count++;
    }
    return count;
}

int main(){

    char name[20];

    cout<<"Enter your name "<<endl;
    cin>>name;
    cout<<"Your name is:- "<<name<<endl;

    int len = getLength(name);

    cout<<len<<endl;

    cout<<"Is Palindrome:- "<<checkPalindrome1(name, len)<<endl;

    cout<<"to lowercase:- "<<toLowercase('B')<<endl;

    return 0;
}