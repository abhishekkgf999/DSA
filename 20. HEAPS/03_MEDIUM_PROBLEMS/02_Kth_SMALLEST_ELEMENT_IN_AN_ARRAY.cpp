/*
#Kth smallest element

link:- https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

#include<bits/stdc++.h>
using namespace std;

/*
[Expected Approach] Using Max-Heap - O(n * log(k)) Time and O(k) Spac

The idea is to maintain a max heap of size k while iterating through the array. 
The heap always contains the k smallest elements seen so far. If the heap size exceeds k, 
remove the largest element. At the end, the heap holds the k smallest elements.
 */

int kthSmallest(vector<int>& arr, int k) {
    
    // Create a max heap 
    priority_queue<int> pq;

    // Iterate through the array elements
    for (int i = 0; i < arr.size(); i++)
    {
        // Push the current element onto the max heap
        pq.push(arr[i]);

        // If the size of the max heap exceeds k,
        //remove the largest element
        if (pq.size() > k)
            pq.pop();
    }

    return pq.top();
}

int main()
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    cout << kthSmallest(arr, k);
}

