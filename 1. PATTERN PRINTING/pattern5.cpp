/*
pattern-5 TYPE:-

123     ==> row1 --> 3 columns
456     ==> row2 --> 3 columns
789     ==> row3 --> 3 columns

here, as element increase number is also increasing

in this pattern, we will simply print counting, by declaring a variable and increasing that

*/


#include<iostream>
using namespace std;

int main(){
    int n, count = 1;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n ; j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    
    return 0;
}