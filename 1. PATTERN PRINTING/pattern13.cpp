/*
pattern-13 TYPE:-

ABC
BCD
CDE

*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    for(int i =1; i<=n; i++){
        for(int j= 1; j<=n; j++){
        char c = 'A' + i + j - 2;
            cout<<c<<" ";
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
        char c = 'A' + i - 1;
        for(int j= 1; j<=n; j++){
            cout<<c;
            c++;
        }
        
        cout<<endl;
    }
    return 0;
}