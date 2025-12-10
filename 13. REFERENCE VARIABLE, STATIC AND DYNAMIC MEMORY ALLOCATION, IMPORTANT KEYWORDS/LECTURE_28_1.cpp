//REFERENCE VARIABLE
#include<bits/stdc++.h>
using namespace std;

void update2(int &n){
    n++;
}

void update1(int n){
    n++;
}

int main(){

    /*
    
    int i = 5;

    //creating a ref variable

    int &j = i;

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;
    
    */
    int n = 5;
    cout<<"Before:- "<<n<<endl;
    update1(n);
    cout<<"After calling update1 function:- "<<n<<endl;
    update2(n);
    cout<<"After calling update2 function:- "<<n<<endl;
    return 0;
}