/*
#MERGE K SORTED ARRAYS

LINK:- https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0
*/

#include<bits/stdc++.h>
using namespace std;

/*
💡 PROBLEM SUMMARY:
- Given k sorted arrays
- Each array may have n elements
- Merge them into ONE sorted array

====================================================
APPROACH 1: BRUTE FORCE
----------------------------------------------------
1. Saare k arrays ke elements ko ek single array me daal do
2. Single array ko sort kar do

➡ Total elements = n * k
➡ Sorting complexity = (n*k) log(n*k)

❌ Drawback:
- Sorting ka extra cost
- Optimized nahi hai jab arrays already sorted ho

TIME COMPLEXITY:  O((n*k) log(n*k))
SPACE COMPLEXITY: O(n*k)

====================================================
APPROACH 2: MIN HEAP (OPTIMIZED APPROACH) ⭐
----------------------------------------------------
👉 Because saare arrays already SORTED hain

IDEA:
- Har array ka current smallest element heap me rakhenge
- Heap hamesha smallest element ko top pe rakhega

----------------------------------------------------
CUSTOM NODE STRUCTURE:
Each heap node stores:
1. data → actual value
2. row  → kis array se aaya
3. col  → us array ka index

----------------------------------------------------
STEPS:
1️⃣ Har array ka FIRST element heap me push karo
2️⃣ Heap ka top = current smallest element
3️⃣ Us element ko answer array me daalo
4️⃣ Us element ke array ka NEXT element heap me push karo
5️⃣ Repeat until heap empty ho jaye

----------------------------------------------------
WHY THIS WORKS?
- Heap size max = k
- Har step me smallest element milta hai
- Sorted order automatically maintain hota hai

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
Initial heap insertions:
- k elements → O(k log k)

Processing all elements:
- Total elements = n*k
- Each push/pop = log k

TIME COMPLEXITY:
➡ O(k log k + n*k log k)
➡ Simplified → O(n*k log k)

SPACE COMPLEXITY:
➡ Heap size = O(k)
➡ Answer array = O(n*k)

====================================================
*/

class Node{
    public:
        int data;
        int row;
        int col;
        Node(int val, int row, int col){
            data = val;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

//TIME COMPLEXITY:- O(klog(k))+ O(n*k.Log(k)) ~ O(n*k.Log(k))
//SPACE COMPLEXITY:- O(n*k)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;


    //TIME COMPLEXITY FOR BELOW LOOP IS O(klog(k)) => inserting k arrays element takes log(k) time
    for(int i = 0; i<k; i++){
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }    


    vector<int> ans;

    //TIME COMPELXITY:- O(n*k.Log(k)) => n*k total elements and log(k) for heapify insertion
    while(minHeap.size() > 0){
        Node* temp = minHeap.top();
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        ans.push_back(temp->data);

        if(col+1 < kArrays[row].size()){
            Node* next = new Node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }

    }

    return ans;
}

int main(){
    

    return 0;
}