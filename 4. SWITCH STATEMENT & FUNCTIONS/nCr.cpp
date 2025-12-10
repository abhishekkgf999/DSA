#include<iostream>
using namespace std;

int fact(int a){
    int ans = 1;
    for(int i =1; i<=a; i++){
        ans = ans*i;
    }
    return ans;
}

int nCr(int n, int r){
    int num = fact(n);
    int deno = fact(r) * fact(n-r);
    return num/deno;
}

int main(){
    int num1, num2;
    cout<<"Enter value of n and r to find its nCr "<<endl;
    cin>>num1>>num2;

    int ans = nCr(num1, num2);

    cout<<"value of nCr of given numbers is:- "<<ans<<endl;
    
    return 0;
}