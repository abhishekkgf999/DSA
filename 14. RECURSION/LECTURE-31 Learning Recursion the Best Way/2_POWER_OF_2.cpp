#include<bits/stdc++.h>
using namespace std;

int power(int n){

    //BASE CASE
    if(n == 0) return 1;
    
    //RECURSIVE RELATION
    return 2*power(n-1);
}

int main(){
    
    int n;
    cout<<"Enter a number:- "<<endl;
    cin>>n;

    cout<<power(n)<<endl;
    return 0;
}