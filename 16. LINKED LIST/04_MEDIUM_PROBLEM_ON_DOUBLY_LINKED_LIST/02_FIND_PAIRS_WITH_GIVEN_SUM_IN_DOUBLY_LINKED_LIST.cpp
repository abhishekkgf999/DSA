/*
#FIND PAIRS WITH GIVEN SUM IN A DOUBLY LINKED LIST
LINK:- https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next, * prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
        // code here
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        Node* front = head;
        vector<pair<int, int>> ans;

        while (front != tail && front->prev != tail) {
            int sum = front->data + tail->data;
            if (sum == target) {
                pair<int, int> p(front->data, tail->data);
                ans.push_back(p);
                front = front->next;
                tail = tail->prev;
            }
            else if (sum > target) {
                tail = tail->prev;
            }
            else {
                front = front->next;
            }
        }

        return ans;
    }
};

// Helper function to insert a node at the end of the list
void insertEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

// Helper function to print the list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    Node* head = nullptr;

    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    insertEnd(&head, 8);

    cout << "Original Doubly Linked List: ";
    printList(head);

    int target_sum = 7;
    vector<pair<int, int>> pairs = sol.findPairsWithGivenSum(head, target_sum);

    cout << "Pairs with sum " << target_sum << ": ";
    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for (const auto& p : pairs) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}