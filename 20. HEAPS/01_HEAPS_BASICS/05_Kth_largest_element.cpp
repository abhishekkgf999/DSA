/*
#KTH LARGEST ELEMENT

LINK:- https://leetcode.com/problems/kth-largest-element-in-an-array/

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto i : nums) pq.push(i);

        for (int i = 1; i < k; i++)
            pq.pop();

        return pq.top();
    }
};

int main() {
    vector<int> arr = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    Solution obj;
    cout << obj.findKthLargest(arr, k);

    return 0;
}