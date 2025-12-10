#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY:- BEST CASE - O(nlogn), WORST CASE - O(N^2)
//SPACE COMPLEXITY:- O(1)
int getPivot(int arr[], int start, int end){
    int pivot = arr[start];

    int i = start+1, j = end;

    while(i <= j){
        while(i <= j && arr[i] <= pivot){
            i++;
        }
        while(i <= j && arr[j] > pivot){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    } 

    swap(arr[start], arr[j]);
    return j;
}

void Quick_Sort(int arr[], int start, int end){
    if(start>= end) return;

    int partition = getPivot(arr, start, end);

    Quick_Sort(arr, start, partition-1);
    Quick_Sort(arr, partition+1, end);
}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Quick_Sort(arr, 0, n-1);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}