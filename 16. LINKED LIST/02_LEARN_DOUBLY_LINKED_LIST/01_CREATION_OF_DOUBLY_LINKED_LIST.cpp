/*
#CREATING A DOUBLY LINKED LIST
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* ptr = head;
    head = head->next;
    head->prev = nullptr;
    ptr->next = nullptr;

    delete ptr;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    Node* back = temp->prev;
    temp->prev = nullptr;
    back->next = nullptr;

    delete temp;
    return head;
}

Node* removeKthElement(Node* head, int k) {

    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    for (int count = 1; count < k && temp != nullptr; count++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return head;
    }

    if (temp->prev == nullptr) {
        Node* newHead = head->next;
        if (newHead != nullptr) {
            newHead->prev = nullptr;
        }
        delete temp;
        return newHead;
    }
    else if (temp->next == nullptr) {
        Node* newTail = temp->prev;
        newTail->next = nullptr;
        delete temp;
        return head;
    }
    else {
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete temp;
        return head;
    }
}

Node* insertHead(Node* head, int val) {
    // Create the new node.
    Node* newNode = new Node(val);

    // If the list is empty, the new node is the only node.
    if (head == nullptr) {
        return newNode;
    }

    // Link the new node to the old head.
    newNode->next = head;
    head->prev = newNode;

    // The new node becomes the new head.
    return newNode;
}

Node* insertTail(Node* head, int val) {
    // Create the new node.
    Node* newNode = new Node(val);

    // If the list is empty, the new node is the head.
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the last node.
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the new node to the last node.
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node* insertAtKth(Node* head, int k, int val) {
    // If k is 1, insert at the head.
    if (k == 1) {
        return insertHead(head, val);
    }

    // Traverse to the position before where the new node should go.
    Node* temp = head;
    int count = 1;
    while (count < k - 1) {
        temp = temp->next;
        count++;
    }

    // Create the new node.
    Node* newNode = new Node(val);

    // Link the new node into the list.
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}

Node* insertBeforeNode(Node* head, Node* existingNode, int val) {

    // If the existing node is the head, handle that case.
    if (existingNode == head) {
        return insertHead(head, val);
    }
    // Create the new node.
    Node* newNode = new Node(val);

    // Link the new node into the list.
    Node* prevNode = existingNode->prev;

    prevNode->next = newNode;
    newNode->prev = prevNode;

    newNode->next = existingNode;
    existingNode->prev = newNode;

    return head;
}


int main() {
    vector<int> arr = { 1,3,2,4 };

    Node* head = new Node(arr[0]);
    Node* ptr = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, ptr);
        ptr->next = temp;
        ptr = temp;
    }

    display(head);
    return 0;
}