#include<iostream>
using namespace std;

int bitcounter(int n){
    int ans = 0;
    for(; n!=0; n = n>>1){
        if(n&1){
            ans++;
        }
    }
   return ans; 
}



int main(){
    int a, b;
    cout<<"Enter the value of a & b"<<endl;
    cin>>a>>b;
    cout<<"THE VALUE OF BITCOUNTER FOR "<<a<<" & "<<b<<" is "<<bitcounter(a)+bitcounter(b)<<endl;
    return 0;
}