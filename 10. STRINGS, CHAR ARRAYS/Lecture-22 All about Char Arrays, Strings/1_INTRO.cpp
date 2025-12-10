#include<bits/stdc++.h>
using namespace std;

int main(){

    char name[20];      //CHARACTER ARRAY

    string s = "Hello";     //DECLARATION OF STRING
    s.at(2) = '\0';
    cout<<s<<endl;

    cout<<"Enter your name "<<endl;
    cin>>name;
    name[2] = '\0';
    cout<<"Your name is:- "<<name;

    return 0;
}