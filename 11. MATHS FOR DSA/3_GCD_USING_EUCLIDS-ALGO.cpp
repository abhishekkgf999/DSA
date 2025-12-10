/*
#GCD (GREATEST COMMON DIVISOR) USING EUCLIDS ALGORITHM

==>There are two ways to find gcd using euclids algo
==>The first one is:- gcd(a-b, b)  && The seconds one is:- gcd(a%b, b)




==> gcd(a%b, b)
1. Given two integers a and b, where a is greater than or equal to b.
2. Divide a by b and compute the remainder (r).
3. If r is equal to zero, then b is the GCD of the original a and b.
4. If r is not zero, set a to b and b to r, and repeat from step 2.


*/

#include<bits/stdc++.h>
using namespace std;

//gcd using euclids algorithm:- gcd(a-b, b)
int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;

    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

//efficient method to find gcd using euclids algorithm:- gcd(a%b, b)
/*
In each iteration of the while loop, a is replaced by b, and b is replaced by the remainder 
of a divided by b (denoted as a % b). This process is repeated until b becomes zero. At that 
point, the last non-zero value of a is the GCD of the original a and b.
*/
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(){
    int a, b;
    cout<<"Enter two numbers:- "<<endl;
    cin>>a>>b;

    int ans = gcd(a, b);
    cout<<"Greatest common divisor of "<<a<<" & "<<b<<" is:- "<<ans<<endl;
    return 0;
}