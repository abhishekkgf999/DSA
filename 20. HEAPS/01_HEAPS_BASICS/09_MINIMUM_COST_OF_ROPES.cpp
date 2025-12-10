/*
#MINIMUM COST OF ROPES

LINK:- https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/

#include<bits/stdc++.h>
using namespace std;

/*
[Expected Approach] Greedy with Heap - O(n*log(n)) Time and O(n) Space

Always connect the two smallest ropes first to minimize total cost, similar to Huffman coding.
The idea is to use a min-heap (priority queue) and push all elements into it. While the heap contains 
more than one element, repeatedly extract the two smallest values, add them, and insert the sum back into the heap. 
Continue until one rope remains, then return the total cost.
*/
class Solution {
public:
    int minCost(vector<int>& arr) {

        // Create a min priority queue
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

        // Initialize result
        int res = 0;

        // While size of priority queue is more than 1
        while (pq.size() > 1) {

            // Extract shortest two ropes from pq
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            // Connect the ropes: update result and
            // insert the new rope to pq
            res += first + second;
            pq.push(first + second);
        }

        return res;
    }
};

int main() {
    vector<int> arr = { 4,3,2,6 };
    Solution obj;
    cout << obj.minCost(arr);
    return 0;
}