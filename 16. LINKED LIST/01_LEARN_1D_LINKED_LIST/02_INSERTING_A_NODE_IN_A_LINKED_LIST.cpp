#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insert_at_head(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_end(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_at_middle(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr || head->next == nullptr) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* temp = slow->next;
    slow->next = newNode;
    newNode->next = temp;
}

void insert_at_given_position(Node*& head, int val, int pos) {
    if (pos < 0) return;

    if (pos == 0) {
        insert_at_head(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 0; i < pos - 1; i++) {
        if (temp == nullptr) return; // Out of bounds
        temp = temp->next;
    }

    if (temp == nullptr) return; // Out of bounds

    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_before_the_value_of_x(Node*& head, int val, int x) {
    if (!head) {
        cout << "Empty linked list\n";
        return;
    }

    Node* newNode = new Node(val);

    if (head->data == x) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != x) {
        curr = curr->next;
    }

    if (curr->next == nullptr) return; // x not found

    newNode->next = curr->next;
    curr->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    insert_at_head(head, 10);
    insert_at_end(head, 20);
    insert_at_end(head, 30);
    insert_at_middle(head, 15);
    insert_at_given_position(head, 25, 3);
    insert_before_the_value_of_x(head, 5, 10);

    display(head);

    return 0;
}
