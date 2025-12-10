/*
pattern-6 TYPE:-

1
23
345
4567

Here, 
1st row has 1
2nd row has 2 & 3
3rd row has 3,4 & 5
4th row has 4,5,6 & 7 

as we can see, the first number is equal to row number, and it increases upto column value.

we will declare a variable which will be equal to row number

and it will increase till its column number

*/


// #METHOD-1

#include<iostream>
using namespace std;

int main(){
    int n, count =1;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        int value = i;
        for(int j = 1; j<=i ; j++){
            
            cout<<value;
            value++;
        }
        cout<<endl;
    }
    
    return 0;
}


// #METHOD-2
#include<iostream>
using namespace std;

int main(){
    int n, count =1;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = i; j<(2*i) ; j++){
            
            cout<<j;
        }
        cout<<endl;
    }
    
    return 0;
}

// IN METHOD-2, WE ARE OBSERVING THE PATTERN, WHICH ALSO INDICATES THAT

// we set the condition while (j<2*i) in 2nd while loop cuz in above pattern 
// every row starts with the the row number(value of i) N ends before the twice of its row value..


// #METHOD-3 ===> we can also use cout<<i+j-1<<" ";
#include<iostream>
using namespace std;

int main(){
    int n, count =1;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i ; j++){
            
            cout<<(i+j-1);
        }
        cout<<endl;
    }
    
    return 0;
}