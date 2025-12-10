/*
pattern-3 TYPE:-

4321    ==> row1 --> 4 columns
4321    ==> row2 --> 4 columns
4321    ==> row3 --> 4 columns
4321    ==> row4 --> 4 columns


now in this case, the number is printing in reverse order of coumn number

we can conclude a formula to print that number in reverse order

for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<(n-j+1);  ===> here (n-j+1) will print number in revers order
        }
        cout<<endl;
    }

if n = 4
then,  case 1:- j = 1; n-j+1 = 4-1+1 = 4
then,  case 2:- j = 2; n-j+1 = 4-2+1 = 3
then,  case 3:- j = 3; n-j+1 = 4-3+1 = 2
then,  case 4:- j = 4; n-j+1 = 4-4+1 = 1

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
            cout<<(n-j+1);
        }
        cout<<endl;
    }
    return 0;
}