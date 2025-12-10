// https://leetcode.com/problems/fibonacci-number/description/


#include<iostream>
using namespace std;

int fib(int n) {
        //BASE CASE
        if(n == 0) return 0;
        if(n == 1) return 1;

        //RECURSIVE CALL
        return fib(n-2) + fib(n-1);
    }

int main(){
    
    int n;
    cout<<"Enter a number:- ";
    cin>>n;

    cout<<n<<"th Fibonacci number is:- "<<fib(n)<<endl;

    return 0;
}