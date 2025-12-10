#include<bits/stdc++.h>
using namespace std;

//TAIL RECURSION
void counting(int n){

    //BASE CASE
    if(n == 0) return;

    //PROCESS
    cout<<n<<endl;

    //RECURSIVE CALL
    counting(n-1);
}

int main(){
    int n;
    cout<<"Enter a number:- ";
    cin>>n;

    counting(n);

    return 0;
}