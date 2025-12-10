#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- BEST CASE - O(N), WORST CASE - O(N^2)
//SPACE COMPLEXITY:- O(1)
void Bubble_sort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        bool swapped = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Bubble_sort(arr, n);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}