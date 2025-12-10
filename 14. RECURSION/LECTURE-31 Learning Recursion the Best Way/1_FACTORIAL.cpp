// FACTORIAL

//TIME COMPLEXITY :- O(N)

#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    
    //BASE CASE
    if(n == 0) return 1;
    
    //RECURSIVE CALL
    return n * factorial(n-1);
}

int main(){
    int n;
    cout<<"Enter number:- "<<endl;
    cin>>n;

    int ans = factorial(n);

    cout<<ans<<endl;

    return 0;
}