/*
#SUM OF FIRST N NUMBERS

LINK:- https://www.naukri.com/code360/problems/sum-of-first-n-numbers_8876068
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(N), SPACE COMPLEXITY :- O(N) -> due to stack
void getSum(long long &ans, long long n){
    //BASE CASE
    if(n<=0)return;

    //PROCESS OF ADDING 
    ans += n;

    //RECURSIVE CALL
    getSum(ans, n-1);
}

long long sumFirstN(long long n) {
    long long ans = 0;
    getSum(ans, n);
    return ans;
}

int main(){
    cout<<sumFirstN(10);
    return 0;
}