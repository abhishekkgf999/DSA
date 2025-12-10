#include<bits/stdc++.h>
using namespace std;

void Recursive_Insertion_Sort(int arr[], int n){
    //BASE CONDITION
    if(n<=1)return;

    // Sort the first n-1 elements
    Recursive_Insertion_Sort(arr, n-1);

    int key = arr[n-1];
    int j = n-2;

    while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = key;

}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Recursive_Insertion_Sort(arr, n);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}