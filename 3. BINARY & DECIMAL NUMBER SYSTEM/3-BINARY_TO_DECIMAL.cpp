#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long n;
    cout<<"enter the value in binary format "<<endl;
    cin>>n;
    long long ans = 0;    
    for(int i =0; n!=0; i++, n /=10){
        int bit = n%10;
        if(bit == 1){
            ans = (bit * pow(2, i)) + ans;
        }
    }
    cout<<ans;
    return 0;
}