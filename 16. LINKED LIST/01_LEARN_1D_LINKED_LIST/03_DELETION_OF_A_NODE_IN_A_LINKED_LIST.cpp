#include<bits/stdc++.h>
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

void Delete_at_head(Node*& head) {
    if (head->next == nullptr) {
        head = nullptr;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void Delete_at_tail(Node*& head) {
    if (!head) {
        cout << "Empty linked list";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = nullptr;
    delete toDelete;
}

void delete_Kth_Element(Node*& head, int k) {
    if (k < 0) {
        cout << "INVALID POSITION";
        return;
    }

    if (k == 0) {
        if (head == nullptr) {
            return;
        }

        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < k - 1; i++) {
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Out of bound";
            return;
        }
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Out of bound";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}


void delete_the_element_with_value(Node*& head, int val) {
    if (head == nullptr) {
        cout << "Empty linked list";
        return;
    }

    if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found in linked list";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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

    insert_at_end(head, 10);
    insert_at_end(head, 20);
    insert_at_end(head, 30);
    insert_at_end(head, 40);

    cout << "Before deletion: ";
    display(head);

    delete_the_element_with_value(head, 20);

    cout << "After deleting 20: ";
    display(head);

    delete_the_element_with_value(head, 50); // not found

    return 0;
}
