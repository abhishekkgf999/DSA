//Macros 

#include<bits/stdc++.h>
using namespace std;

#define PI 3.14
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(){

    int r = 5;

    //double pi = 3.14;

    double area = PI * r * r;

    cout<<"Area is:- "<<area<<endl;
        
    int a = 18;
    int b = 76;

    cout<<"Minimum value between "<<a<<" and "<<b<<" is "<<min(a,b)<<endl;

    
    return 0;
}