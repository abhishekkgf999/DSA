#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY :- O(1)
void Selection_Sort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Selection_Sort(arr, n);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}