/*
pattern-17 TYPE:-

D
CD
BCD
ABCD

*/

// #METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    for(int i =1; i<=n; i++){
        for(int j= 1; j<=i; j++){
            char c = 'D' - i + j;
            cout<<c;
        }
        
        cout<<endl;
    }
    return 0;
}



//#METHOD-2
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    for(int i =1; i<=n; i++){
        char c = 'A' + n - i;
        for(int j= 1; j<=i; j++){
            cout<<c;
            c++;
        }
        
        cout<<endl;
    }
    return 0;
}
