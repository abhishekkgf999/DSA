/*
#FLATTEN A LINKED LIST

LINK:- https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/


#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*
 1. Recursive Strategy
Key Insight: Process from rightmost column first, then merge leftward

Node* list2 = flatten(root->next);  // Flatten right side first
root = merge(root, list2);          // Merge current column with flattened right


Why right-first? Ensures each merge combines current column with fully processed remaining structure.

 2. Merge Logic (Standard 2-List Merge)
Purpose: Combine two sorted vertical lists into one sorted list

Process:
- Compare heads: take smaller element
- Connect via bottom pointer (vertical connections)
- Clear next pointer: temp->next = nullptr
- Handle remaining elements

 3. Key Implementation Details

Dummy Node Pattern:

Node* dummy = new Node(-1);
Node* temp = dummy;

Logic: Simplifies merge - no special case for first element

Pointer Management:
- Use bottom for result connections (vertical chain)
- Set next = nullptr to avoid horizontal references
- Final cleanup: dummy->bottom->next = nullptr

 4. Base Case Logic

if(root == nullptr || root->next == nullptr) return root;

Logic: Single column or empty - already flattened

## Mental Model
Structure: Think of columns connected horizontally, sorted vertically within each column

Process:
1. Recurse to rightmost column
2. Merge current column with flattened right portion
3. Return merged result as single vertical chain
*/

class Solution {
public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->data <= list2->data) {
                temp->bottom = list1;
                temp = list1;
                list1 = list1->bottom;
            }
            else {
                temp->bottom = list2;
                temp = list2;
                list2 = list2->bottom;
            }
            temp->next = nullptr;
        }

        if (list1 != nullptr) temp->bottom = list1;
        else temp->bottom = list2;

        if (dummy->bottom != nullptr) dummy->bottom->next = nullptr;

        return dummy->bottom;
    }
    Node* flatten(Node* root) {
        // Your code here
        if (root == nullptr || root->next == nullptr) {
            return root;
        }

        Node* list2 = flatten(root->next);
        root = merge(root, list2);
        return root;
    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->bottom; // Traverse down the bottom pointers
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;

    // Create a multi-level linked list
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    cout << "Original multi-level list (first column): ";
    display(head);

    Node* flattened_list = sol.flatten(head);

    cout << "\nFlattened and sorted list: ";
    display(flattened_list);

    // Note: The memory management for a complex structure like this is tricky.
    // In a production environment, you would need a proper destructor or
    // cleanup function to deallocate all nodes to prevent memory leaks.

    return 0;
}