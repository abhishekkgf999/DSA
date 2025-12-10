/*
#FACTORIAL OF A GIVEN NUMBER

LINK:- https://www.naukri.com/code360/problems/factorial_975273
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(N), SPACE COMPLEXITY :- O(N) -> due to stack
long long getfactorial(int n){
    //BASE CASE
    if(n <= 1)return 1;

    //RECURSIVE CALL
    return n*getfactorial(n-1);
}

void factorial(int n)
{
    long long fact = getfactorial(n);
    cout<<fact;
}


int main(){
    factorial(5);
    return 0;
}