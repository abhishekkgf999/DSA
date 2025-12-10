/*
#PRINT 1 TO N USING RECURSION
*/

#include<bits/stdc++.h>
using namespace std;

//HEAD RECURSION
void print(int n){
    //BASE CASE
    if(n<=0) return;

    //RECURSIVE CALL
    print(n-1);

    //PROCESS
    cout<<n<<endl;
}

int main(){
    print(5);
    return 0;
}