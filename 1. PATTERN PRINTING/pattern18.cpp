/*
pattern-18 TYPE:-

        *
       ** 
      ***
     ****
    *****  
*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    for(int i=1; i<=n; i++){
    //space print karlo
    int space = n-i;
    while(space){
        cout<<" ";
        space--;
    }
    //stars print karlo
    for(int j= 1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}

