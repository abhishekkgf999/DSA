/*
pattern-9 TYPE:-

1
21
321
4321


we can a print (i-j+1) ===> which will print the desired output 

as, for( i(row) = 1; i(row)<=n ; i++){  
        for(j(column)= 1; j<=i; j++){ ===> column is dependent on row
            cout<<(i-j+1);
        }
        cout<<endl;
}
for row-1 ::  i=1, j=1, i-j+1 = 1-1+1 = 1

for row-2 ::  i=2, j=1, i-j+1 = 2-1+1 = 2
              i=2, j=2, i-j+1 = 2-2+1 = 1

for row-3 ::  i=3, j=1, i-j+1 = 3-1+1 = 3
              i=3, j=2, i-j+1 = 3-2+1 = 2
              i=3, j=3, i-j+1 = 3-3+1 = 1

for row-4 ::  i=4, j=1, i-j+1 = 4-1+1 = 4
              i=4, j=2, i-j+1 = 4-2+1 = 3
              i=4, j=3, i-j+1 = 4-3+1 = 2
              i=4, j=4, i-j+1 = 4-4+1 = 1

*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n, count =1;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<endl;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i ; j++){
            cout<<(i-j+1);            
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
        int value = i;
        for(int j = 1; j<=i ; j++){
            
            cout<<value;
            value--;
        }
        cout<<endl;
    }
    
    return 0;
}