/*
#REVERSE A DOUBLY LINKED LIST

LINK:- https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        if (head == NULL || head->next == NULL)return head;
        // code here
        Node* back = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = back;
            curr->prev = temp;
            back = curr;
            curr = temp;
        }

        return back;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.reverse(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
