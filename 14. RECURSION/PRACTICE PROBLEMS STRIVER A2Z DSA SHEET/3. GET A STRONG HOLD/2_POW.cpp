/*
#POW(X, N)

LINK:- https://leetcode.com/problems/powx-n/description/

*/


#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    // Base case: x^0 = 1
    if(n == 0) return 1;

    // Recursively calculate x^(n/2)
    double half = myPow(x, n / 2);

    if(n % 2 == 0) {
        // If n is even: x^n = (x^(n/2))^2
        return half * half;
    } else {
        if(n > 0) {
            // If n is odd and positive: x^n = (x^(n/2))^2 * x
            return half * half * x;
        } else {
            // If n is odd and negative: x^n = (x^(n/2))^2 / x
            /*
            myPow(2, -3)
                => half = myPow(2, -1)
                => half = myPow(2, 0) = 1

                return half * half / x = 1 * 1 / 2 = 0.5 (eventually gives 1/8)
            */
            return half * half / x;
        }
    }
}


int main(){
    cout<<myPow(2,-2)<<endl;
    cout<<myPow(2, 2)<<endl;
    cout<<myPow(3, 3)<<endl;
    cout<<myPow(3, -3)<<endl;
    return 0;
}