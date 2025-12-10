#include<bits/stdc++.h>
using namespace std;


/*
1. NODE:- ith index
2. LEFT CHILD :- 2*i
3. RIGHT CHILD :- 2*i + 1
4. PARENT :- (i/2)
*/
class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    //INSERTION
    //STEP 1: INSERT AT THE END
    //STEP 2: TAKE IT TO ITS CORRECT POSITION 
    //TIME COMPLEXITY :- O(log N)
    void insert(int val) {
        size++;
        int ind = size;
        arr[ind] = val;

        while (ind > 1) {
            int parent = ind / 2;
            if (arr[parent] < arr[ind]) {
                swap(arr[parent], arr[ind]);
                ind = parent;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }

    //DELETION (TC:- O(log N))
    /*
    Step	        Operation                              Purpose
     1	        Check if heap empty	                Prevent invalid delete
     2	        Move last element to root	        Replace deleted element
     3	        Decrease heap size	                Adjust valid heap area
     4	        Set i = 1	                        Start heapify from root
     5	        Find child indices	                Identify nodes to compare
     6	        Compare & swap	                    Maintain max-heap property
    */
    void deleteFromHeap() {     //delete root node
        if (size == 0) {
            cout << "No element present" << endl;
            return;
        }

        arr[1] = arr[size];
        int i = 1;
        size--;
        int leftIndex, rightIndex;
        while (i < size) {
            leftIndex = 2 * i;
            rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[leftIndex] > arr[i] && arr[leftIndex] > arr[rightIndex]) {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex <= size && arr[rightIndex] > arr[i] && arr[rightIndex] > arr[leftIndex]) {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else return;
        }
    }
};

/*
🧩 Heapify (Max Heap) — Quick Notes //TIME COMPLEXITY :- O(N)

Purpose:
Fixes the max-heap property for a subtree rooted at index i
(assuming left & right subtrees are already heaps).

Steps:

1. largest = i → assume parent is largest

2. left = 2*i, right = 2*i + 1 (for 1-based index)

3. If left < n and arr[left] > arr[largest] → largest = left

4. If right < n and arr[right] > arr[largest] → largest = right

5. If largest != i →

    swap(arr[i], arr[largest])

    heapify(arr, n, largest) (recursive fix)
*/
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
    // Get the last element
    int lastElement = arr[n];

    // Replace root with last element
    arr[1] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    heapify(arr, n, 1);
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();


    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout<<"printing the array now"<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}