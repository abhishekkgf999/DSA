//THIS IS FOR POSITIVE NUMBERS

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"enter the value of n "<<endl;
    cin>>n;
    // int i=0;
    float ans = 0;
    for(int i=0; n!=0; i++, n = n>>1){
        int bit = n&1;
        ans = (bit * pow(10, i)) + ans;
        // n = n>>1;
        // i++;
    }
    cout<<"decimal to binary is:- "<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}