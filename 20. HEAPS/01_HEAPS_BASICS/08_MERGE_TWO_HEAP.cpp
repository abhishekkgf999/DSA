/*
#MERGE TWO HEAPS

LINK:- https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
*/


#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }

        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        // your code here
        for (auto i : b) {
            a.push_back(i);
        }
        n = a.size();
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(a, n, i);
        }

        return a;
    }
};

int main() {
    Solution obj;
    vector<int> a = { 10, 5, 6, 2 };
    vector<int> b = { 12, 7, 9 };
    vector<int> ans = obj.mergeHeaps(a, b, a.size(), b.size());
    for (auto i : ans)cout << i << " ";
    return 0;
}