/*
pattern-3 TYPE:-

1234    ==> row1 --> 4 columns
1234    ==> row2 --> 4 columns
1234    ==> row3 --> 4 columns
1234    ==> row4 --> 4 columns


each row is printing number sequnce wise according equal 
to number of columns

*/



#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}