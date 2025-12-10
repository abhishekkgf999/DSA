#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(N^2)
//SPACE COMPLEXITY:- O(N) -> due to stack calls
void Recursive_Bubble_sort(int arr[], int n){
    if(n <= 1)return;

    for(int i = 0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    Recursive_Bubble_sort(arr, n-1);

}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Recursive_Bubble_sort(arr, n);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}