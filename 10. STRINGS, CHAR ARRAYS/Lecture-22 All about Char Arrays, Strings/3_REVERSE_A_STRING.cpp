#include<bits/stdc++.h>
using namespace std;

void Reverse(char name[], int len) {
    int s = 0, e = len - 1;
    while (s < e) {
        swap(name[s++], name[e--]);
    }
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
    cout<<"Length "<<len<<endl;

    Reverse(name, len);
    cout<<"After reversing :-"<<name<<endl;

    return 0;
}