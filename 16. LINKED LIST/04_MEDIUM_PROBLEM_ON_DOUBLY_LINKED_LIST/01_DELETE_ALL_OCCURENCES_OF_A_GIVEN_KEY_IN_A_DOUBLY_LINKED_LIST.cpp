/*
#DELETE ALL OCCURENCES OF A GIEN KEY IN A DOUBLY LINKED LIST

LINK:- https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x) { data = x; next = prev = NULL; }
};

/*
#void someFunction(struct Node* head): If you pass a single pointer head, the function gets a
copy of the pointer. Inside the function, you can modify the list (e.g., delete nodes),
but you cannot change where the original head pointer points. If you delete the first node
of the list, the original head pointer in the calling function will still be pointing to the
old, now invalid, memory location.

#void deleteAllOccurOfX(struct Node** head_ref, int x): By passing a pointer to the head pointer
(head_ref), the function receives the memory address of the original head pointer. This allows
the function to dereference it (*head_ref) and change the value of the original head pointer in
the calling function. This is crucial for correctly updating the list's entry point when the first
node (or multiple nodes at the beginning) needs to be deleted.
*/

class Solution {
public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // Write your code here
        if (*head == nullptr)return;

        Node* current = *head;
        while (current != nullptr) {
            if (current->data == x) {
                if (current == *head) {
                    *head = current->next;
                    if (*head != nullptr) {
                        (*head)->prev = nullptr;
                    }
                    delete current;
                    current = *head;
                }
                else {
                    Node* nextNode = current->next;
                    Node* prevNode = current->prev;

                    if (prevNode != nullptr) {
                        prevNode->next = nextNode;
                    }
                    if (nextNode != nullptr) {
                        nextNode->prev = prevNode;
                    }

                    delete current;
                    current = nextNode;
                }
            }
            else {
                current = current->next;
            }
        }
    }
};


// Utility function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}


int main() {
    // Create nodes manually
    Node* head = new Node(2);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(10);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(8);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original DLL: ";
    printList(head);

    int key = 2;
    Solution obj;
    obj.deleteAllOccurOfX(&head, key);

    cout << "DLL after deleting all occurrences of " << key << ": ";
    printList(head);

    return 0;
}