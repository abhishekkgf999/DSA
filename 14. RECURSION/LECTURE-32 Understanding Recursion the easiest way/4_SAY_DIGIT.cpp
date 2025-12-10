#include <iostream>
#include <vector>
#include<string>

using namespace std;

void printwords(int n, vector<string> &m){

    //BASE CASE
    if(n <= 0){
        return;
    }

    //PROCESS (HEAED RECURSION)
    printwords(n/10, m);


    //PROCESS
    int ind = n%10;
    
    cout<<m[ind]<<" ";

}

int main(){

vector<string> m(10);
    m[0] = "zero";
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";

    int n;
    cout<<"Enter a number:- ";
    cin>>n;

    printwords(n, m);

    return 0;
}
