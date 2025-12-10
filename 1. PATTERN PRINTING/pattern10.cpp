/*
pattern-10 TYPE:-

AAA     every row is printing same character sequence wise
BBB
CCC

so we have to declare a character which will increase according to row
A is in 1st enitre row
B is in 2nd enitre row, similarly c is in 3rd row

and column is depedent on given number ;

we will declare a char which is something like 'A' + row - 1
*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    for(int i =1; i<=n; i++){
        char c = ('A' + i - 1);
        for(int j= 1; j<=n; j++){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}




//METHOD-2
#include<iostream>
using namespace std;

int main(){
    int n;
    char a = 65;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n ; j++){
           cout<<a<<" ";
        }
        a++;
        cout<<endl;
    }
    
    return 0;
}