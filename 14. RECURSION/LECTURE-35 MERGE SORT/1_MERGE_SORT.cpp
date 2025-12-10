#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(N*logN), SPACE COMPLEXITY:- O(N)
void merge(vector<int> &arr, int start, int end, int mid){
    int l1 = mid-start+1;
    int l2 = end-mid;

    int *arr1 = new int[l1];
    int *arr2 = new int[l2];

    int k = start;
    
    //COPY THE ELEMENTS IN ARR1 FROM START->MID
    for(int i = 0; i<l1; i++){
        arr1[i] = arr[k++];
    }

    // KEEP TRACK IN ORIGINAL ARRAY
    k = mid+1;

    //COPY THE ELEMENTS IN ARR2 FROM MID+1->END
    for(int i = 0; i<l2; i++){
        arr2[i] = arr[k++];
    }

    int index1 = 0;
    int index2 = 0;
    k = start;
    while(index1 < l1 && index2 < l2){
        if(arr1[index1] < arr2[index2]){
            arr[start++] = arr1[index1++];
        }
        else{
            arr[start++] = arr2[index2++];
        }
    }

    while(index1 < l1){
        arr[start++] = arr1[index1++];
    }

    while(index2 < l2){
        arr[start++] = arr2[index2++];
    }

    delete []arr1;
    delete []arr2;
}

void mergeSort(vector<int> &arr, int start, int end){
    if(start >= end) return;

    int mid = start + (end-start)/2;

    //LEFT PART SORT KARNA HAI
    mergeSort(arr, start, mid);

    //RIGHT PART SORT KARNA HAI
    mergeSort(arr, mid+1, end);

    //MERGE
    merge(arr, start, end, mid);
}

int main(){
    vector<int> arr = {2, 1413, 1, 16, 90, 7};
    mergeSort(arr, 0, arr.size()-1);

    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}