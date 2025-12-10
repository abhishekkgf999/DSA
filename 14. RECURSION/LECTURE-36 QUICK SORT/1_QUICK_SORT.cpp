#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[start];

    int count = 0;
    for(int i = start+1; i<=end; i++){
        if(arr[i] <= pivot) count++;
    }

    int pivotIndex = start + count;  //place pivot at right position

    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    //left and right wala part smbhal lete h 
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}


//OPTIMIZED PARTITION LOGIC
int partition2(vector<int> &arr, int start, int end) {
    int pivot = arr[start];
    int i = start + 1; // Pointer for elements <= pivot
    int j = end;       // Pointer for elements > pivot

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in its correct position
    swap(arr[start], arr[j]);
    return j;
}


void quickSort(vector<int> &arr, int start, int end){
    if(start >= end) return;

    // PARTITION KARENGE
    int pivot = partition(arr, start, end);

    //LEFT PART SORT KARO
    quickSort(arr, start, pivot-1);

    //RIGHT PART SORT KARO
    quickSort(arr, pivot+1, end);

}
int main(){
    vector<int> arr = {2,4,1,6,9,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}