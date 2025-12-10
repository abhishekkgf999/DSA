#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(N^2), SPACE COMPLEXITY:- O(N)
void Recursive_Selection_Sort(int arr[], int n){
    if(n<=1)return;

    int min_index = 0;
    for(int j = 1; j<n; j++){
        if(arr[j] < arr[min_index]){
            min_index = j;
        }
    }
    swap(arr[0], arr[min_index]);

    Recursive_Selection_Sort(arr+1, n-1);
}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Recursive_Selection_Sort(arr, n);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}