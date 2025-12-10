#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- BEST CASE - O(N), WORST CASE - O(N^2)
//SPACE COMPLEXITY:- O(1)
void Insertion_Sort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insertion_Sort(arr, n);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}