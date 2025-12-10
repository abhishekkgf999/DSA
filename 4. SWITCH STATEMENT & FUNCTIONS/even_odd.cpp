#include<iostream>
using namespace std;

bool isEven(int n){
    if(n&1){
        return 0;
    }
    return 1;
}

int main(){
    int a;
    cout<<"enter a number"<<endl;
    cin>>a;
    if(isEven(a)){
        cout<<"Your number is even "<<endl;
    }
    else{
        cout<<"Your number is odd "<<endl;
    }
    return 0;
}