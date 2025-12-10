/*
#MAXIMUM OCCURING CHARACTER

LINK:-  https://www.youtube.com/watch?v=Wdjr6uoZ0e0&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=24
*/

#include<bits/stdc++.h>
using namespace std;

char countchar(string s){

    int count[26] = {0};

    //created an array of count of character
    for(int i=0; i<s.size(); i++){
        char ch = s[i];
        int number = 0;
        //lowercase
        if(ch>='a' && ch<='z'){
             number = ch-'a';
        }
        //uppercase
        else{
            number = ch-'A';
        }
        count[number]++;
    }

    int max = -1, ans = 0;
    for(int i=0; i<26; i++){
        if(max<count[i]){
            ans = i;
            max = count[i];
        }
    }
    return ans+'a';
}

int main(){
    string s;
    cout<<"enter your string"<<endl;
    getline(cin, s);
    cout<<countchar(s)<<endl;
    return 0;
}