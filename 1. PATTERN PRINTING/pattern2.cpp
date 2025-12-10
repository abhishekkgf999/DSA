/*
pattern-2 TYPE:-

111     ==> row1 --> 3 columns
222     ==> row2 --> 3 columns
333     ==> row3 --> 3 columns

Here, 3 rows are present & each row has 3 columns

*/


#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<n ; j++){
            cout<<i;
        }
        cout<<endl;
    }
    
    return 0;
}