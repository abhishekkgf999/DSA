/*
pattern-6 TYPE:-

*
**
***
****

Here, star is printing according to row number, as we can see
1st row has 1 star
2nd row has 2 stars
3rd row has 3 stars
4th row has 4 stars

it means that star count is depend on row number,

also column number is also equal to row number, 
so we should run column for loop according to row number

 for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i ; j++){ 
            cout<<"*";
        }
        cout<<endl;
    }

as you can see that
if i(row) = 1, then j(column)<= 1               ===> it means that it will run only once
if i(row) = 2, then j(column)<= 2               ===> it means that it will run twice
if i(row) = 3, then j(column)<= 3               ===> it means that it will run thrice
if i(row) = 4, then j(column)<= 4               ===> it means that it will run 4 times
*/


#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}