/*
#CHECK IF ARRAY REPRESENTS A MIN-HEAP OR NOT
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isMinHeap(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || n == 1) {
        return true; // Empty or single-element array is always a min-heap
    }

    // Iterate through all non-leaf nodes
    // The last non-leaf node is at index (n/2) - 1
    for (int i = 0; i <= (n / 2) - 1; ++i) {
        int parent = arr[i];
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        // Check left child
        if (leftChildIndex < n && parent > arr[leftChildIndex]) {
            return false;
        }

        // Check right child
        if (rightChildIndex < n && parent > arr[rightChildIndex]) {
            return false;
        }
    }

    return true; // If all checks pass
}

int main() {
    // Example 1: A valid min-heap
    vector<int> heap1 = {10, 20, 30, 40, 50, 60};
    if (isMinHeap(heap1)) {
        cout << "heap1 is a min-heap." << endl;
    } else {
        cout << "heap1 is not a min-heap." << endl;
    }

    // Example 2: Not a min-heap (25 > 20)
    vector<int> heap2 = {10, 25, 30, 40, 20, 60};
    if (isMinHeap(heap2)) {
        cout << "heap2 is a min-heap." << endl;
    } else {
        cout << "heap2 is not a min-heap." << endl;
    }

    return 0;
}
