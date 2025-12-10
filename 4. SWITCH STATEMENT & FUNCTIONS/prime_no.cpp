#include<iostream>
using namespace std;
bool Prime(int n){
    for(int i=2; i<n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    if(Prime(n)){
        cout<<"The given number is prime number";
    }
    else{
        cout<<"The given number is not prime";
    }
    return 0;
}