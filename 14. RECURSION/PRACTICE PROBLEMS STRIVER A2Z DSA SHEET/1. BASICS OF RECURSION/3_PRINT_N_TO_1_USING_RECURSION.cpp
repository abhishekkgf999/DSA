/*
#PRINT N TO 1 USING RECURSION

*/

#include<bits/stdc++.h>
using namespace std;

//TAIL RECURSION
void print(int n){
    //BASE CASE
    if(n<=0) return;

    //PROCESS
    cout<<n<<endl;

    //RECURSIVE CALL
    print(n-1);
}

int main(){
    print(5);
    return 0;
}