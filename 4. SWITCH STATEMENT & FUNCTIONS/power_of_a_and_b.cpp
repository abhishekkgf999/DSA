#include<iostream>
using namespace std;

void power(void){
    int a, b;
    cout<<"Enter the value of a & b"<<endl;
    cin>>a>>b;

    int ans = 1;
    for(int i = 1; i<=b; i++){
        ans = ans*a;
    }
    cout<<a<<" raise to the power "<<b<<" is "<<ans<<endl;
}

int main(){
    /*int a, b;
    cin>>a>>b;
    int ans = 1;
    for(int i=1; i<=b; i++){
        ans = ans*a;
    }
    cout<<ans;
    */
   cout<<"Now power function is calling"<<endl;
   power();
   power();
   power();
    return 0;
}