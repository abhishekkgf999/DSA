//POINTERS FOR FUNCTIONS

#include<bits/stdc++.h>
using namespace std;

void print(int  *p){
    cout<<p<<endl;
}

void update(int *p){
    //=> Any changes made to p inside update() (like p = p + 1) only modify the local copy and do not affect the original pointer in main.
    //=> When update(p) is called, the pointer p from main is "passed by value" to the function.
    //=> This means that p inside update() is a separate variable that holds the same address as p from main, but modifying it does not change the original pointer's value.
    // p = p+1;
    // cout<<"inside "<<p<<endl;
    *p = *p + 1;
}

int getSum(int *arr, int n ){
    cout<<endl<<"Size: "<<sizeof(arr)<<endl;

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    
    int value = 5;
    int *p = &value;

    // print(p);

    cout<<"Before "<<*p<<endl;
    update(p);
    cout<<"After "<<*p<<endl;

    int arr[6] = {1,2,3,4,5,8};
    cout<<"Sum is:- "<<getSum(arr+3, 3)<<endl;
    return 0;
}