/*
#COPY LINKED LIST WITH RANDOM POINTER

LINK:- https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/

#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//TIME COMPLEXITY :- O(N);
//SPACE COMPLEXITY :- O(N);
/*
## Problem Logic
Create a deep copy of linked list where each node has next and random pointers.

## Core Challenge
Random pointers can point to ANY node → Need mapping between original and copied nodes.

## Two-Pass Algorithm Logic

### Pass 1: Create Nodes + Build Mapping
cpp
unordered_map<Node*, Node*> mpp;  // original → copy mapping


Logic:
- Create new nodes with same values
- Build next connections for copied list
- Crucially: Store original → copy mapping in hashmap

Why mapping needed? Random pointers reference nodes we may not have created yet.

### Pass 2: Set Random Pointers
cpp
Node* temp = curr->random;        // Get original's random target
Node* temp2 = mpp[temp];          // Find corresponding copy
prev->random = temp2;             // Set copy's random pointer


Logic:
- For each original node's random pointer
- Look up the corresponding copied node in hashmap
- Set copied node's random pointer to that target

## Key Points
- HashMap essential: Maps original nodes to their copies
- Two passes required: Structure first, then random pointers
- Null safety: Check random pointer exists before mapping

*/
class Solution_using_hashmap {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = nullptr;
        Node* prev = nullptr;
        Node* curr = head;
        unordered_map<Node*, Node*> mpp;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            if (prev == nullptr) {
                prev = newNode;
                if (newHead == nullptr) newHead = newNode;
            }
            else {
                prev->next = newNode;
                prev = newNode;
            }
            mpp[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        prev = newHead;
        while (curr != nullptr) {
            Node* temp = curr->random;
            if (temp != NULL) {
                Node* temp2 = mpp[temp];
                prev->random = temp2;
            }
            curr = curr->next;
            prev = prev->next;
        }


        return newHead;
    }
};

/*
# Copy Random List (Optimized) - Logic & Revision

## Problem Logic
Create deep copy of linked list with random pointers without using extra space (no hashmap).

## Three-Pass Algorithm Logic

### Pass 1: Interweave Original and Copy

A → B → C
becomes
A → A' → B → B' → C → C'


Logic: Insert each copied node right after its original
- curr->next = newNode
- newNode->next = originalNext

Key Insight: Copy of node X is always at X->next

### Pass 2: Set Random Pointers

curr->next->random = curr->random->next;


Logic: If original points to node Y, copy should point to Y's copy
- curr->random → original target node Y
- curr->random->next → Y's copy (Y')
- Set copy's random to Y'

Why this works? Interweaved structure guarantees copy is always original->next

### Pass 3: Separate Lists

curr->next = curr->next->next;  // Skip copy node
temp->next = temp->next->next;  // Skip original node


Logic: Restore original structure and extract copied list
- Original: A → B → C (skip A', B', C')
- Copy: A' → B' → C' (skip A, B, C)

## Key Implementation Logic

Random Pointer Edge Case:

if(curr->random == nullptr)
    curr->next->random = nullptr;


Separation Safety:

curr->next = (curr->next == NULL) ? NULL : curr->next->next;

Logic: Handle case where we're at last node

## Mental Model
Problem: Need mapping without extra space
Solution: Create temporary interweaved structure

Phases:
1. Interweave: A→A'→B→B'→C→C'
2. Connect randoms: Use pattern original->random->next
3. Separate: Extract two independent lists


Time: O(n) | Space: O(1)
*/
class Solution_using_original_linked_list {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        Node* curr = head;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            Node* temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
            curr = temp;
        }

        curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->random == nullptr) {
                curr->next->random = nullptr;
            }
            else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* newHead = head->next;
        Node* temp = newHead;
        while (curr != nullptr && temp != nullptr) {
            curr->next = (curr->next == NULL) ? NULL : curr->next->next;
            temp->next = (temp->next == NULL) ? NULL : temp->next->next;

            curr = curr->next;
            temp = temp->next;
        }

        return newHead;
    }
};

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "List traversal (val, random_val):" << endl;
    while (temp != nullptr) {
        cout << "(" << temp->val << ", ";
        if (temp->random != nullptr) {
            cout << temp->random->val;
        }
        else {
            cout << "NULL";
        }
        cout << ") -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution_using_hashmap hash_solver;
    Solution_using_original_linked_list optimized_solver;

    // Test Case 1: Example list with random pointers
    // List: 1 -> 2 -> 3
    // 1.random -> 3
    // 2.random -> 1
    // 3.random -> 3
    Node* head1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    head1->next = node2;
    node2->next = node3;
    head1->random = node3;
    node2->random = head1;
    node3->random = node3;

    cout << "Original List:" << endl;
    display(head1);

    // Test with HashMap Solution
    Node* copied_list_hash = hash_solver.copyRandomList(head1);
    cout << "\nCopied List (HashMap Solution):" << endl;
    display(copied_list_hash);

    // Test with Optimized Solution (need a fresh list)
    Node* head2 = new Node(1);
    Node* node2_2 = new Node(2);
    Node* node3_2 = new Node(3);
    head2->next = node2_2;
    node2_2->next = node3_2;
    head2->random = node3_2;
    node2_2->random = head2;
    node3_2->random = node3_2;

    Node* copied_list_optimized = optimized_solver.copyRandomList(head2);
    cout << "\nCopied List (Optimized Solution):" << endl;
    display(copied_list_optimized);

    // Note: Proper memory deallocation for these linked lists is complex
    // due to the random pointers and cycles. For a simple main function,
    // we focus on demonstrating correctness.

    return 0;
}