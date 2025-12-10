/*
#given char string is case sensitive 
'N' and 'n' both are different things in this question
*/

#include<bits/stdc++.h>
using namespace std;


bool checkPalindrome1(char name[], int len) {
    int s = 0, e = len - 1;
    while (s < e) {     
        if (name[s++] != name[e--]) {
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

    if(checkPalindrome1(name, len)){
        cout<<"Given string is palindrome"<<endl;
    }
    else cout<<"Given string is not palindrome"<<endl;

    return 0;
}