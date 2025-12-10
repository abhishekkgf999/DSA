/*
==> PIVOT MEANING :- the central point on which something turns or balances.

In this code, we will find pivot element index.

Ex:- Given Arr = [8,9,1,2,3]
                      ^
                      |
                      |
                   pivot element
    
    Output :- 2
*/

#include<iostream>
using namespace std;

int getPivot(int arr[], int n){
    int left = 0, right = n-1;
    int mid = left + (right-left)/2;
    while(left<right){
        if(arr[mid]>=arr[0]){
            left = mid+1;
        }
        else{
            right  = mid;
        }
        mid = left + (right-left)/2;
    }
    return right;
}

int main(){
    int arr[] = {8,9, 1, 2, 3};
    cout<<"Pivot index is:- "<<getPivot(arr, 5)<<endl;
    return 0;
}
