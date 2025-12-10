#include <bits/stdc++.h>
using namespace std;

// Function to maintain max-heap property
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
//TIME COMPLEXIYT :- O(nlogn)
void heapSort(vector<int> &arr, int n) {
    // STEP 0: Build a Max Heap (bottom-up)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // STEP 1–4: Extract elements from heap one by one
    int size = n;
    while (size > 1) {
        swap(arr[0], arr[size - 1]); // Step 1: Move current max to end
        size--;                      // Step 2: Reduce heap size
        heapify(arr, size, 0);       // Step 3: Restore heap property
    }
}

// Driver code
int main() {
    vector<int> arr = {50, 30, 40, 10, 5, 20, 30};

    heapSort(arr, arr.size());

    cout << "Sorted array: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
