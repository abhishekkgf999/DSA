
/*
pattern-23 TYPE:-
    *
    * *
    * * *
    * * * *
    * * * * *
    * * * *
    * * *
    * *
    * 
*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i = 0; i<(2*n); i++ ){
        int totalColsInRow  = i>n ? 2*n-i : i;
        for(int j=0; j<totalColsInRow; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}




//#METHOD-2
// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the number of n ";
//     cin>>n;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//          cout<<"*";   
//         }
//         cout<<endl;
//     }
//     for(int i=1; i<=(n-1); i++){
//         for(int j=1; j<=(n-i); j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }