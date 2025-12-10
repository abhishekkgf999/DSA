//STATIC AND DYNAMIC MEMORY ALLOCATION

#include<bits/stdc++.h>
using namespace std;

int getSum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    
    int n;
    cout<<"Enter the size of array:- "<<endl;
    cin>>n;

    //DYNAMICALLY ALLOCATING MEMORY FOR N INTEGERS, AND RETURNING THE ADDRESS OF FIRST CONTIGUOUS MEMORY LOCATION
    int *arr = new int[n];

    cout<<"Enter the values of array:- "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int sum = getSum(arr, n);

    cout<<"Sum of the elements in array is:- "<<sum<<endl;

    delete []arr;
    cout<<"Memory released for array!"<<endl;
    return 0;
}