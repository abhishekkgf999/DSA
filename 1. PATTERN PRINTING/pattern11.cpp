/*
pattern-11 TYPE:-

ABC     every row is printing character in sequence wise
ABC
ABC

so we have to declare a character which will increase according to column

and column is depedent on given number ;

we will declare a char which is something like 'A' + column - 1
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
            char c = ('A' + j - 1);
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
