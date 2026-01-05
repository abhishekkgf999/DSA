/*
#MERGE K SORTED LINKED LIST

LINK:- https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0
*/

/*
/*
💡 PROBLEM SUMMARY:
- Given k sorted linked lists
- Merge them into ONE sorted linked list
- Return the head of merged list

====================================================
APPROACH 1: BRUTE FORCE
----------------------------------------------------
1️⃣ Saari linked lists ke elements ek vector me daal do
2️⃣ Vector ko sort kar do
3️⃣ Ab sorted data se linked list rebuild kar lo

❌ Drawbacks:
- Sorting ka extra overhead
- Linked list ka sorted nature use nahi ho raha

TIME COMPLEXITY:
➡ O((n*k) log(n*k))

SPACE COMPLEXITY:
➡ O(n*k)

====================================================
APPROACH 2: MIN HEAP (OPTIMAL APPROACH) ⭐
----------------------------------------------------
👉 Kyunki saari linked lists already SORTED hain

IDEA:
- Har linked list ka current smallest node heap me rakhenge
- Heap hamesha smallest data wala node top pe rakhega

----------------------------------------------------
MIN HEAP SETUP:
- Heap me Node* store karenge
- Comparison based on node->data (min heap)

----------------------------------------------------
STEPS:
1️⃣ Sabhi linked lists ke HEAD nodes ko heap me push karo
2️⃣ Heap ka top = smallest element among all lists
3️⃣ Us node ko merged list me attach karo
4️⃣ Agar us node ka next exist karta hai:
      ➜ top->next ko heap me push karo
5️⃣ Repeat jab tak heap empty na ho jaye

----------------------------------------------------
MERGED LIST BUILDING:
- head → merged list ka start
- tail → merged list ka last node

✔ First node:
    - head = tail = top
✔ Remaining nodes:
    - tail->next = top
    - tail = top

----------------------------------------------------
WHY THIS WORKS?
- Heap size max = k
- Har step me smallest available node milta hai
- Linked list sorted order automatically maintain hota hai

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
Initial heap insertion:
➡ k heads → O(k log k)

Processing all nodes:
➡ Total nodes = n*k
➡ Each push/pop = log k

TIME COMPLEXITY:
➡ O(k log k + n*k log k)
➡ Simplified → O(n*k log k)

SPACE COMPLEXITY:
➡ Heap size = O(k)

====================================================
*/



#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

//TIME COMPLEXITY:- O(k.log(k)) + O(n*k.log(k))
//SPACE COMPLEXITY:- O(K) => total number of linked list
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(int i = 0; i<listArray.size(); i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }


    Node* head = nullptr;
    Node* tail = nullptr;

    while(minHeap.size()>0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(head == nullptr){
            head = top;
            tail = top;
        }else{
            tail->next = top;
            tail = top;
        }

        if(top->next != NULL){
            minHeap.push(top->next);
        }
    }

    return head;
}
