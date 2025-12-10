/*
#REMOVE DUPLICATES FROM SORTED DLL

LINK:- https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
*/

#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }

};


class Solution {
public:
    Node* removeDuplicates(struct Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* to_delete = current->next;
                current->next = to_delete->next;

                // If the list is not at the end
                if (to_delete->next != nullptr) {
                    to_delete->next->prev = current;
                }

                delete to_delete;
            }
            else {
                current = current->next;
            }
        }
        return head;
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

    // Create a sample doubly linked list with duplicates
    // Expected output after removal: 1 2 3 4 5
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 5);

    cout << "Original Doubly Linked List: ";
    printList(head); // Output: 1 2 2 3 3 4 5 5

    // Call the function to remove duplicates
    Node* new_head = sol.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(new_head); // Output: 1 2 3 4 5

    return 0;
}