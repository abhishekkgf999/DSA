#include<bits/stdc++.h>
using namespace std;

// HEAD RECURSION
void print(int n){
    
    //BASE CASE
    if(n == 0) return;

    //RECURSIVE CALL
    print(n-1);

    //PROCESS
    cout<<n<<endl;
}


int main(){
    int n;
    cout<<"Enter a number:- ";
    cin>>n;

    print(n);

    return 0;
}