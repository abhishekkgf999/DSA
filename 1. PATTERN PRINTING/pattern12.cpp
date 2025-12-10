/*
pattern-12 TYPE:-

ABC
DEF
GHI


*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    char c = 'A';
    cin>>n;
    for(int i =1; i<=n; i++){
        for(int j= 1; j<=n; j++){
            cout<<c;
            c++;
        }
        cout<<endl;
    }
    return 0;
}
