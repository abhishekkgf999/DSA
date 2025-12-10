#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(nlogn), SPACE COMPLEXITY:- O(N)
void merge(int arr[], int start, int end, int mid){
    int l1 = mid-start+1;
    int l2 = end-mid;

    int *arr1 = new int[l1];
    int *arr2 = new int[l2];

    int k = start;
    for(int i = 0; i<l1; i++){
        arr1[i] = arr[k++];
    }
    k = mid+1;
    for(int i = 0; i<l2; i++){
        arr2[i] = arr[k++];
    }

    int ind1 = 0, ind2 = 0;
    k = start;
    while(ind1 < l1 && ind2 < l2){
        if(arr1[ind1] <= arr2[ind2]){
            arr[k++] = arr1[ind1++];
        }
        else{
            arr[k++] = arr2[ind2++];
        }
    }

    while(ind1 < l1){
        arr[k++] = arr1[ind1++];
    }

    while(ind2 < l2){
        arr[k++] = arr2[ind2++];
    }

    delete []arr1;
    delete []arr2;
}

void Merge_Sort(int arr[], int start, int end){
    if(start>=end)return;

    int mid = start+(end-start)/2;

    Merge_Sort(arr, start, mid);
    Merge_Sort(arr, mid+1, end);
    merge(arr, start, end, mid);
}

int main(){
    int arr[] = {3, 5, 1, 2, 765, 89};
    int n = sizeof(arr)/sizeof(arr[0]);
    Merge_Sort(arr, 0, n-1);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}