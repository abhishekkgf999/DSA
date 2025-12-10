
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    bool isPrime = 1;

    for(int i=2; i<n; i++){
        if(n%i == 0){
            isPrime = 0;
            break;
        }
    }
    if(isPrime == 0){
        cout<<"NOT A PRIME NUMBER"<<endl;
    }
    else{
        cout<<"IS A PRIME NUMBER"<<endl;
    }
    return 0;
}









//MY SOLUTION
// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the value of n"<<endl;
//     cin>>n;
//     bool prime;
//     if(n==2){
//        prime = 1;
//     }
//     for(int i=2; i<n; i++){
//         if(n%i ==0){
//             prime = 0;
//             break;
//         }    
//         else{
//             prime =1;
//         }
//     }

//     prime == true ? cout<<"prime number" : cout<<"not prime number";

//     return 0;
// }