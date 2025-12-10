#include<iostream>
using namespace std;

int main(){
    int a=0, b=1;
    int sum= 0;
    int n;
    cin>>n;
    cout<<a<<" "<<b<<" ";
    for(int i=1; i<n; i++){
        sum = a+b;
        cout<<sum<<" ";    
        a=b;
        b=sum;
        }
    return 0;
}