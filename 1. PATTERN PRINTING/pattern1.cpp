/*
pattern-1 TYPE:-

***     ==> row1 --> 3 columns
***     ==> row2 --> 3 columns
***     ==> row3 --> 3 columns

Here, 3 rows are present & each row has 3 columns

*/


#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the a number"<<endl;
    cin>>n;
    cout<<"\n";
    for(int i=0; i<n; i++){     // ====> this for loop is running for rows
        for(int j=0; j<n; j++){     //====> this for loop is running for columns
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}