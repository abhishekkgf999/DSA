#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;
    if (right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main(){
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3};
    int n = arr.size();
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(auto i: arr)cout<<i<<" ";
    return 0;
}