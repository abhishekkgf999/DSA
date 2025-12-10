/*
pattern-14 TYPE:-

A
BB
CCC
DDDD


*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    for(int i =1; i<=n; i++){
        char c = 'A' + i -1;
        for(int j= 1; j<=i; j++){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
