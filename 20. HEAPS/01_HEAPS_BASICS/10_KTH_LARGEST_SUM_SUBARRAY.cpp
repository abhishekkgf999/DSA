/*
#KTH LARGEST SUM SUBARRAY

LINK:- https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0
*/

#include<bits/stdc++.h>
using namespace std;

//brute force (TC:- n^2.Log(n) SC:- O(N^2))
int getKthLargest(vector<int>& arr, int k)
{
    //	Write your code here.
    vector<int> sumStore;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
}

//OPTIMIZED (TC:- O(N^2.Log(k)) SC:- O(K))
int getKthLargest2(vector<int>& arr, int k)
{
    //	Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (pq.size() < k) pq.push(sum);
            else {
                if (pq.top() < sum) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}

int main() {
    vector<int> arr = {1, -2, 3, -4, 5};
    cout<<getKthLargest2(arr, 2);
    return 0;
}