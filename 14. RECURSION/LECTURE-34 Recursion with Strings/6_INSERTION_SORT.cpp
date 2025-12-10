#include<iostream>
using namespace std;

// Recursive function to sort the array
void insertionSortRecursive(int arr[], int n) {
    // Base case: If the size is 1 or less, it's already sorted
    if (n <= 1) {
        return;
    }

    // Sort the first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert the last element at its correct position in the sorted part
    int last = arr[n - 1];
    int j = n - 2;

    // Move elements greater than 'last' one position ahead
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last; // Place the last element in its correct position
}


int main(){
    int arr[] = {2, 1, 4, 6, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSortRecursive(arr, n);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}